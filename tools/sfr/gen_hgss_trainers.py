#!/usr/bin/env python3
"""Super Emerald: puts the HeartGold / SoulSilver Kanto trainers on the Fire Red maps.

Data: tools/sfr/data/hgss_trainers.json (HGSS Kanto trainers per location, from
altissimo1.github.io/Main-Series/Kanto-Locations, which credits Bulbapedia; extracted with
tools/sfr/extract_hgss_trainers.py). Base Fire Red teams come from upstream
pokeemerald-expansion (commit 83dc0468).

- For each route / dungeon / Gym, the Fire Red trainers (in the order their battles appear
  in the map scripts) become the HGSS trainers of the same place: name, class, picture and
  team. Trainers of the same class are paired first, the rest in order.
- Fire Red trainers left over, and every other Fire Red trainer of Kanto and the Sevii
  Islands, keep their Fire Red team.
- Levels: Kanto is postgame, but route trainers must stay below the Gym Leaders (55-65),
  so the HGSS trainer levels are spread linearly over 47-62 (Fire Red ones too, over the
  same range).
- VS Seeker rematches (TRAINER_X_2.._5) get the same team, +3 / +6 / +9 / +12 levels.
- Not changed: Gym Leaders, Elite Four, rivals, Team Rocket, the Sevii Islands.

Usage (repo root): python3 tools/sfr/gen_hgss_trainers.py
"""
import collections, json, os, re, subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
PARTY = 'src/data/trainers_frlg.party'
LOW, HIGH = 47, 62

CLASSES = {  # HGSS class -> (Class, male pic, female pic)
    'Ace Trainer': ('Cooltrainer Frlg', 'Cooltrainer M Frlg', 'Cooltrainer F Frlg'),
    'Biker': ('Biker Frlg', 'Biker Frlg', None), 'Bird Keeper': ('Bird Keeper Frlg', 'Bird Keeper Frlg', None),
    'Picnicker': ('Picnicker Frlg', None, 'Picnicker Frlg'), 'Swimmer♀': ('Swimmer F Frlg', None, 'Swimmer F Frlg'),
    'Swimmer♂': ('Swimmer M Frlg', 'Swimmer M Frlg', None), 'School Kid': ('School Kid', 'School Kid M', 'School Kid F'),
    'Fisherman': ('Fisherman Frlg', 'Fisherman Frlg', None), 'Camper': ('Camper Frlg', 'Camper Frlg', None),
    'Bug Catcher': ('Bug Catcher Frlg', 'Bug Catcher Frlg', None), 'Hiker': ('Hiker Frlg', 'Hiker Frlg', None),
    'Pokéfan': ('Pokefan', 'Pokefan M', 'Pokefan F'), 'Lass': ('Lass Frlg', None, 'Lass Frlg'),
    'Psychic': ('Psychic Frlg', 'Psychic M Frlg', 'Psychic F Frlg'), 'Super Nerd': ('Super Nerd Frlg', 'Super Nerd Frlg', None),
    'Youngster': ('Youngster Frlg', 'Youngster Frlg', None), 'Teacher': ('Lady Frlg', None, 'Lady Frlg'),
    'Scientist': ('Scientist Frlg', 'Scientist Frlg', None), 'Sailor': ('Sailor Frlg', 'Sailor Frlg', None),
    'Firebreather': ('Kindler', 'Kindler', None), 'Black Belt': ('Black Belt Frlg', 'Black Belt Frlg', None),
    'Gentleman': ('Gentleman Frlg', 'Gentleman Frlg', None), 'Medium': ('Channeler Frlg', None, 'Channeler Frlg'),
    'Boarder': ('Camper Frlg', 'Camper Frlg', None), 'Skier': ('Picnicker Frlg', None, 'Picnicker Frlg'),
    'Beauty': ('Beauty Frlg', None, 'Beauty Frlg'), 'Juggler': ('Juggler Frlg', 'Juggler Frlg', None),
    'Guitarist': ('Rocker Frlg', 'Rocker Frlg', None), 'Twins': ('Twins Frlg', None, 'Twins Frlg'),
    'Young Couple': ('Young Couple Frlg', 'Young Couple Frlg', None), 'Double Team': ('Cool Couple Frlg', 'Cool Couple Frlg', None),
}
FEMALE_NAMES = {'ARABELLA', 'BONITA', 'JAMIE', 'JOYCE', 'MEGAN', 'QUINN', 'REENA', 'SALMA', 'ELEANOR'}
SKIP_TRAINERS = ('Team Rocket', 'Rival', 'Blue', 'Brock', 'Misty', 'Lt.', 'Erika', 'Janine', 'Sabrina', 'Blaine',
                 'Giovanni', 'Cal', 'Will', 'Koga', 'Bruno', 'Karen', 'Lance', 'Red', 'Falkner', 'Bugsy', 'Whitney',
                 'Morty', 'Chuck', 'Jasmine', 'Pryce', 'Clair')
SKIP_FRLG = re.compile(r'TRAINER_(LEADER|ELITE_FOUR|CHAMPION|RIVAL|TEAM_ROCKET|BOSS|SFR_|SE_)')
EXTRA_LEFTOVERS = ['TRAINER_SUPER_NERD_MIGUEL', 'TRAINER_BIKER_GOON', 'TRAINER_BIKER_GOON_2', 'TRAINER_BIKER_GOON_3',
                   'TRAINER_CUE_BALL_PAXTON']
SPECIES_NAMES = {"Farfetch'd": 'Farfetchd', 'Mr. Mime': 'Mr Mime', 'Mime Jr.': 'Mime Jr', 'Nidoran♀': 'Nidoran F',
                 'Nidoran♂': 'Nidoran M', 'Porygon-Z': 'Porygon Z', 'Ho-Oh': 'Ho Oh'}


def page_groups():
    dirs = os.listdir('data/maps')
    g = {}
    for n in range(1, 26):
        g['route-%d' % n] = [d for d in dirs if d.split('_')[0] == 'Route%d' % n and d.endswith('_Frlg')]
    g['mt-moon'] = [d for d in dirs if d.startswith('MtMoon_')]
    g['seafoam-islands'] = [d for d in dirs if d.startswith('SeafoamIslands_')]
    g['victory-road'] = [d for d in dirs if d.startswith('VictoryRoad_') and d.endswith('_Frlg')]
    g['viridian-forest'] = ['ViridianForest_Frlg']
    g['fighting-dojo'] = ['SaffronCity_Dojo_Frlg']
    for city, camel in (('pewter-city', 'PewterCity'), ('cerulean-city', 'CeruleanCity'), ('vermilion-city', 'VermilionCity'),
                        ('celadon-city', 'CeladonCity'), ('fuchsia-city', 'FuchsiaCity'), ('saffron-city', 'SaffronCity'),
                        ('cinnabar-island', 'CinnabarIsland'), ('viridian-city', 'ViridianCity')):
        g[city + '#gym'] = [d for d in dirs if d.startswith(camel + '_Gym') and d.endswith('_Frlg')]
    g['seafoam-islands#gym'] = g.pop('cinnabar-island#gym')   # HGSS Blaine's Gym is in the Seafoam Islands
    return g


def label_trainers():
    """script label -> first trainer it battles (map scripts and data/scripts/trainers_frlg.inc)."""
    out = {}
    files = ['data/scripts/trainers_frlg.inc'] + [os.path.join('data/maps', d, 'scripts.inc') for d in os.listdir('data/maps')]
    for f in files:
        if not os.path.exists(f):
            continue
        for m in re.finditer(r'^(\w+)::?\n(?:\t[^\n]*\n){0,6}?\ttrainerbattle\w*\s+(TRAINER_\w+)', open(f).read(), re.M):
            out.setdefault(m.group(1), m.group(2))
    return out


LABELS = None


def frlg_slots(dirs, party_ids):
    """Fire Red trainers of these maps, in the order of their objects."""
    global LABELS
    if LABELS is None:
        LABELS = label_trainers()
    out = []
    for d in sorted(dirs):
        p = os.path.join('data/maps', d, 'map.json')
        if not os.path.exists(p):
            continue
        for o in json.load(open(p)).get('object_events', []):
            t = LABELS.get(o.get('script', ''))
            if t and t not in out and t in party_ids and not SKIP_FRLG.match(t) and not re.search(r'_\d+$', t):
                out.append(t)
    return out


def hgss_class(who):
    for c in sorted(CLASSES, key=len, reverse=True):
        if who.startswith(c + ' '):
            return c, who[len(c) + 1:]
    return None, who


def blocks(text):
    return {m.group(1): m for m in re.finditer(r'^=== (TRAINER_\w+) ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)}


def frlg_class(text, tid):
    m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |\Z)', text, re.S | re.M)
    c = re.search(r'^Class: (.*)$', m.group(1), re.M)
    return c.group(1).strip() if c else ''


def species(n):
    return SPECIES_NAMES.get(n, n)


def main():
    data = json.load(open('tools/sfr/data/hgss_trainers.json'))
    text = open(PARTY).read()
    upstream = subprocess.check_output(['git', 'show', '83dc0468:' + PARTY]).decode()
    up_blocks = blocks(upstream)
    party_ids = set(blocks(text))
    groups = page_groups()
    plan = {}          # FRLG trainer -> (HGSS class, HGSS name, HGSS row)
    all_slots = set()
    log = []
    for page, dirs in groups.items():
        base, _, kind = page.partition('#')
        rows = data.get(base, [])
        firsts, seen = [], set()
        for r in rows:
            if 'Rematch' in r['table'] or 'Elite Four' in r['table'] or 'Trainer House' in r['table']:
                continue
            if bool(kind) != ('Gym)' in r['table']):
                continue
            if r['trainer'].startswith(SKIP_TRAINERS) or r['trainer'] in seen:
                continue
            seen.add(r['trainer'])
            firsts.append(r)
        slots = frlg_slots(dirs, party_ids)
        slots = [s for s in slots if s not in plan]
        all_slots.update(slots)
        free = list(slots)
        pending = []
        for r in firsts:
            cls, name = hgss_class(r['trainer'])
            if not cls:
                log.append(f'{page}: unknown class for {r["trainer"]}')
                continue
            match = next((s for s in free if frlg_class(upstream, s) == CLASSES[cls][0]), None)
            if match:
                free.remove(match)
                plan[match] = (cls, name, r)
            else:
                pending.append((cls, name, r))
        for cls, name, r in pending:
            if not free:
                log.append(f'{page}: no Fire Red slot left for {r["trainer"]}')
                continue
            plan[free.pop(0)] = (cls, name, r)
    # every other Fire Red trainer of Kanto and the Sevii Islands keeps its Fire Red team
    all_slots.update(frlg_slots([d for d in os.listdir('data/maps') if d.endswith('_Frlg')], party_ids))
    # Fire Red trainers the label scan misses (long scripts, numbered names)
    all_slots.update(EXTRA_LEFTOVERS)
    leftovers = sorted(all_slots - set(plan))
    # level spread
    hg_levels = [l for _, _, r in plan.values() for _, l in r['party']]
    fr_levels = []
    for t in leftovers:
        fr_levels += [int(x) for x in re.findall(r'^Level: (\d+)', up_blocks[t].group(2), re.M)]
    def spread(levels):
        lo, hi = min(levels), max(levels)
        return lambda l: round(LOW + (l - lo) * (HIGH - LOW) / max(1, hi - lo))
    hg_lv, fr_lv = spread(hg_levels), spread(fr_levels or [1, 2])
    cur = blocks(text)

    def write(tid, header, mons, extra=0):
        nonlocal text
        m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
        if not m:
            return
        body = '\n\n'.join(f'{s}\nLevel: {min(100, l + extra)}' for s, l in mons)
        text = text[:m.start(1)] + header + '\n\n' + body + '\n\n' + text[m.end(1):]

    def make_header(tid, changes):
        m = re.search(rf'^=== {tid} ===\n(.*?)(?=^=== |^/\*|\Z)', text, re.S | re.M)
        header = m.group(1).split('\n\n')[0]
        for k, v in changes.items():
            header = re.sub(rf'^{k}: .*$', f'{k}: {v}', header, flags=re.M)
        return header

    for tid, (cls, name, r) in plan.items():
        klass, mpic, fpic = CLASSES[cls]
        pair = '&' in name
        nm = ' & '.join(x.strip().upper() for x in name.split('&')) if pair else name.upper()
        female = (fpic and not mpic) or nm in FEMALE_NAMES
        changes = {'Name': nm, 'Class': klass, 'Pic': fpic if female else mpic,
                   'Gender': 'Female' if female else 'Male',
                   'Double Battle': 'Yes' if pair and len(r['party']) >= 2 else 'No'}
        mons = [(species(s), hg_lv(l)) for s, l in r['party']]
        for i, extra in enumerate([0, 3, 6, 9, 12]):
            t = tid if i == 0 else f'{tid}_{i + 1}'
            if t in cur:
                write(t, make_header(t, changes), mons, extra)
    for tid in leftovers:
        mons = [(s.strip(), fr_lv(int(l))) for s, l in re.findall(r'^([^\n=-][^\n]*)\nLevel: (\d+)', up_blocks[tid].group(2), re.M)]
        for i, extra in enumerate([0, 3, 6, 9, 12]):
            t = tid if i == 0 else f'{tid}_{i + 1}'
            if t in cur and (i == 0 or t not in all_slots):
                write(t, make_header(t, {}), mons, extra)
    open(PARTY, 'w').write(text)
    print(f'{len(plan)} Fire Red trainers became HGSS trainers, {len(leftovers)} keep their Fire Red team')
    open('tools/sfr/data/hgss_trainers_not_placed.txt', 'w').write('\n'.join(log) + '\n')
    print(len(log), 'HGSS trainers not placed (see tools/sfr/data/hgss_trainers_not_placed.txt)')


if __name__ == '__main__':
    main()
