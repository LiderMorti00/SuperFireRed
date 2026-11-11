#!/usr/bin/env python3
"""Super Fire Red: places the Mega Stones around Hoenn following their Omega Ruby locations.

Each stone becomes an item ball in the Emerald map of its ORAS location. The ball goes on a
free walkable tile next to something the player can already reach in that map (an item
ball, a trainer or an NPC), at the same height. Stones that ORAS gives through an NPC are
placed the same way in that NPC's map, except Cameruptite, Sharpedonite and Metagrossite,
which Maxie, Archie and Steven hand over themselves after their battles.

Flags: FLAG_SFR_ITEM_<STONE>, taken from the unused flags 0x264-0x2BB.
Run once (repo root): python3 tools/sfr/place_mega_stones.py
"""
import json, os, re, struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)

STONES = [  # (item, map dir) — ORAS location in the comment
    ('ABOMASITE', 'Route123'), ('ABSOLITE', 'SafariZone_North'), ('AERODACTYLITE', 'MeteorFalls_B1F_1R'),
    ('AGGRONITE', 'RusturfTunnel'), ('ALAKAZITE', 'SlateportCity'), ('ALTARIANITE', 'LilycoveCity'),
    ('AMPHAROSITE', 'NewMauville_Inside'), ('AUDINITE', 'BattleFrontier_OutsideWest'),   # Battle Resort
    ('BANETTITE', 'MtPyre_Summit'), ('BEEDRILLITE', 'AbandonedShip_HiddenFloorCorridors'),  # Sea Mauville
    ('BLASTOISINITE', 'SSTidalLowerDeck'), ('BLAZIKENITE', 'Route114'), ('SCEPTILITE', 'Route114'),
    ('SWAMPERTITE', 'Route114'), ('CHARIZARDITE_X', 'FieryPath'), ('CHARIZARDITE_Y', 'MtChimney'),  # Scorched Slab
    ('GALLADITE', 'FallarborTown'), ('GARCHOMPITE', 'FortreeCity'), ('GARDEVOIRITE', 'VerdanturfTown'),
    ('GENGARITE', 'BattleFrontier_OutsideEast'), ('GLALITITE', 'ShoalCave_LowTideIceRoom'),
    ('GYARADOSITE', 'Route123'), ('HERACRONITE', 'Route127'), ('HOUNDOOMINITE', 'LavaridgeTown'),
    ('KANGASKHANITE', 'PacifidlogTown'), ('LATIASITE', 'LittlerootTown'), ('LOPUNNITE', 'MauvilleCity'),
    ('LUCARIONITE', 'LilycoveCity_ContestLobby'), ('MANECTITE', 'Route110'), ('MAWILITE', 'VerdanturfTown'),
    ('MEDICHAMITE', 'MtPyre_6F'), ('MEWTWONITE_X', 'LittlerootTown'), ('MEWTWONITE_Y', 'EverGrandeCity'),
    ('PIDGEOTITE', 'RustboroCity'), ('PINSIRITE', 'Route124'), ('SABLENITE', 'SootopolisCity'),
    ('SALAMENCITE', 'MeteorFalls_1F_2R'), ('SCIZORITE', 'PetalburgWoods'), ('SLOWBRONITE', 'ShoalCave_LowTideEntranceRoom'),
    ('STEELIXITE', 'GraniteCave_B2F'), ('TYRANITARITE', 'JaggedPass'), ('VENUSAURITE', 'Route119'),
]
FIRST_FLAG = 0x264


def layout_of(map_dir):
    d = json.load(open(f'data/maps/{map_dir}/map.json'))
    lays = json.load(open('data/layouts/layouts.json'))['layouts']
    lay = [l for l in lays if l.get('id') == d['layout']][0]
    return d, lay, open(lay['blockdata_filepath'], 'rb').read()


def find_tile(d, lay, blocks, used):
    """A free land tile the player can walk (or surf) to from the map's warps/edges,
    as close as possible to an item ball or trainer, otherwise deep inside the map."""
    w, h = lay['width'], lay['height']
    def block(x, y):
        return struct.unpack_from('<H', blocks, (y * w + x) * 2)[0]
    def passable(x, y):
        return 0 <= x < w and 0 <= y < h and (block(x, y) >> 10) & 3 == 0
    def elev(x, y):
        return block(x, y) >> 12
    taken = {(o['x'], o['y']) for o in d['object_events']} | {(e['x'], e['y']) for e in d.get('warp_events', [])} \
        | {(e['x'], e['y']) for e in d.get('coord_events', [])} | {(e['x'], e['y']) for e in d.get('bg_events', [])} | used
    starts = [(e['x'], e['y']) for e in d.get('warp_events', [])]
    if d.get('connections'):
        starts += [(x, y) for x in range(w) for y in (0, h - 1)] + [(x, y) for y in range(h) for x in (0, w - 1)]
    starts = [p for p in starts if passable(*p)] or [(o['x'], o['y']) for o in d['object_events'] if passable(o['x'], o['y'])]
    dist = {p: 0 for p in starts}
    queue = list(starts)
    while queue:
        x, y = queue.pop(0)
        for nx, ny in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
            if (nx, ny) in dist or not passable(nx, ny):
                continue
            e1, e2 = elev(x, y), elev(nx, ny)
            if not (e1 == e2 or 0 in (e1, e2) or 15 in (e1, e2) or 1 in (e1, e2)):
                continue
            dist[(nx, ny)] = dist[(x, y)] + 1
            queue.append((nx, ny))
    near_warp = {(x + dx, y + dy) for x, y in [(e['x'], e['y']) for e in d.get('warp_events', [])]
                 for dx in (-1, 0, 1) for dy in (-1, 0, 1)}
    ok = [p for p in dist if p not in taken and p not in near_warp and elev(*p) not in (0, 1, 15)
          and 1 <= p[0] < w - 1 and 1 <= p[1] < h - 1]
    if not ok:
        return None
    anchors = [(o['x'], o['y']) for o in d['object_events']
               if o['graphics_id'] == 'OBJ_EVENT_GFX_ITEM_BALL' or o.get('trainer_type', 'TRAINER_TYPE_NONE') != 'TRAINER_TYPE_NONE']
    anchors = [a for a in anchors if any(abs(a[0] - p[0]) + abs(a[1] - p[1]) == 1 for p in dist)]
    best = None
    for p in ok:
        if anchors:
            dd = min(abs(p[0] - a[0]) + abs(p[1] - a[1]) for a in anchors)
            key = (dd if dd >= 2 else 99, -dist[p])
        else:
            key = (0, -dist[p])
        if best is None or key < best[0]:
            best = (key, p)
    x, y = best[1]
    return x, y, elev(x, y)


def main():
    flags_h = open('include/constants/flags.h').read()
    used = {}
    for i, (stone, map_dir) in enumerate(STONES):
        flag = f'FLAG_SFR_ITEM_{stone}'
        if flag not in flags_h:
            v = FIRST_FLAG + i
            pat = re.compile(r'^#define FLAG_UNUSED_0x%03X\s+0x%X // Unused Flag$' % (v, v), re.M)
            assert pat.search(flags_h), hex(v)
            flags_h = pat.sub('#define %-40s 0x%X // Super Fire Red: Mega Stone' % (flag, v), flags_h)
        d, lay, blocks = layout_of(map_dir)
        if any(o['flag'] == flag for o in d['object_events']):
            continue
        spot = find_tile(d, lay, blocks, used.setdefault(map_dir, set()))
        if not spot:
            print('no spot for', stone, 'in', map_dir)
            continue
        x, y, elev = spot
        used[map_dir].add((x, y))
        d['object_events'].append({'graphics_id': 'OBJ_EVENT_GFX_ITEM_BALL', 'x': x, 'y': y, 'elevation': elev,
                                   'movement_type': 'MOVEMENT_TYPE_LOOK_AROUND', 'movement_range_x': 1,
                                   'movement_range_y': 1, 'trainer_type': 'TRAINER_TYPE_NONE',
                                   'trainer_sight_or_berry_tree_id': 'ITEM_' + stone,
                                   'script': 'Common_EventScript_FindItem', 'flag': flag})
        json.dump(d, open(f'data/maps/{map_dir}/map.json', 'w'), indent=2)
        open(f'data/maps/{map_dir}/map.json', 'a').write('\n')
        print(f'{stone:15} {map_dir} ({x},{y})')
    open('include/constants/flags.h', 'w').write(flags_h)


if __name__ == '__main__':
    main()
