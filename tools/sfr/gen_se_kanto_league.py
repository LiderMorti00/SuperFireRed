#!/usr/bin/env python3
"""Super Emerald: Kanto Gym Leaders, Elite Four and Champion as in HeartGold / SoulSilver,
at postgame levels (src/data/trainers_frlg.party).

- Gym Leaders: HGSS teams; levels moved from HGSS 33-58 to 55-65 (55 + 0.4 x (HGSS - 33)).
- Elite Four (Koga, Bruno, Karen, Lance): HGSS teams; HGSS level + 25 (65-75).
- Champion Red: his Mt. Silver team, Pikachu at 80 and the rest 72-76.
- League rematch (_2 slots, after beating Red): the same Elite Four teams 5 levels higher.
Trainer slots reused: Giovanni -> Blue (Viridian), Koga -> Janine (Fuchsia),
Lorelei -> Koga, Agatha -> Karen, the three Champion slots -> Red.

Usage (repo root): python3 tools/sfr/gen_se_kanto_league.py
"""
import os, re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
PARTY = 'src/data/trainers_frlg.party'


def leader(l):
    return int(55 + 0.4 * (l - 33) + 0.5)


LEADERS = {
    'TRAINER_LEADER_BROCK': (None, [('Graveler', 41), ('Rhyhorn', 41), ('Omastar', 42), ('Kabutops', 42), ('Onix', 44)]),
    'TRAINER_LEADER_MISTY': (None, [('Golduck', 42), ('Quagsire', 42), ('Lapras', 44), ('Starmie', 47)]),
    'TRAINER_LEADER_LT_SURGE': (None, [('Raichu', 46), ('Electrode', 40), ('Magneton', 40), ('Electrode', 40), ('Electabuzz', 46)]),
    'TRAINER_LEADER_ERIKA': (None, [('Tangela', 42), ('Jumpluff', 41), ('Victreebel', 46), ('Bellossom', 46)]),
    'TRAINER_LEADER_KOGA': ({'Name': 'JANINE', 'Pic': 'Leader Janine', 'Gender': 'Female'},
                            [('Crobat', 36), ('Weezing', 36), ('Ariados', 33), ('Ariados', 33), ('Venomoth', 39)]),
    'TRAINER_LEADER_SABRINA': (None, [('Espeon', 46), ('Mr. Mime', 46), ('Alakazam', 48)]),
    'TRAINER_LEADER_BLAINE': (None, [('Magcargo', 45), ('Magmar', 45), ('Rapidash', 50)]),
    'TRAINER_LEADER_GIOVANNI': ({'Name': 'BLUE', 'Pic': 'Champion Rival Frlg', 'Music': 'Serious'},
                                [('Pidgeot', 56), ('Alakazam', 54), ('Rhydon', 56), ('Gyarados', 58), ('Exeggutor', 58), ('Arcanine', 58)]),
}
ELITE = {
    'TRAINER_ELITE_FOUR_LORELEI': ({'Name': 'KOGA', 'Pic': 'Leader Koga Frlg'},
                                   [('Ariados', 40), ('Venomoth', 41), ('Forretress', 43), ('Muk', 42), ('Crobat', 44)]),
    'TRAINER_ELITE_FOUR_BRUNO': (None, [('Hitmontop', 42), ('Hitmonlee', 42), ('Hitmonchan', 42), ('Onix', 43), ('Machamp', 46)]),
    'TRAINER_ELITE_FOUR_AGATHA': ({'Name': 'KAREN', 'Pic': 'Elite Four Karen', 'Gender': 'Female'},
                                  [('Umbreon', 42), ('Vileplume', 42), ('Murkrow', 44), ('Gengar', 45), ('Houndoom', 47)]),
    'TRAINER_ELITE_FOUR_LANCE': (None, [('Gyarados', 44), ('Dragonite', 47), ('Dragonite', 47), ('Aerodactyl', 46), ('Charizard', 46), ('Dragonite', 50)]),
}
RED = [('Pikachu', 80), ('Espeon', 72), ('Snorlax', 74), ('Venusaur', 76), ('Charizard', 76), ('Blastoise', 76)]
CHAMPIONS = ['TRAINER_CHAMPION_FIRST_SQUIRTLE', 'TRAINER_CHAMPION_FIRST_BULBASAUR', 'TRAINER_CHAMPION_FIRST_CHARMANDER']
IVS = {'leader': 24, 'elite': 30, 'champion': 31}


def set_team(text, tid, mons, header_changes, ivs, items=None):
    m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
    header = m.group(1).split('\n\n')[0]
    for k, v in (header_changes or {}).items():
        if re.search(rf'^{k}: ', header, re.M):
            header = re.sub(rf'^{k}: .*$', f'{k}: {v}', header, flags=re.M)
        else:
            header = header.replace('\nDouble Battle', f'\n{k}: {v}\nDouble Battle', 1)
    if items:
        if re.search(r'^Items: ', header, re.M):
            header = re.sub(r'^Items: .*$', f'Items: {items}', header, flags=re.M)
        else:
            header = header.replace('\nDouble Battle', f'\nItems: {items}\nDouble Battle', 1)
    iv = f'IVs: {ivs} HP / {ivs} Atk / {ivs} Def / {ivs} SpA / {ivs} SpD / {ivs} Spe'
    body = '\n\n'.join(f'{s}\nLevel: {l}\n{iv}' for s, l in mons)
    return text[:m.start(1)] + header + '\n\n' + body + '\n\n' + text[m.end(1):]


def main():
    text = open(PARTY).read()
    for tid, (hc, mons) in LEADERS.items():
        text = set_team(text, tid, [(s, leader(l)) for s, l in mons], hc, IVS['leader'],
                        'Full Restore / Full Restore')
    for tid, (hc, mons) in ELITE.items():
        text = set_team(text, tid, [(s, l + 25) for s, l in mons], hc, IVS['elite'],
                        'Full Restore / Full Restore / Full Restore')
    # League rematch after beating Red: same teams, 5 levels higher (Red stays at 80)
    for tid, (hc, mons) in ELITE.items():
        text = set_team(text, tid + '_2', [(s, l + 30) for s, l in mons], hc, IVS['champion'],
                        'Full Restore / Full Restore / Full Restore')
    for tid in CHAMPIONS + [t.replace('FIRST', 'REMATCH') for t in CHAMPIONS]:
        text = set_team(text, tid, RED, {'Name': 'RED', 'Pic': 'Red'}, IVS['champion'],
                        'Full Restore / Full Restore / Full Restore / Full Restore')
    open(PARTY, 'w').write(text)
    print('Kanto Gym Leaders, Elite Four and Red written')


if __name__ == '__main__':
    main()
