#!/usr/bin/env python3
"""Super Fire Red: writes the Kanto rematch teams of tools/sfr/data/kanto_rematch.txt.

Gym Leader rematches are new trainers (TRAINER_SFR_*_REMATCH, in the free Emerald slots
855-861 of src/data/trainers.party); the Elite Four and Blue reuse their FRLG rematch
trainers in src/data/trainers_frlg.party.
Usage (repo root): python3 tools/sfr/gen_kanto_rematch.py
"""
import os, re
ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

LEADERS = {  # new trainer -> (name, class pic)
    'TRAINER_SFR_BROCK_REMATCH': ('BROCK', 'Leader Brock Frlg'),
    'TRAINER_SFR_MISTY_REMATCH': ('MISTY', 'Leader Misty Frlg'),
    'TRAINER_SFR_LT_SURGE_REMATCH': ('LT. SURGE', 'Leader Lt Surge Frlg'),
    'TRAINER_SFR_ERIKA_REMATCH': ('ERIKA', 'Leader Erika Frlg'),
    'TRAINER_SFR_KOGA_REMATCH': ('KOGA', 'Leader Koga Frlg'),
    'TRAINER_SFR_SABRINA_REMATCH': ('SABRINA', 'Leader Sabrina Frlg'),
    'TRAINER_SFR_BLAINE_REMATCH': ('BLAINE', 'Leader Blaine Frlg'),
}
GENDER = {'MISTY': 'Female', 'ERIKA': 'Female', 'SABRINA': 'Female'}


def parse():
    teams, cur = {}, None
    for line in open('tools/sfr/data/kanto_rematch.txt'):
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        if line.startswith('== '):
            cur = line[3:]; teams[cur] = []; continue
        mon, lvl, ab, moves = [x.strip() for x in line.split('|')]
        out = f'{mon}\nLevel: {lvl}\n'
        if ab != '-':
            out += f'Ability: {ab}\n'
        out += 'IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe\n'
        out += ''.join(f'- {m.strip()}\n' for m in moves.split('/'))
        teams[cur].append(out.rstrip('\n'))
    return teams


def replace_team(text, tid, mons):
    m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
    header = m.group(1).split('\n\n')[0]
    header = re.sub(r'^AI: .*$', 'AI: Smart Trainer', header, flags=re.M)
    return text[:m.start(1)] + header + '\n\n' + '\n\n'.join(mons) + '\n\n' + text[m.end(1):]


def main():
    teams = parse()
    em = open('src/data/trainers.party').read()
    fr = open('src/data/trainers_frlg.party').read()
    for tid, mons in teams.items():
        if tid in LEADERS:
            name, pic = LEADERS[tid]
            if f'=== {tid} ===' not in em:
                em = em.rstrip('\n') + f'\n\n=== {tid} ===\nName: {name}\nClass: Leader Frlg\nPic: {pic}\n' \
                     f'Gender: {GENDER.get(name, "Male")}\nMusic: Serious\nItems: Full Restore / Full Restore / Full Restore\n' \
                     f'Double Battle: No\nAI: Smart Trainer\n\nX\nLevel: 1\n'
            em = replace_team(em, tid, mons)
        else:
            fr = replace_team(fr, tid, mons)
    open('src/data/trainers.party', 'w').write(em)
    open('src/data/trainers_frlg.party', 'w').write(fr)


if __name__ == '__main__':
    main()
