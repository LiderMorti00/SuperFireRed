#!/usr/bin/env python3
"""Super Fire Red: puts Omega Ruby / Alpha Sapphire wild Pokemon into the Hoenn tables
of src/data/wild_encounters.json.

- Data: tools/sfr/data/oras_wild.json (ORAS encounter slots and DexNav lists).
- Levels follow the Super Fire Red curve: 45 + ORAS level * 0.55.
- Version exclusives: Super Fire Red follows Omega Ruby (Alpha Sapphire-only slots are dropped).
- ORAS and the GBA use different slot rates, so each species keeps (as close as possible)
  its ORAS share of the encounters: the GBA slots are handed out, from the most common to
  the rarest, to the species that is furthest below its ORAS share.
- Hoenn tables with no ORAS counterpart (Mirage Tower, Desert Underpass, Artisan Cave,
  Altering Cave...) keep their Emerald species and only get the level curve.
- DexNav: the ORAS DexNav-only species go into a hidden_mons table (3 slots).

Usage (repo root): python3 tools/sfr/gen_oras_wild.py
"""
import json, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

GAME = 'Omega Ruby'

AREAS = {
    'MAP_ROUTE104': ['route-104_south', 'route-104_north'],
    'MAP_ROUTE111': ['route-111', 'route-111_desert'],
    'MAP_ROUTE112': ['route-112_south', 'route-112_north'],
    'MAP_ROUTE120': ['route-120_west', 'route-120_east'],
    'MAP_UNDERWATER_ROUTE124': ['route-124_underwater'],
    'MAP_UNDERWATER_ROUTE126': ['route-126_underwater'],
    'MAP_PETALBURG_WOODS': ['petalburg-woods'],
    'MAP_RUSTURF_TUNNEL': ['rusturf-tunnel'],
    'MAP_GRANITE_CAVE_1F': ['granite-cave_1f'],
    'MAP_GRANITE_CAVE_STEVENS_ROOM': ['granite-cave_1f'],
    'MAP_GRANITE_CAVE_B1F': ['granite-cave_b1f'],
    'MAP_GRANITE_CAVE_B2F': ['granite-cave_b2f'],
    'MAP_FIERY_PATH': ['fiery-path'],
    'MAP_JAGGED_PASS': ['jagged-pass'],
    'MAP_METEOR_FALLS_1F_1R': ['meteor-falls_1f-front'],
    'MAP_METEOR_FALLS_1F_2R': ['meteor-falls_b1f-back'],
    'MAP_METEOR_FALLS_B1F_1R': ['meteor-falls_b1f-front'],
    'MAP_METEOR_FALLS_B1F_2R': ['meteor-falls_b1f-back'],
    'MAP_METEOR_FALLS_STEVENS_CAVE': ['meteor-falls_b1f-back'],
    'MAP_NEW_MAUVILLE_ENTRANCE': ['new-mauville'],
    'MAP_NEW_MAUVILLE_INSIDE': ['new-mauville'],
    'MAP_MT_PYRE_EXTERIOR': ['mt-pyre_exterior'],
    'MAP_MT_PYRE_SUMMIT': ['mt-pyre_summit'],
    'MAP_ABANDONED_SHIP_ROOMS_B1F': ['sea-mauville_inside'],
    'MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS': ['sea-mauville_inside'],
    'MAP_SEAFLOOR_CAVERN_ENTRANCE': ['seafloor-cavern_entrance'],
    'MAP_CAVE_OF_ORIGIN_ENTRANCE': ['cave-of-origin'],
    'MAP_CAVE_OF_ORIGIN_1F': ['cave-of-origin'],
    'MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM': ['shoal-cave_entrance'],
    'MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM': ['shoal-cave_inner'],
    'MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM': ['shoal-cave_inner'],
    'MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM': ['shoal-cave_inner'],
    'MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM': ['shoal-cave_ice-room'],
    'MAP_VICTORY_ROAD_1F': ['victory-road_entrance'],
    'MAP_VICTORY_ROAD_B1F': ['victory-road_2f'],
    'MAP_VICTORY_ROAD_B2F': ['victory-road_2f'],
    'MAP_SAFARI_ZONE_SOUTH': ['safari-zone_area-1'],
    'MAP_SAFARI_ZONE_SOUTHWEST': ['safari-zone_area-2'],
    'MAP_SAFARI_ZONE_NORTHWEST': ['safari-zone_area-3'],
    'MAP_SAFARI_ZONE_NORTH': ['safari-zone_area-4'],
}
for n in list(range(101, 104)) + list(range(105, 111)) + list(range(113, 120)) + list(range(121, 135)):
    AREAS['MAP_ROUTE%d' % n] = ['route-%d' % n]
for f in range(1, 7):
    AREAS['MAP_MT_PYRE_%dF' % f] = ['mt-pyre_inside']
for r in range(1, 5):
    AREAS['MAP_SEAFLOOR_CAVERN_ROOM%d' % r] = ['seafloor-cavern_room-1']
for r in range(5, 9):
    AREAS['MAP_SEAFLOOR_CAVERN_ROOM%d' % r] = ['seafloor-cavern_room-5']
for f in (1, 3, 5):
    AREAS['MAP_SKY_PILLAR_%dF' % f] = ['sky-pillar']
for town in ('dewford-town', 'lilycove-city', 'mossdeep-city', 'pacifidlog-town', 'petalburg-city',
             'slateport-city', 'sootopolis-city', 'ever-grande-city'):
    AREAS['MAP_' + town.upper().replace('-', '_')] = [town]

FIELDS = {  # GBA field -> (ORAS keys, GBA slot rates or sub-tables)
    'land_mons': (['walking'], [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]),
    'water_mons': (['surfing'], [60, 30, 5, 4, 1]),
    'rock_smash_mons': (['rock_smash'], [60, 30, 5, 4, 1]),
}
FISHING = [('old', [70, 30]), ('good', [60, 20, 20]), ('super', [40, 40, 15, 4, 1])]
SPECIAL = {'nidoran♀': 'NIDORAN_F', 'nidoran♂': 'NIDORAN_M', 'mr. mime': 'MR_MIME', "farfetch'd": 'FARFETCHD',
           'mime jr.': 'MIME_JR', 'flabébé': 'FLABEBE', 'type: null': 'TYPE_NULL'}


def curve(level):
    return int(45 + level * 0.55 + 0.5)


def species_constant(name):
    n = name.lower()
    return 'SPECIES_' + SPECIAL.get(n, re.sub(r'[^A-Z0-9]+', '_', name.upper()).strip('_'))


def levels(text):
    nums = [int(x) for x in re.findall(r'\d+', text)]
    return min(nums), max(nums)


def gather(area_slots):
    """{species: [share, min, max]} from ORAS slots, Omega Ruby only."""
    out = {}
    for slot in area_slots:
        opts = [o for o in slot['options'] if GAME in o['games']]
        for o in opts:
            lo, hi = levels(o['level'])
            e = out.setdefault(species_constant(o['name']), [0.0, lo, hi])
            e[0] += slot['rate'] / len(opts)
            e[1] = min(e[1], lo); e[2] = max(e[2], hi)
    return out


def allocate(species, rates):
    total = sum(v[0] for v in species.values())
    if not species or total == 0:
        return None
    target = {s: v[0] * sum(rates) / total for s, v in species.items()}
    got = {s: 0 for s in species}
    slots = []
    for r in rates:  # rates are already from most to least common
        s = max(species, key=lambda x: (target[x] - got[x], -list(species).index(x)))
        got[s] += r
        slots.append(s)
    return [{'min_level': curve(species[s][1]), 'max_level': curve(species[s][2]), 'species': s} for s in slots]


def merge(keys, kind):
    sp = {}
    for k in keys:
        for s, v in gather(ORAS[k].get(kind, [])).items():
            e = sp.setdefault(s, [0.0, v[1], v[2]])
            e[0] += v[0]; e[1] = min(e[1], v[1]); e[2] = max(e[2], v[2])
    return sp


ORAS = None


def main():
    global ORAS
    data = json.load(open('tools/sfr/data/oras_wild.json'))
    ORAS = data['areas']
    path = 'src/data/wild_encounters.json'
    wild = json.load(open(path))
    group = wild['wild_encounter_groups'][0]
    if not any(f['type'] == 'hidden_mons' for f in group['fields']):
        group['fields'].append({'type': 'hidden_mons', 'encounter_rates': [50, 35, 15]})
    known = {species_constant(n) for n in []}
    species_ok = set(re.findall(r'^\s*(SPECIES_\w+)\s*=', open('include/constants/species.h').read(), re.M))
    stats = {'oras': 0, 'curve': 0, 'hidden': 0, 'missing': set()}
    for enc in group['encounters']:
        if enc['base_label'].endswith(('_FireRed', '_LeafGreen')):
            continue
        keys = AREAS.get(enc['map'])
        if keys:
            stats['oras'] += 1
            for field, (kinds, rates) in FIELDS.items():
                sp = {}
                for kind in kinds:
                    sp.update(merge(keys, kind))
                mons = allocate(sp, rates)
                if mons:
                    enc.setdefault(field, {'encounter_rate': {'land_mons': 20, 'water_mons': 4, 'rock_smash_mons': 20}[field]})
                    enc[field]['mons'] = mons
            fish = []
            for kind, rates in FISHING:
                mons = allocate(merge(keys, kind), rates)
                if not mons:
                    fish = None
                    break
                fish += mons
            if fish:
                enc.setdefault('fishing_mons', {'encounter_rate': 30})
                enc['fishing_mons']['mons'] = fish
            hidden = []
            for k in keys:
                for h in data['dexnav'].get(k, []):
                    s = species_constant(h['name'])
                    if s not in [x['species'] for x in hidden]:
                        lo, hi = levels(h['level'])
                        hidden.append({'min_level': curve(lo), 'max_level': curve(hi), 'species': s})
            if hidden:
                enc['hidden_mons'] = {'encounter_rate': 0, 'mons': hidden[:3]}
                stats['hidden'] += 1
        else:
            stats['curve'] += 1
            for field in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'):
                for m in enc.get(field, {}).get('mons', []):
                    m['min_level'] = curve(m['min_level']); m['max_level'] = curve(m['max_level'])
        for field in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons', 'hidden_mons'):
            for m in enc.get(field, {}).get('mons', []):
                if m['species'] not in species_ok:
                    stats['missing'].add(m['species'])
    json.dump(wild, open(path, 'w'), indent=2)
    open(path, 'a').write('\n')
    print('%d Hoenn tables from ORAS, %d with the level curve only, %d DexNav lists' % (stats['oras'], stats['curve'], stats['hidden']))
    if stats['missing']:
        print('unknown species:', sorted(stats['missing']))


if __name__ == '__main__':
    main()
