#!/usr/bin/env python3
"""Super Fire Red: turn a picture saved by MS Paint (24-bit RGB) back into the indexed
16-color PNG the decomp needs, using the palette of the original file.

Usage (repo root):
  python3 tools/sfr/paint_to_indexed.py EDITED.png ORIGINAL.png [OUTPUT.png]
  python3 tools/sfr/paint_to_indexed.py EDITED.png PALETTE.pal  OUTPUT.png

ORIGINAL.png is the indexed PNG you started from (its palette and colour order are kept);
OUTPUT defaults to ORIGINAL.png, so the file is replaced in place.
Pixels with the palette's colour 0, or magenta (255,0,255), become transparent (index 0).
Colours that are not in the palette are matched to the nearest one and reported, so you
can fix them in Paint if the match is wrong.
"""
import sys
from PIL import Image


def read_pal(path):
    lines = open(path).read().split('\n')
    return [tuple(map(int, l.split())) for l in lines[3:3 + int(lines[2])] if l.strip()]


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    edited, ref = sys.argv[1], sys.argv[2]
    if ref.endswith('.pal'):
        if len(sys.argv) < 4:
            sys.exit('With a .pal file, give an OUTPUT.png too.')
        pal = read_pal(ref)
        out_path = sys.argv[3]
    else:
        img = Image.open(ref)
        if img.mode != 'P':
            sys.exit('%s is not an indexed PNG; give the original indexed file or a .pal' % ref)
        raw = img.getpalette()[:48]
        pal = [tuple(raw[i:i + 3]) for i in range(0, 48, 3)]
        out_path = sys.argv[3] if len(sys.argv) > 3 else ref
    pal = (pal + [(0, 0, 0)] * 16)[:16]
    src = Image.open(edited).convert('RGB')
    out = Image.new('P', src.size, 0)
    out.putpalette([v for c in pal for v in c] + [0] * (768 - 48))
    exact = {c: i for i, c in reversed(list(enumerate(pal)))}
    unknown = {}
    px, opx = src.load(), out.load()
    for y in range(src.height):
        for x in range(src.width):
            c = px[x, y]
            if c == (255, 0, 255) or c == pal[0]:
                continue
            if c in exact:
                opx[x, y] = exact[c]
                continue
            i = min(range(1, 16), key=lambda k: sum((a - b) ** 2 for a, b in zip(pal[k], c)))
            opx[x, y] = i
            unknown.setdefault(c, [i, 0])[1] += 1
    out.save(out_path)
    print('Saved %s (%dx%d)' % (out_path, src.width, src.height))
    for c, (i, n) in sorted(unknown.items(), key=lambda kv: -kv[1][1]):
        print('  colour %s is not in the palette: %d pixel(s) -> index %d %s' % (c, n, i, pal[i]))


if __name__ == '__main__':
    main()
