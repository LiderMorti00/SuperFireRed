#!/usr/bin/env python3
"""Super Emerald: gives the Hoenn story trainers their Omega Ruby / Alpha Sapphire teams.

Data: tools/sfr/data/oras_trainers.json (ORAS trainers per location page, from
altissimo1.github.io/Main-Series/Hoenn-Locations, which credits Bulbapedia), plus the
rival, Wally, Team Magma / Aqua and Champion teams written below from the same site.

- Levels are the original ORAS levels (Hoenn is the main story).
- Both games: Team Magma comes from Omega Ruby, Team Aqua from Alpha Sapphire.
- Route trainers are matched by name with the Emerald trainer whose battle is in one of the
  maps of that location page. ORAS rematch teams go, in order, to the Emerald rematch slots
  TRAINER_X_2 ... TRAINER_X_5 (they unlock with the same badges as in ORAS).
- Wallace is the Sootopolis Gym Leader (Juan's trainer slots), Steven is the Champion
  (Wallace's Champion slot). Juan becomes a Contest coordinator.
- Emerald trainers with no ORAS counterpart keep their Emerald team.
- Each Pokemon keeps the IVs of the trainer's Emerald team; moves are the level-up defaults.

Usage (repo root, on the Emerald trainers.party): python3 tools/sfr/gen_se_hoenn_trainers.py
"""
import collections, json, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
PARTY = 'src/data/trainers.party'

SKIP_NAMES = ('Brendan', 'May', 'Wally', 'Steven', 'Archie', 'Maxie', 'Wallace', 'Team Aqua', 'Team Magma',
              'Aqua', 'Magma', 'Matt', 'Shelly', 'Tabitha', 'Courtney', 'Zinnia', 'Scott')
LEADERS = {'Roxanne': 'TRAINER_ROXANNE_1', 'Brawly': 'TRAINER_BRAWLY_1', 'Wattson': 'TRAINER_WATTSON_1',
           'Flannery': 'TRAINER_FLANNERY_1', 'Norman': 'TRAINER_NORMAN_1', 'Winona': 'TRAINER_WINONA_1',
           'Tate & Liza': 'TRAINER_TATE_AND_LIZA_1', 'Wallace': 'TRAINER_JUAN_1'}
GYM_PAGES = {'rustboro-city': 'Roxanne', 'dewford-town': 'Brawly', 'mauville-city': 'Wattson',
             'lavaridge-town': 'Flannery', 'petalburg-city': 'Norman', 'fortree-city': 'Winona',
             'mossdeep-city': 'Tate & Liza', 'sootopolis-city': 'Wallace'}
GYM_DIRS = {'rustboro-city': 'RustboroCity_Gym', 'dewford-town': 'DewfordTown_Gym', 'mauville-city': 'MauvilleCity_Gym',
            'lavaridge-town': 'LavaridgeTown_Gym', 'petalburg-city': 'PetalburgCity_Gym', 'fortree-city': 'FortreeCity_Gym',
            'mossdeep-city': 'MossdeepCity_Gym', 'sootopolis-city': 'SootopolisCity_Gym'}
ELITE_FOUR = {'Sidney': 'TRAINER_SIDNEY', 'Phoebe': 'TRAINER_PHOEBE', 'Glacia': 'TRAINER_GLACIA', 'Drake': 'TRAINER_DRAKE'}
SPECIAL_SPECIES = {"Farfetch'd": 'Farfetchd', 'Mr. Mime': 'Mr Mime', 'Mime Jr.': 'Mime Jr',
                   'Nidoran♀': 'Nidoran F', 'Nidoran♂': 'Nidoran M', 'Flabébé': 'Flabebe'}

# Rivals. Emerald names the trainer after the player's starter; the rival has the starter
# strong against it, "elemental 1" is weak against the player's starter and "elemental 2"
# shares its type (ORAS rules).
RIVAL_LINES = {  # player's starter -> (rival starter line, elemental 1 line, elemental 2 line)
    'MUDKIP': (('Treecko', 'Grovyle', 'Sceptile'), ('Slugma', 'Magcargo'), ('Wailmer', 'Wailord')),
    'TREECKO': (('Torchic', 'Combusken', 'Blaziken'), ('Wailmer', 'Wailord'), ('Shroomish', 'Breloom')),
    'TORCHIC': (('Mudkip', 'Marshtomp', 'Swampert'), ('Shroomish', 'Breloom'), ('Slugma', 'Magcargo')),
}


def rival_team(place, player_starter):
    st, e1, e2 = RIVAL_LINES[player_starter]
    return {  # ORAS: Route 103, 110, 119 and Lilycove; Rustboro is Emerald-only (Emerald levels)
        'ROUTE_103': [(st[0], 5)],
        'RUSTBORO': [(e1[0], 13), (st[0], 15)],
        'ROUTE_110': [(e1[0], 18), (e2[0], 18), (st[1], 20)],
        'ROUTE_119': [(e1[0], 31), (e2[0], 31), (st[1], 33)],
        'LILYCOVE': [('Swellow', 37), (e1[1], 37), (e2[1], 37), (st[2], 39)],
    }[place]


SPECIAL_TEAMS = {
    # Wally
    'TRAINER_WALLY_MAUVILLE': [('Ralts', 17)],
    'TRAINER_WALLY_VR_1': [('Altaria', 46), ('Delcatty', 46), ('Roselia', 46), ('Magneton', 46), ('Gallade', 48, 'Galladite')],
    # Team Magma (Omega Ruby)
    'TRAINER_TABITHA_MT_CHIMNEY': [('Koffing', 24), ('Numel', 24)],
    'TRAINER_MAXIE_MT_CHIMNEY': [('Mightyena', 25), ('Golbat', 25), ('Camerupt', 27)],
    'TRAINER_TABITHA_MAGMA_HIDEOUT': [('Camerupt', 39)],          # ORAS: Magma Admin in the Hideout
    'TRAINER_MAXIE_MAGMA_HIDEOUT': [('Mightyena', 41), ('Weezing', 41), ('Crobat', 41), ('Camerupt', 43, 'Cameruptite')],
    'TRAINER_TABITHA_MOSSDEEP': [('Mightyena', 41), ('Weezing', 41), ('Camerupt', 43)],
    'TRAINER_MAXIE_MOSSDEEP': [('Mightyena', 42), ('Weezing', 42), ('Crobat', 42), ('Camerupt', 44, 'Cameruptite')],
    # Team Aqua (Alpha Sapphire)
    'TRAINER_SHELLY_WEATHER_INSTITUTE': [('Sharpedo', 32)],
    'TRAINER_MATT': [('Sharpedo', 39)],                           # ORAS: Aqua Admin in the Hideout
    'TRAINER_SHELLY_SEAFLOOR_CAVERN': [('Mightyena', 40), ('Muk', 40), ('Sharpedo', 41)],
    'TRAINER_ARCHIE': [('Mightyena', 41), ('Muk', 41), ('Crobat', 41), ('Sharpedo', 43, 'Sharpedonite')],
    # Champion Steven (in Wallace's Champion slot)
    'TRAINER_WALLACE': [('Skarmory', 57), ('Claydol', 57), ('Aggron', 57), ('Cradily', 57), ('Armaldo', 57),
                        ('Metagross', 59, 'Metagrossite')],
}
for who in ('MAY', 'BRENDAN'):
    for place in ('ROUTE_103', 'RUSTBORO', 'ROUTE_110', 'ROUTE_119', 'LILYCOVE'):
        for st in RIVAL_LINES:
            SPECIAL_TEAMS[f'TRAINER_{who}_{place}_{st}'] = rival_team(place, st)

HEADER_CHANGES = {  # trainer -> {field: value}
    'TRAINER_WALLACE': {'Name': 'STEVEN', 'Pic': 'Steven'},
}
for i in range(1, 6):
    HEADER_CHANGES[f'TRAINER_JUAN_{i}'] = {'Name': 'WALLACE', 'Pic': 'Champion Wallace'}


def page_dirs(page):
    camel = ''.join(w.capitalize() for w in page.split('-'))
    return [d for d in os.listdir('data/maps') if d.startswith(camel) and not d.endswith('_Frlg')]


def trainers_by_dir():
    out = {}
    for d in os.listdir('data/maps'):
        p = os.path.join('data/maps', d, 'scripts.inc')
        if os.path.exists(p):
            out[d] = set(re.findall(r'trainerbattle\w*\s+(TRAINER_\w+)', open(p).read()))
    return out


def block(text, trainer):
    return re.search(rf'^=== {trainer} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)


def emerald_trainers(text):
    out = {}
    for m in re.finditer(r'^=== (TRAINER_\w+) ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M):
        name = re.search(r'^Name: (.*)$', m.group(2), re.M)
        double = re.search(r'^Double Battle: Yes', m.group(2), re.M) is not None
        if name:
            out[m.group(1)] = (name.group(1).strip().upper(), double)
    return out


def rematch_tiers():
    tiers = {}
    for m in re.finditer(r'REMATCH\((TRAINER_\w+), (TRAINER_\w+), (TRAINER_\w+), (TRAINER_\w+), (TRAINER_\w+), MAP_\w+\)',
                         open('src/battle_setup.c').read()):
        ids = list(m.groups())
        tiers[ids[0]] = [t for i, t in enumerate(ids) if i == 0 or t != ids[i - 1]]
    return tiers


def species_name(name, valid):
    n = SPECIAL_SPECIES.get(name, name)
    const = 'SPECIES_' + re.sub(r'[^A-Z0-9]+', '_', n.upper()).strip('_')
    return n if const in valid else None


def set_team(text, trainer, mons, double, header_changes=None):
    m = block(text, trainer)
    parts = m.group(1).split('\n\n')
    header = parts[0]
    ivs = re.findall(r'^IVs: .*$', m.group(1), re.M)
    if double and len(mons) < 2:
        header = header.replace('Double Battle: Yes', 'Double Battle: No')
    for k, v in (header_changes or {}).items():
        header = re.sub(rf'^{k}: .*$', f'{k}: {v}', header, flags=re.M)
    body = []
    for i, mon in enumerate(mons):
        s, l = mon[0], mon[1]
        line = f'{s} @ {mon[2]}' if len(mon) > 2 else s
        iv = ivs[min(i, len(ivs) - 1)] if ivs else None
        if iv and i == len(mons) - 1:
            iv = ivs[-1]
        body.append(f'{line}\nLevel: {l}' + (f'\n{iv}' if iv else ''))
    return text[:m.start(1)] + header + '\n\n' + '\n\n'.join(body) + '\n\n' + text[m.end(1):]


def main():
    valid = set(re.findall(r'^\s*(SPECIES_\w+)\s*=', open('include/constants/species.h').read(), re.M))
    data = json.load(open('tools/sfr/data/oras_trainers.json'))
    text = open(PARTY).read()
    em = emerald_trainers(text)
    by_dir = trainers_by_dir()
    tiers = rematch_tiers()
    teams, log = {}, []

    def convert(party):
        out = []
        for s, l in party:
            n = species_name(s, valid)
            if not n:
                return None
            out.append((n, l))
        return out

    for page, rows in data.items():
        dirs = page_dirs(page)
        local = set().union(*[by_dir.get(d, set()) for d in dirs]) if dirs else set()
        gym_dir = GYM_DIRS.get(page)
        gym_local = set().union(*[by_dir[d] for d in by_dir if gym_dir and d.startswith(gym_dir)]) if gym_dir else set()
        firsts, rematches = {}, collections.defaultdict(list)
        for r in rows:
            who = r['trainer']
            if 'Rematch' in r['table']:
                rematches[who].append(r)
            elif who not in firsts:
                firsts[who] = r
        for who, r in firsts.items():
            if who in LEADERS and GYM_PAGES.get(page) == who:
                team = convert(r['party'])
                if team:
                    teams[LEADERS[who]] = (team, False)
                continue
            if who in ELITE_FOUR:
                if 'Rematch' not in r['table']:
                    team = convert(r['party'])
                    if team:
                        teams[ELITE_FOUR[who]] = (team, False)
                continue
            if who.startswith(SKIP_NAMES) or ' ' not in who:
                continue
            name = who.rsplit(' ', 1)[1].upper()
            if '&' in who:   # double battle pairs: "Twins Gina & Mia" -> GINA & MIA
                name = ' & '.join(x.strip().upper() for x in who.split(' ', 1)[1].split('&'))
            cands = [t for t in (gym_local | local) if t in em and em[t][0] == name and not re.search(r'_[2-5]$', t)]
            if len(cands) != 1:
                log.append(f'{page}: {who} ({len(cands)} matches)')
                continue
            tid = cands[0]
            team = convert(r['party'])
            if not team:
                log.append(f'{page}: {who} (unknown species)')
                continue
            teams[tid] = (team, em[tid][1])
            ids = tiers.get(tid, [tid])[1:]
            for k, rr in enumerate(rematches.get(who, [])[:len(ids)]):
                t2 = convert(rr['party'])
                if t2:
                    teams[ids[k]] = (t2, em[ids[k]][1])
    for tid, team in SPECIAL_TEAMS.items():
        if tid in em:
            teams[tid] = (team, em[tid][1])
        else:
            log.append(f'special: {tid} not in trainers.party')
    for tid, (team, double) in teams.items():
        text = set_team(text, tid, team, double, HEADER_CHANGES.get(tid))
    for tid, ch in HEADER_CHANGES.items():
        if tid not in teams:
            m = block(text, tid)
            body = m.group(1)
            for k, v in ch.items():
                body = re.sub(rf'^{k}: .*$', f'{k}: {v}', body, count=1, flags=re.M)
            text = text[:m.start(1)] + body + text[m.end(1):]
    open(PARTY, 'w').write(text)
    print(f'{len(teams)} Hoenn trainer teams from ORAS; {len(log)} ORAS trainers not matched')
    open('tools/sfr/data/oras_trainers_not_matched.txt', 'w').write('\n'.join(log) + '\n')


if __name__ == '__main__':
    main()
