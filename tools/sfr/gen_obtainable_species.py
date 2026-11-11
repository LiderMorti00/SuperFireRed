#!/usr/bin/env python3
"""Super Fire Red: lists every species that can be obtained in the game, for the Shiny Charm.

A species counts as obtainable when it:
- appears in any wild table (src/data/wild_encounters.json), or
- is given, hatched, met in an overworld battle or traded for in a script / in-game trade, or
- evolves from an obtainable species with a method the game supports (no regional-form
  evolutions; trade evolutions through the Linking Cord; evolution and held items must be
  obtainable somewhere), or
- hatches from an obtainable species (incense babies only if the incense is obtainable).

Obtainable items: item balls, hidden items, giveitem in scripts and Poke Mart lists.
Output: src/data/sfr_obtainable_species.h (national dex numbers).
Usage (repo root): python3 tools/sfr/gen_obtainable_species.py
"""
import glob, json, os, re

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
REGIONAL = ('_ALOLA', '_GALAR', '_HISUI', '_PALDEA')
BAD_CONDITIONS = ('IF_REGION', 'IF_IN_MAPSEC', 'IF_IN_MAP', 'IF_RECOIL_DAMAGE_GE', 'IF_CURRENT_DAMAGE_GE',
                  'IF_TRADE_PARTNER_SPECIES', 'IF_USED_MOVE_X_TIMES', 'IF_DEFEAT_X_WITH_ITEMS',
                  'IF_PID_UPPER_MODULO_10_EQ', 'IF_PID_UPPER_MODULO_10_GT', 'IF_PID_UPPER_MODULO_10_LT')
OK_METHODS = ('EVO_LEVEL', 'EVO_ITEM', 'EVO_TRADE', 'EVO_LEVEL_BATTLE_ONLY', 'EVO_SPLIT_FROM_EVO', 'EVO_BATTLE_END')


def obtainable_items():
    items = set()
    for f in glob.glob('data/maps/*/map.json'):
        d = json.load(open(f))
        for o in d.get('object_events', []):
            if o.get('script') == 'Common_EventScript_FindItem':
                items.add(o.get('trainer_sight_or_berry_tree_id'))
        for b in d.get('bg_events', []):
            if b.get('type') == 'hidden_item':
                items.add(b.get('item'))
    for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc') + ['data/event_scripts.s']:
        s = open(f).read()
        items |= set(re.findall(r'\b(?:giveitem|giveitem_msg[^,]*,|additem|checkitemspace)\s+(ITEM_\w+)', s))
        for mart in re.findall(r'pokemart\s+(\w+)', s):
            m = re.search(rf'^{mart}::?\n((?:\s*\.2byte .*\n)+)', s, re.M)
            if m:
                items |= set(re.findall(r'ITEM_\w+', m.group(1)))
        items |= set(re.findall(r'^\s*pokemartlistend\s*$|^\s*\.2byte (ITEM_\w+)', s, re.M)) - {''}
    return items


def species_info():
    evo, nat, forms = {}, {}, {}
    for f in sorted(glob.glob('src/data/pokemon/species_info/gen_*_families.h')):
        s = open(f).read()
        for m in re.finditer(r'^\s*\[(SPECIES_\w+)\]\s*=\s*\{(.*?)^\s*\},', s, re.S | re.M):
            sp, body = m.group(1), m.group(2)
            n = re.search(r'\.natDexNum\s*=\s*(NATIONAL_DEX_\w+)', body)
            if n:
                nat[sp] = n.group(1)
            e = re.search(r'\.evolutions\s*=\s*EVOLUTION\((.*?)\),\s*\n', body, re.S)
            if e:
                evo[sp] = e.group(1)
    return evo, nat


def split_evos(text):
    out, depth, cur = [], 0, ''
    for ch in text:
        if ch == '{':
            depth += 1
        if depth > 0:
            cur += ch
        if ch == '}':
            depth -= 1
            if depth == 0:
                out.append(cur); cur = ''
    return out


def main():
    items = obtainable_items()
    evo, nat = species_info()
    have = set()
    w = json.load(open('src/data/wild_encounters.json'))
    for g in w['wild_encounter_groups']:
        for e in g['encounters']:
            for k, v in e.items():
                if isinstance(v, dict) and 'mons' in v:
                    have |= {m['species'] for m in v['mons']}
    for f in glob.glob('data/maps/*/scripts.inc') + glob.glob('data/scripts/*.inc'):
        text = open(f).read()
        have |= set(re.findall(r'\b(?:setwildbattle|seteventmon|givemon|giveegg|createmon)\s+(SPECIES_\w+)', text))
        # starter choices pass the species through a variable before givemon
        have |= set(re.findall(r'setvar VAR_\w+, (SPECIES_\w+)', text))
    have |= set(re.findall(r'\.species\s*=\s*(SPECIES_\w+)', open('src/data/trade.h').read()))
    have |= set(re.findall(r'TryAddRoamer\((SPECIES_\w+)', open('src/roamer.c').read()))
    incense = {m[2]: m[1] for m in re.findall(r'\{\s*(SPECIES_\w+),\s*(ITEM_\w+),\s*(SPECIES_\w+)\s*\}', open('src/daycare.c').read())}
    pre = {}
    for sp, text in evo.items():
        for one in split_evos(text):
            t = re.search(r'(SPECIES_\w+)', one)
            if t:
                pre.setdefault(t.group(1), []).append(sp)
    changed = True
    while changed:
        changed = False
        for sp in list(have):
            if sp.endswith(REGIONAL):
                continue
            for one in split_evos(evo.get(sp, '')):
                parts = [x.strip() for x in one.strip('{}').split(',')]
                method, param = parts[0], parts[1]
                target = re.search(r'(SPECIES_\w+)', one).group(1)
                if target in have or target.endswith(REGIONAL) or method not in OK_METHODS:
                    continue
                if any(c in one for c in BAD_CONDITIONS):
                    continue
                if method == 'EVO_ITEM' and param not in items:
                    continue
                if method == 'EVO_TRADE' and 'ITEM_LINKING_CORD' not in items:   # Linking Cord works as a trade
                    continue
                held = re.findall(r'IF_HOLD_ITEM,\s*(ITEM_\w+)', one)
                if any(i not in items for i in held):
                    continue
                have.add(target); changed = True
            for p in pre.get(sp, []):   # breeding
                if p in have or p.endswith(REGIONAL):
                    continue
                if p in incense and incense[p] not in items:
                    continue
                have.add(p); changed = True
    dex = sorted({nat[s] for s in have if s in nat and not s.endswith(REGIONAL)},
                 key=lambda x: x)
    with open('src/data/sfr_obtainable_species.h', 'w') as f:
        f.write('// Generated by tools/sfr/gen_obtainable_species.py: every species obtainable in Super Fire Red.\n')
        f.write('static const u16 sSfrObtainableDex[] =\n{\n')
        for d in dex:
            f.write(f'    {d},\n')
        f.write('};\n')
    print(len(dex), 'obtainable species;', len(items), 'obtainable items')


if __name__ == '__main__':
    main()
