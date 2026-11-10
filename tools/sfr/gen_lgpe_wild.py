#!/usr/bin/env python3
"""Super Fire Red: puts Let's Go Pikachu/Eevee wild Pokemon into the Kanto (Fire Red) tables
of src/data/wild_encounters.json.

- Data: tools/sfr/data/lgpe_wild.json (LGPE overworld spawns, extracted from PokeAPI).
- Only land and water tables are replaced. Fishing, Rock Smash, Safari Zone and the
  Sevii Islands keep their Fire Red data (Let's Go has none of them).
- Version exclusives: a Pokemon that appears in only one Let's Go version is kept unless
  it is a LeafGreen exclusive in FRLG (Super Fire Red follows Fire Red).
- Let's Go has no encounter slots, so species are ordered from weakest to strongest
  (base stat total) and spread over the GBA slots: the common slots go to the weaker
  Pokemon, the rare ones to evolved forms.

Usage (repo root): python3 tools/sfr/gen_lgpe_wild.py
"""
import json, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

AREA_TO_MAPS = {
    'kanto-route-1': ['MAP_ROUTE1'],
    'kanto-route-2/south-towards-viridian-city': ['MAP_ROUTE2'],
    'kanto-route-2/north-towards-pewter-city': ['MAP_ROUTE2'],
    'kanto-route-3': ['MAP_ROUTE3'], 'kanto-route-4': ['MAP_ROUTE4'], 'kanto-route-5': ['MAP_ROUTE5'],
    'kanto-route-6': ['MAP_ROUTE6'], 'kanto-route-7': ['MAP_ROUTE7'], 'kanto-route-8': ['MAP_ROUTE8'],
    'kanto-route-9': ['MAP_ROUTE9'], 'kanto-route-10': ['MAP_ROUTE10'], 'kanto-route-11': ['MAP_ROUTE11'],
    'kanto-route-12': ['MAP_ROUTE12'], 'kanto-route-13': ['MAP_ROUTE13'], 'kanto-route-14': ['MAP_ROUTE14'],
    'kanto-route-15': ['MAP_ROUTE15'], 'kanto-route-16': ['MAP_ROUTE16'], 'kanto-route-17': ['MAP_ROUTE17'],
    'kanto-route-18': ['MAP_ROUTE18'], 'kanto-sea-route-19': ['MAP_ROUTE19'], 'kanto-sea-route-20': ['MAP_ROUTE20'],
    'kanto-sea-route-21': ['MAP_ROUTE21_NORTH', 'MAP_ROUTE21_SOUTH'],
    'kanto-route-22': ['MAP_ROUTE22'], 'kanto-route-23': ['MAP_ROUTE23'], 'kanto-route-24': ['MAP_ROUTE24'],
    'kanto-route-25': ['MAP_ROUTE25'],
    'viridian-forest': ['MAP_VIRIDIAN_FOREST'],
    'mt-moon/1f': ['MAP_MT_MOON_1F'], 'mt-moon/b1f': ['MAP_MT_MOON_B1F'], 'mt-moon/b2f': ['MAP_MT_MOON_B2F'],
    'rock-tunnel/1f': ['MAP_ROCK_TUNNEL_1F'], 'rock-tunnel/b1f': ['MAP_ROCK_TUNNEL_B1F'],
    'pokemon-tower/3f': ['MAP_POKEMON_TOWER_3F'], 'pokemon-tower/4f': ['MAP_POKEMON_TOWER_4F'],
    'pokemon-tower/5f': ['MAP_POKEMON_TOWER_5F'], 'pokemon-tower/6f': ['MAP_POKEMON_TOWER_6F', 'MAP_POKEMON_TOWER_7F'],
    'seafoam-islands/1f': ['MAP_SEAFOAM_ISLANDS_1F'], 'seafoam-islands/b1f': ['MAP_SEAFOAM_ISLANDS_B1F'],
    'seafoam-islands/b2f': ['MAP_SEAFOAM_ISLANDS_B2F'], 'seafoam-islands/b3f': ['MAP_SEAFOAM_ISLANDS_B3F'],
    'seafoam-islands/b4f': ['MAP_SEAFOAM_ISLANDS_B4F'],
    'kanto-victory-road-1/1f': ['MAP_VICTORY_ROAD_1F_FRLG'], 'kanto-victory-road-1/2f': ['MAP_VICTORY_ROAD_2F'],
    'kanto-victory-road-1/3f': ['MAP_VICTORY_ROAD_3F'],
    'cerulean-cave/1f': ['MAP_CERULEAN_CAVE_1F'], 'cerulean-cave/2f': ['MAP_CERULEAN_CAVE_2F'],
    'cerulean-cave/b1f': ['MAP_CERULEAN_CAVE_B1F'],
    'digletts-cave': ['MAP_DIGLETTS_CAVE_B1F'],
    'pokemon-mansion/1f': ['MAP_POKEMON_MANSION_1F'], 'pokemon-mansion/2f': ['MAP_POKEMON_MANSION_2F'],
    'pokemon-mansion/3f': ['MAP_POKEMON_MANSION_3F'], 'pokemon-mansion/b1f': ['MAP_POKEMON_MANSION_B1F'],
    'kanto-power-plant': ['MAP_POWER_PLANT'],
    'pallet-town': ['MAP_PALLET_TOWN'], 'cerulean-city': ['MAP_CERULEAN_CITY'], 'vermilion-city': ['MAP_VERMILION_CITY'],
    'celadon-city': ['MAP_CELADON_CITY'], 'fuchsia-city': ['MAP_FUCHSIA_CITY'], 'cinnabar-island': ['MAP_CINNABAR_ISLAND'],
}

# LeafGreen exclusives in Kanto (FRLG). Version-exclusive Let's Go spawns of these are dropped.
LEAFGREEN_ONLY = {'sandshrew', 'sandslash', 'vulpix', 'ninetales', 'bellsprout', 'weepinbell', 'victreebel',
                  'slowpoke', 'slowbro', 'staryu', 'starmie', 'pinsir', 'magmar'}

LAND_SLOTS = 12   # 20 20 10 10 10 10 5 5 4 4 1 1
WATER_SLOTS = 5   # 60 30 5 4 1


def species_constant(name):
    special = {'nidoran-f': 'NIDORAN_F', 'nidoran-m': 'NIDORAN_M', 'mr-mime': 'MR_MIME', 'farfetchd': 'FARFETCHD'}
    return 'SPECIES_' + special.get(name, name.upper().replace('-', '_'))


def base_stat_totals():
    totals = {}
    for path in sorted(os.listdir('src/data/pokemon/species_info')):
        text = open(os.path.join('src/data/pokemon/species_info', path)).read()
        for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*\{(.*?)\n    \},', text, re.S):  # noqa
            body = m.group(2)
            stats = [re.search(rf'\.{s}\s*=\s*(?:[^,\n]*\?\s*)?(\d+)', body) for s in
                     ('baseHP', 'baseAttack', 'baseDefense', 'baseSpeed', 'baseSpAttack', 'baseSpDefense')]
            if all(stats):
                totals[m.group(1)] = sum(int(x.group(1)) for x in stats)
    return totals


def pick(spawns):
    out = []
    for name, e in spawns.items():
        if len(e['versions']) == 1 and name in LEAFGREEN_ONLY:
            continue
        out.append((name, e))
    return out


def build(spawns, n_slots, bst):
    """Weakest species take the common slots; every species gets at least one slot
    and the strongest ones end up in the rare slots."""
    chosen = sorted(pick(spawns), key=lambda x: (bst.get(species_constant(x[0]), 999), x[0]))
    if not chosen:
        return None
    if len(chosen) > n_slots:
        # too many species: keep an even spread from weakest to strongest
        step = len(chosen) / n_slots
        chosen = [chosen[int(i * step)] for i in range(n_slots)]
    extra = [chosen[i % len(chosen)] for i in range(n_slots - len(chosen))]
    rank = {c[0]: i for i, c in enumerate(chosen)}
    slots = sorted(extra + chosen, key=lambda c: rank[c[0]])
    return [{'min_level': e['min'], 'max_level': e['max'], 'species': species_constant(name)} for name, e in slots]


def main():
    data = json.load(open('tools/sfr/data/lgpe_wild.json'))['areas']
    bst = base_stat_totals()
    merged = {}
    for area, maps in AREA_TO_MAPS.items():
        for m in maps:
            dst = merged.setdefault(m, {'land': {}, 'water': {}})
            for kind in ('land', 'water'):
                for sp, e in data.get(area, {}).get(kind, {}).items():
                    cur = dst[kind].setdefault(sp, {'min': e['min'], 'max': e['max'], 'versions': list(e['versions'])})
                    cur['min'] = min(cur['min'], e['min']); cur['max'] = max(cur['max'], e['max'])
                    cur['versions'] = sorted(set(cur['versions']) | set(e['versions']))
    path = 'src/data/wild_encounters.json'
    wild = json.load(open(path))
    changed = 0
    for enc in wild['wild_encounter_groups'][0]['encounters']:
        if not enc['base_label'].endswith('_FireRed') or enc['map'] not in merged:
            continue
        for kind, field, n in (('land', 'land_mons', LAND_SLOTS), ('water', 'water_mons', WATER_SLOTS)):
            if field in enc and merged[enc['map']][kind]:
                mons = build(merged[enc['map']][kind], n, bst)
                if mons:
                    enc[field]['mons'] = mons
                    changed += 1
    json.dump(wild, open(path, 'w'), indent=2)
    open(path, 'a').write('\n')
    print(f'{changed} Kanto tables updated with Let\'s Go data')


if __name__ == '__main__':
    main()
