#!/usr/bin/env python3
"""Super Emerald: Kanto Gym Leaders, Elite Four, Champion Red and the Kanto Gym Leader
rematches, with their HeartGold / SoulSilver teams, moves and held items, at postgame levels.

Data: pret/pokeheartgold files/poketool/trainer/trainers.json (path as first argument).

Levels:
- Gym Leaders: HGSS 44-60 -> 55-65   (55 + (L - 44) x 0.625)
- Elite Four:  HGSS 40-50 -> 65-75   (L + 25)
- Champion Red: HGSS 80-88 -> 72-80  (L - 8)
- League rematch after Red (_2 slots): HGSS rematch teams, 60-75 -> 70-79 (70 + (L - 60) x 0.6)
- Gym Leader rematches after Red: HGSS rematch teams, 48-72 -> 70-78 (70 + (L - 48) / 3)

Trainer slots reused: Giovanni -> Blue (Viridian), Koga -> Janine (Fuchsia),
Lorelei -> Koga, Agatha -> Karen, the Champion slots -> Red. The Gym Leader rematches
use TRAINER_SFR_<LEADER>_REMATCH (src/data/trainers.party) and TRAINER_SE_BLUE_REMATCH.

Usage (repo root): python3 tools/sfr/gen_se_kanto_league.py <pokeheartgold>/files/poketool/trainer/trainers.json
"""
import json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
FRLG_PARTY = 'src/data/trainers_frlg.party'
EM_PARTY = 'src/data/trainers.party'

MOVE_FIX = {'MOVE_FAINT_ATTACK': 'MOVE_FEINT_ATTACK', 'MOVE_HI_JUMP_KICK': 'MOVE_HIGH_JUMP_KICK',
            'MOVE_SMELLING_SALT': 'MOVE_SMELLING_SALTS', 'MOVE_SELFDESTRUCT': 'MOVE_SELF_DESTRUCT',
            'MOVE_SOFTBOILED': 'MOVE_SOFT_BOILED', 'MOVE_THUNDERPUNCH': 'MOVE_THUNDER_PUNCH',
            'MOVE_VICEGRIP': 'MOVE_VISE_GRIP', 'MOVE_DOUBLESLAP': 'MOVE_DOUBLE_SLAP'}

leader = lambda l: round(55 + (l - 44) * 0.625)
elite = lambda l: l + 25
red = lambda l: l - 8
elite2 = lambda l: round(70 + (l - 60) * 0.6)
leader2 = lambda l: round(70 + (l - 48) / 3)

# (pokeheartgold index, trainer, level function, header changes)
JOBS = [
    (253, 'TRAINER_LEADER_BROCK', leader, {}),
    (254, 'TRAINER_LEADER_MISTY', leader, {}),
    (255, 'TRAINER_LEADER_LT_SURGE', leader, {}),
    (256, 'TRAINER_LEADER_ERIKA', leader, {}),
    (257, 'TRAINER_LEADER_KOGA', leader, {'Name': 'JANINE', 'Pic': 'Leader Janine', 'Gender': 'Female'}),
    (258, 'TRAINER_LEADER_SABRINA', leader, {}),
    (259, 'TRAINER_LEADER_BLAINE', leader, {}),
    (261, 'TRAINER_LEADER_GIOVANNI', leader, {'Name': 'BLUE', 'Pic': 'Champion Rival Frlg'}),
    (247, 'TRAINER_ELITE_FOUR_LORELEI', elite, {'Name': 'KOGA', 'Pic': 'Leader Koga Frlg'}),
    (418, 'TRAINER_ELITE_FOUR_BRUNO', elite, {}),
    (246, 'TRAINER_ELITE_FOUR_AGATHA', elite, {'Name': 'KAREN', 'Pic': 'Elite Four Karen', 'Gender': 'Female'}),
    (244, 'TRAINER_ELITE_FOUR_LANCE', elite, {}),
    (703, 'TRAINER_ELITE_FOUR_LORELEI_2', elite2, {'Name': 'KOGA', 'Pic': 'Leader Koga Frlg'}),
    (704, 'TRAINER_ELITE_FOUR_BRUNO_2', elite2, {}),
    (705, 'TRAINER_ELITE_FOUR_AGATHA_2', elite2, {'Name': 'KAREN', 'Pic': 'Elite Four Karen', 'Gender': 'Female'}),
    (701, 'TRAINER_ELITE_FOUR_LANCE_2', elite2, {}),
]
for t in ('FIRST', 'REMATCH'):
    for s in ('SQUIRTLE', 'BULBASAUR', 'CHARMANDER'):
        JOBS.append((260, f'TRAINER_CHAMPION_{t}_{s}', red, {'Name': 'RED', 'Pic': 'Red'}))
REMATCH_HEADER = '''Name: {name}
Class: Leader Frlg
Pic: {pic}
Gender: {gender}
Music: Serious
Items: Full Restore / Full Restore / Full Restore
Double Battle: No
AI: Basic Trainer'''
LEADER_REMATCHES = [  # index, trainer, name, pic, gender
    (720, 'TRAINER_SFR_BROCK_REMATCH', 'BROCK', 'Leader Brock Frlg', 'Male'),
    (721, 'TRAINER_SFR_MISTY_REMATCH', 'MISTY', 'Leader Misty Frlg', 'Female'),
    (722, 'TRAINER_SFR_LT_SURGE_REMATCH', 'LT. SURGE', 'Leader Lt Surge Frlg', 'Male'),
    (723, 'TRAINER_SFR_ERIKA_REMATCH', 'ERIKA', 'Leader Erika Frlg', 'Female'),
    (724, 'TRAINER_SFR_KOGA_REMATCH', 'JANINE', 'Leader Janine', 'Female'),
    (725, 'TRAINER_SFR_SABRINA_REMATCH', 'SABRINA', 'Leader Sabrina Frlg', 'Female'),
    (726, 'TRAINER_SFR_BLAINE_REMATCH', 'BLAINE', 'Leader Blaine Frlg', 'Male'),
    (727, 'TRAINER_SE_BLUE_REMATCH', 'BLUE', 'Champion Rival Frlg', 'Male'),
]
IVS = 31


def pretty(const, prefix):
    return const[len(prefix):].replace('_', ' ').title()


def mon_lines(p, lvfn, valid_moves, valid_items):
    sp = pretty(p['species'], 'SPECIES_')
    item = p.get('item')
    if item and item != 'ITEM_NONE' and item in valid_items:
        sp += ' @ ' + pretty(item, 'ITEM_')
    out = [sp, f'Level: {lvfn(p["level"])}',
           f'IVs: {IVS} HP / {IVS} Atk / {IVS} Def / {IVS} SpA / {IVS} SpD / {IVS} Spe']
    for m in p.get('moves') or []:
        m = MOVE_FIX.get(m, m)
        if m != 'MOVE_NONE' and m in valid_moves:
            out.append('- ' + pretty(m, 'MOVE_'))
    return '\n'.join(out)


def block(text, tid):
    return re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)


def set_block(text, tid, header, body):
    m = block(text, tid)
    if not m:
        return text.rstrip('\n') + f'\n\n=== {tid} ===\n{header}\n\n{body}\n\n'
    return text[:m.start(1)] + header + '\n\n' + body + '\n\n' + text[m.end(1):]


def header_of(text, tid, changes):
    header = block(text, tid).group(1).split('\n\n')[0]
    for k, v in changes.items():
        if re.search(rf'^{k}: ', header, re.M):
            header = re.sub(rf'^{k}: .*$', f'{k}: {v}', header, flags=re.M)
        else:
            header = header.replace('\nDouble Battle', f'\n{k}: {v}\nDouble Battle', 1)
    if not re.search(r'^Items: ', header, re.M):
        header = header.replace('\nDouble Battle', '\nItems: Full Restore / Full Restore / Full Restore\nDouble Battle', 1)
    return header


def main(src):
    hg = json.load(open(src))['trainers']
    valid_moves = set(re.findall(r'^\s*(MOVE_\w+)\s*=', open('include/constants/moves.h').read(), re.M))
    valid_items = set(re.findall(r'^\s*(ITEM_\w+)\s*=', open('include/constants/items.h').read(), re.M))
    frlg = open(FRLG_PARTY).read()
    for idx, tid, lvfn, changes in JOBS:
        body = '\n\n'.join(mon_lines(p, lvfn, valid_moves, valid_items) for p in hg[idx]['party'])
        frlg = set_block(frlg, tid, header_of(frlg, tid, changes), body)
    open(FRLG_PARTY, 'w').write(frlg)
    em = open(EM_PARTY).read()
    for idx, tid, name, pic, gender in LEADER_REMATCHES:
        body = '\n\n'.join(mon_lines(p, leader2, valid_moves, valid_items) for p in hg[idx]['party'])
        em = set_block(em, tid, REMATCH_HEADER.format(name=name, pic=pic, gender=gender), body)
    open(EM_PARTY, 'w').write(em)
    print('Kanto Gym Leaders, Elite Four, Red and Gym Leader rematches written')


if __name__ == '__main__':
    main(sys.argv[1])
