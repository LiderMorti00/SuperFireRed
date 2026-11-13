#!/usr/bin/env python3
"""Super Emerald: 16x16 (1x1) door animations for the Hoenn FR-style doors.

Each animation is built from the door's own closed metatile: the door swings
inwards like FireRed's doors (hinge on the right), over the dark interior used
by graphics/door_anims/littleroot.png. Output: 16x48 indexed PNGs (3 frames)
whose colour indices point into the door's tileset palette.

Usage: python3 tools/sfr/gen_door_anims_1x1.py
"""
import os
import struct
from PIL import Image

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..')
TS_DIR = os.path.join(ROOT, 'data', 'tilesets')
NUM_PRIMARY_METATILES = 0x200
NUM_PRIMARY_TILES = 512
NUM_PALS_IN_PRIMARY = 6

# (secondary tileset, metatile id, output png, palette slot)
DOORS = [
    ('mauville', 0x2AC, 'mauville', 7),
    ('mauville', 0x3A1, 'verdanturf', 5),
    ('mauville', 0x289, 'cycling_road', 7),
    ('rustboro', 0x22F, 'rustboro_tan', 11),
    ('rustboro', 0x21F, 'rustboro_gray', 10),
    ('lilycove', 0x246, 'lilycove', 8),
    ('lilycove', 0x28E, 'lilycove_wooden', 5),
    ('mossdeep', 0x2A1, 'mossdeep', 1),
    ('sootopolis', 0x21C, 'sootopolis_peaked_roof', 6),
    ('sootopolis', 0x21E, 'sootopolis', 6),
    ('dewford', 0x225, 'dewford', 5),
    ('fallarbor', 0x2A5, 'fallarbor_light_roof', 7),
    ('fallarbor', 0x2F7, 'fallarbor_dark_roof', 7),
    ('pacifidlog', 0x21A, 'pacifidlog', 9),
]

# Fully open door (frame 3 of littleroot.png), rows 0-13, columns 1-14.
# e = dark interior, b = floor, d = floor edge
OPEN = [
    'eeeeeeeeeeeeee',
    'eeeeeeeeeeeeee',
    'eeeeeedddddddd',
    'eeeeedbbbbbbbb',
    'eeeeedbbbbbbbb',
    'eeeedbbbbbbbbb',
    'eeeedbbbbbbbbb',
    'eeedbbbbbbbbbb',
    'eeedbbbbbbbbbb',
    'eedbbbbbbbbbbb',
    'eedbbbbbbbbbbb',
    'edbbbbbbbbbbbb',
    'eddddddddddddd',
    'eeeeeeeeeeeeee',
]
FLOOR = (120, 120, 128)
EDGE = (88, 88, 112)


def read_pal(path):
    lines = open(path).read().split('\n')[3:19]
    return [tuple(int(x) for x in l.split()) for l in lines if l.strip()]


def load_tiles(path):
    im = Image.open(path)
    px = im.load()
    w, h = im.size
    return [[[px[tx * 8 + x, ty * 8 + y] & 15 for x in range(8)] for y in range(8)]
            for ty in range(h // 8) for tx in range(w // 8)]


def palettes(sec):
    pals = []
    for i in range(16):
        d = 'primary/general' if i < NUM_PALS_IN_PRIMARY else 'secondary/' + sec
        pals.append(read_pal(os.path.join(TS_DIR, d, 'palettes', '%02d.pal' % i)))
    return pals


def closed_door(sec, metatile):
    pt = load_tiles(os.path.join(TS_DIR, 'primary/general/tiles.png'))
    st = load_tiles(os.path.join(TS_DIR, 'secondary', sec, 'tiles.png'))
    pals = palettes(sec)
    data = open(os.path.join(TS_DIR, 'secondary', sec, 'metatiles.bin'), 'rb').read()
    entries = struct.unpack_from('<12H', data, (metatile - NUM_PRIMARY_METATILES) * 24)
    img = [[None] * 16 for _ in range(16)]
    for layer in range(3):
        for k in range(4):
            v = entries[layer * 4 + k]
            n = v & 0x3FF
            tile = pt[n] if n < NUM_PRIMARY_TILES else st[n - NUM_PRIMARY_TILES]
            pal = pals[(v >> 12) & 15]
            for y in range(8):
                for x in range(8):
                    c = tile[7 - y if v & 0x800 else y][7 - x if v & 0x400 else x]
                    if c == 0:
                        continue
                    img[(k // 2) * 8 + y][(k % 2) * 8 + x] = pal[c]
    return img, pals


def nearest(pal, rgb):
    best = min(range(1, 16), key=lambda i: sum((a - b) ** 2 for a, b in zip(pal[i], rgb)))
    return best


def grayish(pal, rgb, fallback):
    # Interior colours must stay neutral: a pink or green 'floor' looks wrong
    def chroma(c):
        return max(c) - min(c)
    cands = [i for i in range(1, 16) if chroma(pal[i]) <= 40]
    if not cands:
        return fallback
    best = min(cands, key=lambda i: sum((a - b) ** 2 for a, b in zip(pal[i], rgb)))
    if sum((a - b) ** 2 for a, b in zip(pal[best], rgb)) > 60 ** 2:
        return fallback
    return best


def build(sec, metatile, slot):
    rgb, pals = closed_door(sec, metatile)
    pal = pals[slot]
    closed = [[nearest(pal, c) if c else 1 for c in row] for row in rgb]
    dark = closed[0][0]
    role = {'e': dark, 'b': grayish(pal, FLOOR, dark), 'd': grayish(pal, EDGE, dark)}
    frames = []
    for panel_w, panel_h in ((9, 13), (5, 12), (0, 0)):
        f = [row[:] for row in closed]
        for y in range(14):
            for x in range(14):
                f[y][x + 1] = role[OPEN[y][x]]
        if panel_w:
            for y in range(panel_h):
                for x in range(panel_w):
                    sx = 1 + (x * 14) // panel_w
                    f[y][15 - panel_w + x] = closed[y][sx]
        frames.append(f)
    out = Image.new('P', (16, 48))
    flat = []
    for c in pal:
        flat += list(c)
    out.putpalette(flat + [0] * (768 - len(flat)))
    px = out.load()
    for i, f in enumerate(frames):
        for y in range(16):
            for x in range(16):
                px[x, i * 16 + y] = f[y][x]
    return out


def main():
    for sec, metatile, name, slot in DOORS:
        build(sec, metatile, slot).save(os.path.join(ROOT, 'graphics', 'door_anims', name + '.png'))
        print('graphics/door_anims/%s.png' % name)


if __name__ == '__main__':
    main()
