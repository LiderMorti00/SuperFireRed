#!/usr/bin/env python3
"""Super Fire Red: writes the Hoenn Gym Leader rematch teams (TRAINER_<LEADER>_2.._5)
from tools/sfr/data/hoenn_rematch.txt into src/data/trainers.party.
Usage (repo root): python3 tools/sfr/gen_hoenn_rematch.py
"""
import os, re
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

MEGA_RE = re.compile(r'ite$|ite X$|ite Y$')


def parse():
    teams, cur = {}, None
    for line in open('tools/sfr/data/hoenn_rematch.txt'):
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        if line.startswith('== '):
            cur = line[3:]; teams[cur] = []; continue
        mon, lvl, ab, moves = [x.strip() for x in line.split('|')]
        teams[cur].append((mon, int(lvl), ab, [m.strip() for m in moves.split('/')]))
    return teams


def fmt(mon, lvl, ab, moves):
    out = f'{mon}\nLevel: {lvl}\n'
    if ab != '-':
        out += f'Ability: {ab}\n'
    out += 'IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe\n'
    out += ''.join(f'- {m}\n' for m in moves)
    return out.rstrip('\n')


def tier(team, n):
    if n == 2:
        res = []
        for mon, lvl, ab, mv in team[1:]:
            if ' @ ' in mon and MEGA_RE.search(mon.split(' @ ')[1]):
                mon = mon.split(' @ ')[0] + ' @ Life Orb'
            res.append(fmt(mon, lvl, ab, mv))
        return res
    add = {3: 3, 4: 6, 5: 10}[n]
    return [fmt(mon, lvl + add, ab, mv) for mon, lvl, ab, mv in team]


def replace_team(text, tid, mons):
    m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
    header = m.group(1).split('\n\n')[0]
    header = re.sub(r'^AI: .*$', 'AI: Smart Trainer', header, flags=re.M)
    header = re.sub(r'^Items: .*$', 'Items: Full Restore / Full Restore / Full Restore / Full Restore', header, flags=re.M)
    return text[:m.start(1)] + header + '\n\n' + '\n\n'.join(mons) + '\n\n' + text[m.end(1):]


def main():
    teams = parse()
    em = open('src/data/trainers.party').read()
    for leader, team in teams.items():
        for n in (2, 3, 4, 5):
            em = replace_team(em, f'TRAINER_{leader}_{n}', tier(team, n))
    open('src/data/trainers.party', 'w').write(em)


if __name__ == '__main__':
    main()
