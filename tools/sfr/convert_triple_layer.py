#!/usr/bin/env python3
"""Super Fire Red: convert every tileset's metatiles.bin to triple-layer metatiles
(12 tile entries = bottom, middle, top), as used by the Hoenn FR Style tilesets (Jaizu).

A dual-layer metatile (8 entries: layer A, layer B) is rewritten by its layer type so it
draws exactly as before:
  NORMAL  (0): bottom = empty, middle = A, top = B
  COVERED (1): bottom = A,     middle = B, top = empty
  SPLIT   (2): bottom = A,     middle = empty, top = B
Files already in triple-layer format are left alone. Safe to run again.
Usage (repo root): python3 tools/sfr/convert_triple_layer.py
"""
import os, struct

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
EMPTY = [0, 0, 0, 0]

done = 0
for root, _, files in os.walk('data/tilesets'):
    if 'metatiles.bin' not in files or 'metatile_attributes.bin' not in files:
        continue
    mt = open(os.path.join(root, 'metatiles.bin'), 'rb').read()
    at = open(os.path.join(root, 'metatile_attributes.bin'), 'rb').read()
    frlg = root.endswith('_frlg') or '_frlg/' in root
    asize = 4 if frlg else 2
    n = len(at) // asize
    if n == 0 or len(mt) == n * 24:
        continue
    if len(mt) != n * 16:
        raise SystemExit('%s: %d bytes for %d metatiles' % (root, len(mt), n))
    out = bytearray()
    for i in range(n):
        e = list(struct.unpack('<8H', mt[i * 16:i * 16 + 16]))
        a = struct.unpack('<I' if frlg else '<H', at[i * asize:i * asize + asize])[0]
        layer = (a >> 29) & 3 if frlg else (a >> 12) & 0xF
        A, B = e[:4], e[4:]
        if layer == 1:
            t = A + B + EMPTY
        elif layer == 2:
            t = A + EMPTY + B
        else:
            t = EMPTY + A + B
        out += struct.pack('<12H', *t)
    open(os.path.join(root, 'metatiles.bin'), 'wb').write(out)
    done += 1
    print('converted', root)
print(done, 'tilesets converted')
