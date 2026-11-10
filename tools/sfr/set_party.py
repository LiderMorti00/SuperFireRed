#!/usr/bin/env python3
"""Super Fire Red: replaces the Pokemon of trainers in a .party file, keeping their header
(name, class, pic, music, AI...). Moves are left out so the game uses level-up moves.

Usage: python3 tools/sfr/set_party.py src/data/trainers_frlg.party teams.txt
teams.txt format, one trainer per line:
    TRAINER_LEADER_BROCK: Geodude 11, Onix 12
"""
import re, sys


def set_parties(party_path, teams):
    text = open(party_path).read()
    for trainer, mons in teams.items():
        m = re.search(rf'^=== {trainer} ===\n(.*?)(?=^=== |\Z)', text, re.S | re.M)
        if not m:
            raise SystemExit(f'{trainer} not found in {party_path}')
        block = m.group(1)
        header = block.split('\n\n')[0]
        body = '\n\n'.join(f'{species}\nLevel: {level}' for species, level in mons)
        text = text[:m.start(1)] + header + '\n\n' + body + '\n\n' + text[m.end(1):]
    open(party_path, 'w').write(text)


def parse(lines):
    teams = {}
    for line in lines:
        line = line.split('#')[0].strip()
        if not line:
            continue
        trainer, mons = line.split(':', 1)
        teams[trainer.strip()] = [(m.strip().rsplit(' ', 1)[0], int(m.strip().rsplit(' ', 1)[1])) for m in mons.split(',')]
    return teams


if __name__ == '__main__':
    set_parties(sys.argv[1], parse(open(sys.argv[2])))
