#!/usr/bin/env python3
"""Super Fire Red: gives Hoenn trainers their Omega Ruby / Alpha Sapphire teams.

Data: tools/sfr/data/oras_trainers.json (ORAS trainers per location page, from
altissimo1.github.io/Main-Series/Hoenn-Locations, which credits Bulbapedia).

Matching: an ORAS trainer is matched with the Emerald trainer of the same name whose
battle script is in one of the maps of that location page. Rematches: the ORAS rematch
teams, in order, go to the Emerald rematch slots TRAINER_X_2 ... TRAINER_X_5.

Levels (Super Fire Red curve):
- Route trainers and rematches: 45 + ORAS level * 0.55.
- Gym Leaders: their ace is at 60-62; the rest of the team keeps its ORAS gap.
- Gym trainers: 3 levels below their leader, keeping their ORAS gaps (never under 52).
- Elite Four: 72-76.
Not changed: Wallace (set by hand), May, Brendan, Wally, Steven, Archie, Maxie,
Team Aqua / Magma and trainers missing from ORAS.

Usage (repo root): python3 tools/sfr/gen_oras_trainers.py
"""
import collections, glob, json, os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
sys.path.insert(0, 'tools/sfr')

PARTY = 'src/data/trainers.party'
GAME_SKIP = 'Alpha Sapphire Trainers'   # Super Fire Red follows Omega Ruby
SKIP_NAMES = ('Brendan', 'May', 'Wally', 'Steven', 'Archie', 'Maxie', 'Wallace', 'Team Aqua', 'Team Magma',
              'Aqua', 'Magma', 'Matt', 'Shelly', 'Tabitha', 'Courtney', 'Zinnia', 'Scott')
LEADERS = {  # ORAS name -> (Emerald trainer, ace level)
    'Roxanne': ('TRAINER_ROXANNE_1', 60), 'Brawly': ('TRAINER_BRAWLY_1', 60), 'Wattson': ('TRAINER_WATTSON_1', 60),
    'Flannery': ('TRAINER_FLANNERY_1', 61), 'Norman': ('TRAINER_NORMAN_1', 61), 'Winona': ('TRAINER_WINONA_1', 61),
    'Tate & Liza': ('TRAINER_TATE_AND_LIZA_1', 62),
    'Wallace': (None, 62),   # team set by hand; only used for his gym trainers
}
GYM_PAGES = {'rustboro-city': 'Roxanne', 'dewford-town': 'Brawly', 'mauville-city': 'Wattson',
             'lavaridge-town': 'Flannery', 'petalburg-city': 'Norman', 'fortree-city': 'Winona',
             'mossdeep-city': 'Tate & Liza', 'sootopolis-city': 'Wallace'}
GYM_DIRS = {'rustboro-city': 'RustboroCity_Gym', 'dewford-town': 'DewfordTown_Gym', 'mauville-city': 'MauvilleCity_Gym',
            'lavaridge-town': 'LavaridgeTown_Gym', 'petalburg-city': 'PetalburgCity_Gym', 'fortree-city': 'FortreeCity_Gym',
            'mossdeep-city': 'MossdeepCity_Gym', 'sootopolis-city': 'SootopolisCity_Gym'}
ELITE_FOUR = {'Sidney': 'TRAINER_SIDNEY', 'Phoebe': 'TRAINER_PHOEBE', 'Glacia': 'TRAINER_GLACIA', 'Drake': 'TRAINER_DRAKE'}
SPECIAL_SPECIES = {"Farfetch'd": 'Farfetchd', 'Mr. Mime': 'Mr Mime', 'Mime Jr.': 'Mime Jr',
                   'Nidoran♀': 'Nidoran F', 'Nidoran♂': 'Nidoran M', 'Flabébé': 'Flabebe'}


KEEP_PREFIXES = ('TRAINER_MAY_', 'TRAINER_BRENDAN_', 'TRAINER_WALLY_', 'TRAINER_JUAN_')
KEEP = set()


def curve(level):
    return int(45 + level * 0.55 + 0.5)


def page_dirs(page):
    camel = ''.join(w.capitalize() for w in page.split('-'))
    camel = camel.replace('Mt', 'Mt')
    return [d for d in os.listdir('data/maps') if d.startswith(camel) and not d.endswith('_Frlg')]


def trainers_by_dir():
    out = {}
    for d in os.listdir('data/maps'):
        p = os.path.join('data/maps', d, 'scripts.inc')
        if os.path.exists(p):
            out[d] = set(re.findall(r'trainerbattle\w*\s+(TRAINER_\w+)', open(p).read()))
    return out


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


def set_team(text, trainer, mons, double):
    m = re.search(rf'^=== {trainer} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
    header = m.group(1).split('\n\n')[0]
    if double and len(mons) < 2:
        header = header.replace('Double Battle: Yes', 'Double Battle: No')
    body = '\n\n'.join(f'{s}\nLevel: {l}' for s, l in mons)
    return text[:m.start(1)] + header + '\n\n' + body + '\n\n' + text[m.end(1):]


def main():
    valid = set(re.findall(r'^\s*(SPECIES_\w+)\s*=', open('include/constants/species.h').read(), re.M))
    data = json.load(open('tools/sfr/data/oras_trainers.json'))
    text = open(PARTY).read()
    em = emerald_trainers(text)
    KEEP.update(t for t in em if t.startswith(KEEP_PREFIXES) or t in
                ('TRAINER_STEVEN', 'TRAINER_ARCHIE', 'TRAINER_MAXIE_MT_CHIMNEY', 'TRAINER_WALLACE', 'TRAINER_NONE'))
    by_dir = trainers_by_dir()
    tiers = rematch_tiers()
    teams, log = {}, []

    def convert(party, fn):
        out = []
        for s, l in party:
            n = species_name(s, valid)
            if not n:
                return None
            out.append((n, fn(l)))
        return out

    for page, rows in data.items():
        dirs = page_dirs(page)
        local = set().union(*[by_dir.get(d, set()) for d in dirs]) if dirs else set()
        gym_dir = GYM_DIRS.get(page)
        gym_local = set().union(*[by_dir[d] for d in by_dir if gym_dir and d.startswith(gym_dir)]) if gym_dir else set()
        firsts, rematches = {}, collections.defaultdict(list)
        for r in rows:
            if GAME_SKIP in r['table'] and 'Omega' not in r['table']:
                continue
            who = r['trainer']
            if 'Rematch' in r['table']:
                rematches[who].append(r)
            elif who not in firsts:
                firsts[who] = r
        for who, r in firsts.items():
            if who in LEADERS and GYM_PAGES.get(page) == who:
                tid, ace = LEADERS[who]
                top = max(l for _, l in r['party'])
                team = convert(r['party'], lambda l: ace - (top - l))
                if team and tid:
                    teams[tid] = (team, False)
                continue
            if who in ELITE_FOUR:
                team = convert(r['party'], lambda l: 72 + round((l - 50) * 0.8))
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
            if tid in gym_local and GYM_PAGES.get(page) in LEADERS:
                leader = GYM_PAGES[page]
                lr = firsts.get(leader)
                top = max(l for _, l in lr['party']) if lr else max(l for _, l in r['party'])
                ace = LEADERS[leader][1] - 3
                team = convert(r['party'], lambda l: max(52, ace - (top - l)))
            else:
                team = convert(r['party'], curve)
            if not team:
                log.append(f'{page}: {who} (unknown species)')
                continue
            teams[tid] = (team, em[tid][1])
            ids = tiers.get(tid, [tid])[1:]
            for k, rr in enumerate(rematches.get(who, [])[:len(ids)]):
                t2 = convert(rr['party'], curve)
                if t2:
                    teams[ids[k]] = (t2, em[ids[k]][1])
    for tid, (team, double) in teams.items():
        text = set_team(text, tid, team, double)
    # Emerald trainers with no ORAS counterpart keep their team and get the level curve
    gym_trainers = set().union(*[v for d, v in by_dir.items() if d.endswith('_Gym') or '_Gym_' in d])
    curved = 0
    def lift(m):
        return 'Level: %d' % curve(int(m.group(1)))
    for tid in em:
        if tid in teams or tid in KEEP:
            continue
        m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
        lv = [int(x) for x in re.findall(r'^Level: (\d+)', m.group(1), re.M)]
        if not lv or max(lv) >= 45:
            continue
        if tid in gym_trainers:
            body = re.sub(r'^Level: (\d+)', lambda x: 'Level: %d' % max(52, 57 - (max(lv) - int(x.group(1)))), m.group(1), flags=re.M)
        else:
            body = re.sub(r'^Level: (\d+)', lift, m.group(1), flags=re.M)
        text = text[:m.start(1)] + body + text[m.end(1):]
        curved += 1
    open(PARTY, 'w').write(text)
    print(f'{len(teams)} Hoenn trainer teams from ORAS; {curved} Emerald teams with the level curve; '
          f'{len(log)} ORAS trainers not matched')
    open('tools/sfr/data/oras_trainers_not_matched.txt', 'w').write('\n'.join(log) + '\n')


if __name__ == '__main__':
    main()
