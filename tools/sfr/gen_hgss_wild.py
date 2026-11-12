#!/usr/bin/env python3
"""Super Emerald: puts HeartGold / SoulSilver wild Pokemon into the Kanto tables of
src/data/wild_encounters.json.

- Data: pret/pokeheartgold files/fielddata/encountdata/gs_enc_data.json
  (path given as the first argument).
- Both versions: a slot that differs between HeartGold and SoulSilver is split evenly.
- Times of day: the morning table is the base one (also the fallback for every other
  encounter type); Day, Evening (= HGSS day) and Night tables are added for land.
- Levels: Super Emerald postgame curve, 45 + HGSS level x 0.55.
- HGSS and the GBA use different slot counts for fishing and Rock Smash, so each species
  keeps (as close as possible) its HGSS share of the encounters.
- Kanto areas with no HGSS wild Pokemon (Pokemon Tower, Pokemon Mansion, Power Plant,
  Safari Zone, Route 23, S.S. Anne dock) get their Fire Red species back, with the curve.
- Grass, water or rocks that Fire Red has and HGSS lacks in that area keep the Fire Red
  species, with the curve.
- The Sevii Islands are not touched.

Usage (repo root): python3 tools/sfr/gen_hgss_wild.py <pokeheartgold>/files/fielddata/encountdata/gs_enc_data.json
"""
import json, os, re, subprocess, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

AREAS = {  # GBA map -> HGSS area
    'MAP_PALLET_TOWN': 'T01', 'MAP_VIRIDIAN_CITY': 'T02', 'MAP_CERULEAN_CITY': 'T04',
    'MAP_VERMILION_CITY': 'T06', 'MAP_CELADON_CITY': 'T07', 'MAP_FUCHSIA_CITY': 'T08',
    'MAP_CINNABAR_ISLAND': 'T09',
    'MAP_ROUTE16': 'R16R0301', 'MAP_ROUTE19': 'W19', 'MAP_ROUTE20': 'W20',
    'MAP_ROUTE21_NORTH': 'W21', 'MAP_ROUTE21_SOUTH': 'W21',
    'MAP_VIRIDIAN_FOREST': 'D46R0101', 'MAP_DIGLETTS_CAVE_B1F': 'D01R0101',
    'MAP_MT_MOON_1F': 'D02R0101', 'MAP_MT_MOON_B1F': 'D02R0101', 'MAP_MT_MOON_B2F': 'D02R0101',
    'MAP_ROCK_TUNNEL_1F': 'D05R0101', 'MAP_ROCK_TUNNEL_B1F': 'D05R0102',
    'MAP_VICTORY_ROAD_1F_FRLG': 'D43R0101', 'MAP_VICTORY_ROAD_2F': 'D43R0102', 'MAP_VICTORY_ROAD_3F': 'D43R0103',
    'MAP_CERULEAN_CAVE_1F': 'D03R0101', 'MAP_CERULEAN_CAVE_2F': 'D03R0102', 'MAP_CERULEAN_CAVE_B1F': 'D03R0103',
    'MAP_SEAFOAM_ISLANDS_1F': 'D11R0101', 'MAP_SEAFOAM_ISLANDS_B1F': 'D11R0102',
    'MAP_SEAFOAM_ISLANDS_B2F': 'D11R0103', 'MAP_SEAFOAM_ISLANDS_B3F': 'D11R0104',
    'MAP_SEAFOAM_ISLANDS_B4F': 'D11R0105',
}
for n in list(range(1, 16)) + [17, 18, 22, 24, 25]:
    AREAS['MAP_ROUTE%d' % n] = 'R%02d' % n
FIRE_RED_ONLY = ['MAP_POKEMON_TOWER_3F', 'MAP_POKEMON_TOWER_4F', 'MAP_POKEMON_TOWER_5F', 'MAP_POKEMON_TOWER_6F',
                 'MAP_POKEMON_TOWER_7F', 'MAP_POKEMON_MANSION_1F', 'MAP_POKEMON_MANSION_2F', 'MAP_POKEMON_MANSION_3F',
                 'MAP_POKEMON_MANSION_B1F', 'MAP_POWER_PLANT', 'MAP_SAFARI_ZONE_CENTER', 'MAP_SAFARI_ZONE_EAST',
                 'MAP_SAFARI_ZONE_NORTH_FRLG', 'MAP_SAFARI_ZONE_WEST', 'MAP_ROUTE23', 'MAP_SSANNE_EXTERIOR']

HGSS_RATES = {'land': [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1], 'surf': [60, 30, 5, 4, 1],
              'rock_smash': [90, 10], 'rod': [40, 40, 15, 4, 1]}
GBA = {'land_mons': [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1], 'water_mons': [60, 30, 5, 4, 1],
       'rock_smash_mons': [60, 30, 5, 4, 1]}
FISHING = [('old_rod', [70, 30]), ('good_rod', [60, 20, 20]), ('super_rod', [40, 40, 15, 4, 1])]
TIMES = {'morn': '', 'day': '_Day', 'eve': '_Evening', 'nite': '_Night'}
SPECIES_FIX = {}


def curve(level):
    return int(45 + level * 0.55 + 0.5)


def versions(v):
    """value or {HEARTGOLD: x, SOULSILVER: y} -> list of values (one per version)."""
    if isinstance(v, dict) and set(v) <= {'HEARTGOLD', 'SOULSILVER'}:
        return [v['HEARTGOLD'], v['SOULSILVER']]
    return [v, v]


def level_range(lv):
    if isinstance(lv, dict) and 'min' in lv:
        return lv['min'], lv['max']
    return lv, lv


def gather(mons, rates, time=None):
    out = {}
    for mon, rate in zip(mons, rates):
        sp = mon['species']
        if isinstance(sp, dict) and 'morn' in sp:
            sp = sp[time if time in ('morn', 'day', 'nite') else ('day' if time == 'eve' else 'day')]
        for s, l in zip(versions(sp), versions(mon['level'])):
            lo, hi = level_range(l)
            s = SPECIES_FIX.get(s, s)
            e = out.setdefault(s, [0.0, lo, hi])
            e[0] += rate / 2
            e[1] = min(e[1], lo); e[2] = max(e[2], hi)
    return out


def allocate(species, rates):
    total = sum(v[0] for v in species.values())
    if not species or total == 0:
        return None
    target = {s: v[0] * sum(rates) / total for s, v in species.items()}
    got = {s: 0 for s in species}
    order = list(species)
    slots = []
    for r in rates:
        s = max(species, key=lambda x: (target[x] - got[x], -order.index(x)))
        got[s] += r
        slots.append(s)
    return [{'min_level': curve(species[s][1]), 'max_level': curve(species[s][2]), 'species': s} for s in slots]


def main(src):
    hg = {e['map']: e for e in json.load(open(src))['encounters']}
    path = 'src/data/wild_encounters.json'
    wild = json.load(open(path))
    group = wild['wild_encounter_groups'][0]
    upstream = json.loads(subprocess.check_output(['git', 'show', '83dc0468:' + path]))
    fr_upstream = {e['base_label']: e for e in upstream['wild_encounter_groups'][0]['encounters']}
    valid = set(re.findall(r'^\s*(SPECIES_\w+)\s*=', open('include/constants/species.h').read(), re.M))
    missing = set()
    # drop old time-of-day copies of Kanto tables
    group['encounters'] = [e for e in group['encounters']
                           if not (e['map'] in AREAS and re.search(r'_FireRed_(Day|Evening|Night)$', e['base_label']))]
    new_entries = []
    done = 0
    for enc in group['encounters']:
        if not enc['base_label'].endswith('_FireRed'):
            continue
        m = enc['map']
        if m in FIRE_RED_ONLY:
            orig = fr_upstream.get(enc['base_label'])
            if orig:
                for f in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'):
                    if f in orig:
                        enc[f] = json.loads(json.dumps(orig[f]))
                        for mon in enc[f]['mons']:
                            mon['min_level'] = curve(mon['min_level']); mon['max_level'] = curve(mon['max_level'])
                done += 1
            continue
        area = hg.get(AREAS.get(m))
        if not area:
            continue
        done += 1
        for f in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'):
            enc.pop(f, None)
        if area['land']['mons']:
            land = {t: allocate(gather(area['land']['mons'], HGSS_RATES['land'], t), GBA['land_mons']) for t in TIMES}
            enc['land_mons'] = {'encounter_rate': area['land']['rate'] or 20, 'mons': land['morn']}
            for t, suffix in TIMES.items():
                if t != 'morn' and land[t] != land['morn']:
                    new_entries.append({'map': m, 'base_label': enc['base_label'] + suffix,
                                        'land_mons': {'encounter_rate': area['land']['rate'] or 20, 'mons': land[t]}})
        if area['surf']['mons']:
            enc['water_mons'] = {'encounter_rate': 4,
                                 'mons': allocate(gather(area['surf']['mons'], HGSS_RATES['surf']), GBA['water_mons'])}
        if area['rock_smash']['mons']:
            enc['rock_smash_mons'] = {'encounter_rate': 20, 'mons': allocate(
                gather(area['rock_smash']['mons'], HGSS_RATES['rock_smash']), GBA['rock_smash_mons'])}
        fish = []
        for rod, rates in FISHING:
            mons = allocate(gather(area['fishing'][rod]['mons'], HGSS_RATES['rod']), rates)
            if not mons:
                fish = None
                break
            fish += mons
        if fish:
            enc['fishing_mons'] = {'encounter_rate': 30, 'mons': fish}
        # Fire Red has grass / water / rocks that HGSS lacks here: keep its species, with the curve
        orig = fr_upstream.get(enc['base_label'], {})
        for f in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'):
            if f not in enc and f in orig:
                enc[f] = json.loads(json.dumps(orig[f]))
                for mon in enc[f]['mons']:
                    mon['min_level'] = curve(mon['min_level']); mon['max_level'] = curve(mon['max_level'])
    group['encounters'] += new_entries
    for enc in group['encounters']:
        for f in ('land_mons', 'water_mons', 'rock_smash_mons', 'fishing_mons'):
            for mon in enc.get(f, {}).get('mons', []):
                if mon['species'] not in valid:
                    missing.add(mon['species'])
    json.dump(wild, open(path, 'w'), indent=2)
    open(path, 'a').write('\n')
    print(f'{done} Kanto tables updated, {len(new_entries)} day/evening/night land tables')
    if missing:
        print('unknown species:', sorted(missing))


if __name__ == '__main__':
    main(sys.argv[1])
