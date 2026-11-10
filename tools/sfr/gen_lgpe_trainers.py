#!/usr/bin/env python3
"""Super Fire Red: gives Kanto trainers their Let's Go Pikachu/Eevee teams.

Data: tools/sfr/data/lgpe_trainers.json (Let's Go trainers per location, from
altissimo1.github.io/Main-Series/Kanto-Locations, which credits Bulbapedia).

Let's Go reuses most Fire Red trainer names, so a trainer is matched when exactly one
first-battle trainer in trainers_frlg.party has the same name and a similar level
(to avoid matching two different people). Not changed: Team Rocket grunts (no names),
trainers that only exist in one game, VS Seeker rematches and the rival (Blue keeps
his Fire Red teams). Gym Leaders and Elite Four come from kanto_leaders_lgpe.txt.

Usage (repo root): python3 tools/sfr/gen_lgpe_trainers.py
"""
import json, os, re, sys, collections

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
sys.path.insert(0, 'tools/sfr')
from set_party import set_parties

SKIP_PREFIXES = ('Team Rocket', 'Coach Trainer', 'Jessie', 'Erika', 'Misty', 'Blaine', 'Koga', 'Brock',
                 'Sabrina', 'Giovanni', 'Blue', 'Lt.', 'Green', 'Red', 'Mina')
SPECIES_NAMES = {"Farfetch'd": 'Farfetchd', 'Mr. Mime': 'Mr Mime', 'Nidoran♀': 'Nidoran F', 'Nidoran♂': 'Nidoran M'}
MAX_LEVEL_GAP = 12


def frlg_trainers(text):
    out = {}
    for m in re.finditer(r'^=== (TRAINER_\w+) ===\n(.*?)(?=^=== |\Z)', text, re.S | re.M):
        const, block = m.group(1), m.group(2)
        if re.search(r'_\d+$', const):
            continue   # VS Seeker rematch versions
        name = re.search(r'^Name: (.*)$', block, re.M)
        levels = [int(x) for x in re.findall(r'^Level: (\d+)', block, re.M)]
        double = re.search(r'^Double Battle: Yes', block, re.M) is not None
        if name and levels:
            out[const] = (name.group(1).strip().upper(), max(levels), double)
    return out


def species_ok(name):
    return '(' not in name   # skip Mega / Alolan specials (none of these trainers use them)


def main():
    path = 'src/data/trainers_frlg.party'
    frlg = frlg_trainers(open(path).read())
    by_name = collections.defaultdict(list)
    for const, (name, lvl, double) in frlg.items():
        by_name[name].append((const, lvl, double))
    data = json.load(open('tools/sfr/data/lgpe_trainers.json'))
    teams, skipped = {}, []
    for loc, rows in data.items():
        for r in rows:
            t = r['trainer']
            if t.startswith(SKIP_PREFIXES) or ' ' not in t or not r['party']:
                continue
            name = t.rsplit(' ', 1)[1].upper()
            cands = by_name.get(name, [])
            lg_level = max(l for _, l in r['party'])
            cands = [c for c in cands if abs(c[1] - lg_level) <= MAX_LEVEL_GAP]
            if len(cands) != 1 or not all(species_ok(s) for s, _ in r['party']) \
               or (cands[0][2] and len(r['party']) < 2):   # double battles need two Pokemon
                skipped.append(f'{loc}: {t}')
                continue
            teams[cands[0][0]] = [(SPECIES_NAMES.get(s, s), l) for s, l in r['party']]
    set_parties(path, teams)
    print(f'{len(teams)} Kanto trainers now use their Let\'s Go team; {len(skipped)} kept from Fire Red')
    open('tools/sfr/data/lgpe_trainers_not_matched.txt', 'w').write('\n'.join(skipped) + '\n')


if __name__ == '__main__':
    main()
