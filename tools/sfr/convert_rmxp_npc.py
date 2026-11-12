#!/usr/bin/env python3
"""Super Emerald: converts an RPG Maker XP character sheet (4x4 frames of 32x48 drawn at
2x: rows down, left, right, up) into a GBA overworld sheet of 9 frames of 16x32
(face down, face up, face left, walk down x2, walk up x2, walk left x2) with its own
16-colour palette (index 0 transparent).

Usage: convert_rmxp_npc.py <in.png> <out.png> <out.pal>
"""
import sys
from collections import Counter
from PIL import Image


def main(src, out_png, out_pal):
    im = Image.open(src).convert('RGBA')
    small = im.resize((im.width // 2, im.height // 2), Image.NEAREST)  # 2x drawn
    fw, fh = 16, 24
    def frame(row, col):
        return small.crop((col * fw, row * fh, col * fw + fw, row * fh + fh))
    order = [(0, 0), (3, 0), (1, 0), (0, 1), (0, 3), (3, 1), (3, 3), (1, 1), (1, 3)]
    sheet = Image.new('RGBA', (16 * len(order), 32), (0, 0, 0, 0))
    for i, (r, c) in enumerate(order):
        sheet.paste(frame(r, c), (i * 16, 32 - fh))
    px = [p for p in sheet.getdata() if p[3] >= 128]
    colors = [c for c, _ in Counter(p[:3] for p in px).most_common()]
    if len(colors) > 15:
        q = Image.new('RGB', (len(px), 1)); q.putdata([p[:3] for p in px])
        q = q.quantize(15, method=Image.MEDIANCUT)
        pal = q.getpalette()[:45]
        colors = [tuple(pal[i:i + 3]) for i in range(0, 45, 3)]
    def nearest(c):
        return min(range(len(colors)), key=lambda i: sum((a - b) ** 2 for a, b in zip(c, colors[i])))
    out = Image.new('P', sheet.size, 0)
    full = [(255, 0, 255)] + colors + [(0, 0, 0)] * (15 - len(colors))
    out.putpalette(sum(full, ()))
    cache = {}
    data = []
    for p in sheet.getdata():
        if p[3] < 128:
            data.append(0)
        else:
            if p[:3] not in cache:
                cache[p[:3]] = 1 + nearest(p[:3])
            data.append(cache[p[:3]])
    out.putdata(data)
    out.save(out_png, transparency=0)
    with open(out_pal, 'w', newline='\r\n') as f:
        f.write('JASC-PAL\n0100\n16\n')
        for r, g, b in full:
            f.write(f'{r} {g} {b}\n')
    print(out_png, len(colors), 'colours')


if __name__ == '__main__':
    main(*sys.argv[1:4])
