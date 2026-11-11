#!/usr/bin/env python3
"""Super Fire Red: Brendan's five battles (Route 103, 110, 119, Lilycove, Victory Road).

Brendan has the starter that is neither the player's nor May's. Teams are based on the
ORAS rival battles (Route 119 and Lilycove lineups). The trainer suffix is the player's starter.
Victory Road reuses the TRAINER_BRENDAN_RUSTBORO_* slots.
"""
import re, sys

LINES = {  # Brendan's starter line when the player chose ...
    'TREECKO': ('Mudkip', 'Marshtomp', 'Swampert', 'Swampertite', ['Breloom', 'Magcargo'], 'Wailord'),
    'TORCHIC': ('Treecko', 'Grovyle', 'Sceptile', 'Sceptilite', ['Magcargo', 'Wailord'], 'Breloom'),
    'MUDKIP':  ('Torchic', 'Combusken', 'Blaziken', 'Blazikenite', ['Wailord', 'Breloom'], 'Magcargo'),
}
IV = 'IVs: 31 HP / 31 Atk / 31 Def / 31 SpA / 31 SpD / 31 Spe'

def mon(species, level, item=None, extra=''):
    head = species + (' @ ' + item if item else '')
    return '%s\nLevel: %d\n%s%s' % (head, level, IV, extra)

def trainer(tid, mons, items=None):
    out = '=== TRAINER_%s ===\nName: BRENDAN\nClass: Rival\nPic: Brendan\nGender: Male\nMusic: Male\n' % tid
    if items:
        out += 'Items: ' + items + '\n'
    out += 'Double Battle: No\nAI: Smart Trainer\n\n'
    return out + '\n\n'.join(mons) + '\n'

def build():
    t = {}
    for suf, (base, mid, final, stone, pair, third) in LINES.items():
        t['BRENDAN_ROUTE_103_' + suf] = trainer('BRENDAN_ROUTE_103_' + suf, [mon(base, 46)])
        t['BRENDAN_ROUTE_110_' + suf] = trainer('BRENDAN_ROUTE_110_' + suf,
            [mon(pair[0], 50), mon(pair[1], 50), mon(mid, 52)])
        t['BRENDAN_ROUTE_119_' + suf] = trainer('BRENDAN_ROUTE_119_' + suf,
            [mon('Swellow', 55), mon(pair[0], 55), mon(pair[1], 55), mon(final, 57)],
            'Hyper Potion / Hyper Potion')
        t['BRENDAN_LILYCOVE_' + suf] = trainer('BRENDAN_LILYCOVE_' + suf,
            [mon('Swellow', 60), mon(pair[0], 60), mon(pair[1], 60), mon(third, 60), mon(final, 62, 'Sitrus Berry')],
            'Full Restore / Full Restore')
        t['BRENDAN_RUSTBORO_' + suf] = trainer('BRENDAN_RUSTBORO_' + suf,
            [mon('Swellow', 68, 'Flame Orb', '\nAbility: Guts'), mon(pair[0], 68, 'Leftovers'),
             mon(pair[1], 68, 'Leftovers'), mon(third, 68, 'Sitrus Berry'), mon('Ludicolo', 69, 'Life Orb'),
             mon(final, 70, stone)],
            'Full Restore / Full Restore / Full Restore')
    return t

def main(path):
    s = open(path).read()
    for tid, block in build().items():
        m = re.search(r'^=== TRAINER_%s ===\n.*?(?=^/\*|^===)' % tid, s, re.S | re.M)
        if not m:
            sys.exit('missing ' + tid)
        s = s[:m.start()] + block + '\n' + s[m.end():]
    open(path, 'w').write(s)

if __name__ == '__main__':
    main(sys.argv[1] if len(sys.argv) > 1 else 'src/data/trainers.party')
