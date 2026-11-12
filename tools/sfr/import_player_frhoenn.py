#!/usr/bin/env python3
"""Import the FireRed-style Brendan/May player sheets from the FRHoenn pack.

Usage: import_player_frhoenn.py <FRHoenn/PLAYER/E dir>

Every sheet of one character is indexed against a single shared palette,
written to graphics/object_events/palettes/{brendan,may}.pal, so the player,
the rival and every riding/surfing/fishing state use the same colors.
Surfing and watering are remapped from the pack's FRLG frame layout to the
6-frame Emerald layout the pic tables expect.
"""
import sys
from collections import Counter
from pathlib import Path
from PIL import Image

ROOT = Path(__file__).resolve().parents[2]
PICS = ROOT / "graphics/object_events/pics/people"
PALS = ROOT / "graphics/object_events/palettes"

# pack file -> list of (target png, frame width, frame remap or None)
SETS = {
    "brendan": {
        "100": [("walking", 16, list(range(0, 9))), ("running", 16, list(range(9, 18)))],
        "101": [("mach_bike", 32, None)],
        "102": [("acro_bike", 32, None)],
        "103": [("surfing", 32, [0, 9, 1, 10, 2, 11])],
        "104": [("field_move", 32, None)],
        "137": [("fishing", 32, None)],
        "191": [("watering", 32, [0, 3, 1, 5, 2, 7])],
        "193": [("decorating", 16, None)],
    },
    "may": {
        "105": [("walking", 32, list(range(0, 9))), ("running", 32, list(range(9, 18)))],
        "106": [("mach_bike", 32, None)],
        "107": [("acro_bike", 32, None)],
        "108": [("surfing", 32, [0, 9, 1, 10, 2, 11])],
        "109": [("field_move", 32, None)],
        "138": [("fishing", 32, None)],
        "192": [("watering", 32, [0, 3, 1, 5, 2, 7])],
        "194": [("decorating", 16, None)],
    },
}


def nearest(c, pal):
    return min(range(len(pal)), key=lambda i: sum((a - b) ** 2 for a, b in zip(c, pal[i])))


def main(src):
    src = Path(src)
    for who, files in SETS.items():
        imgs = {f: Image.open(src / f"{f}.png").convert("RGB") for f in files}
        bg = next(iter(imgs.values())).getpixel((0, 0))
        count = Counter()
        for im in imgs.values():
            count.update(px for px in im.getdata() if px != bg)
        colors = [c for c, _ in count.most_common(15)]
        pal = [bg] + colors
        while len(pal) < 16:
            pal.append((0, 0, 0))
        lut = {}
        flat = sum(pal, ())
        for f, outs in files.items():
            im = imgs[f]
            idx = Image.new("P", im.size)
            idx.putpalette(flat)
            data = []
            for px in im.getdata():
                if px == bg:
                    data.append(0)
                else:
                    if px not in lut:
                        lut[px] = 1 + nearest(px, colors)
                    data.append(lut[px])
            idx.putdata(data)
            for name, fw, remap in outs:
                frames = [idx.crop((i * fw, 0, i * fw + fw, 32)) for i in range(idx.width // fw)]
                if remap is not None:
                    frames = [frames[i] for i in remap]
                out = Image.new("P", (fw * len(frames), 32))
                out.putpalette(flat)
                for i, fr in enumerate(frames):
                    out.paste(fr, (i * fw, 0))
                out.save(PICS / who / f"{name}.png", transparency=0)
        with open(PALS / f"{who}.pal", "w", newline="\r\n") as fh:
            fh.write("JASC-PAL\n0100\n16\n")
            for r, g, b in pal:
                fh.write(f"{r} {g} {b}\n")
        print(who, "palette:", pal)


if __name__ == "__main__":
    main(sys.argv[1])
