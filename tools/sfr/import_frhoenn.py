#!/usr/bin/env python3
"""Super Fire Red: import the "FRHoenn" pack (Hoenn overworld sprites redrawn in FireRed
style, PokeCommunity thread 436714) over Emerald's NPC sprites.

Usage (repo root):  python3 -I tools/sfr/import_frhoenn.py /path/to/unzipped/FRHoenn

Pack files are named by vanilla Emerald OBJ_EVENT_GFX number (NPC/<n>.png, PLAYER/E/<n>.png).
For each one:
  * frames are split (16 or 32 px cells), the ones the game uses are picked (9-frame walkers,
    3-frame standing NPCs, 4-frame nurse with her bow) and cropped to 16 px wide; sprites
    drawn wider than 16 px keep 32x32 frames and their graphics info is switched to 32x32;
  * colors go to the shared Emerald NPC palette that fits best (paletteTag updated); a
    sprite that fits none of them well gets its own palette (graphics/object_events/
    palettes/sfr_hoenn/<name>.pal, tag OBJ_EVENT_PAL_TAG_SFR_<NAME>).
Variants marked (R), (FR) and the Rayquaza sheet are skipped. C changes are written between
"Super Fire Red: FRHoenn" markers so the tool can be run again.
"""
import os, re, sys
import numpy as np
from PIL import Image

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
os.chdir(ROOT)
PACK = sys.argv[1]
MAX_SHARED_ERROR = 12.0
W = np.array([3, 4, 2], float)
TAG_BASE = 0x1180

EVOBJ = 'include/constants/event_objects.h'
INFO = 'src/data/object_events/object_event_graphics_info.h'
PICS = 'src/data/object_events/object_event_pic_tables.h'
GFX = 'src/data/object_events/object_event_graphics.h'
MOVE = 'src/event_object_movement.c'

s = open(EVOBJ).read()
body = s[s.index('enum\n{'):]
IDS = re.findall(r'OBJ_EVENT_GFX_(\w+)', body[:body.index('};')])
ptr = open('src/data/object_events/object_event_graphics_info_pointers.h').read()
info = open(INFO).read()
pics = open(PICS).read()
gfx = open(GFX).read()
move = open(MOVE).read()

SHARED = {}
for n in (1, 2, 3, 4):
    SHARED['OBJ_EVENT_PAL_TAG_NPC_%d' % n] = 'graphics/object_events/palettes/npc_%d.pal' % n


def read_pal(p):
    return [tuple(map(int, l.split())) for l in open(p).read().split('\n')[3:19] if l.strip()]


def write_pal(p, cols):
    os.makedirs(os.path.dirname(p), exist_ok=True)
    with open(p, 'w', newline='\r\n') as f:
        f.write('JASC-PAL\n0100\n16\n')
        for c in cols:
            f.write('%d %d %d\n' % tuple(int(v) for v in c))


def info_of(name):
    m = re.search(r'\[OBJ_EVENT_GFX_%s\]\s*=\s*&(\w+)' % name, ptr)
    gi = m.group(1)
    b = re.search(r'const struct ObjectEventGraphicsInfo %s = \{(.*?)\n\};' % gi, info, re.S).group(1)
    tab = re.search(r'\.images = (\w+)', b).group(1)
    t = re.search(r'%s\[\] = \{(.*?)\};' % tab, pics, re.S).group(1)
    pic = re.search(r'(gObjectEventPic_\w+)', t).group(1)
    w = int(re.search(r'\.width = (\d+)', b).group(1))
    h = int(re.search(r'\.height = (\d+)', b).group(1))
    tag = re.search(r'\.paletteTag = (\w+)', b).group(1)
    return gi, tab, pic, w, h, tag


def pic_paths(pic):
    m = re.search(r'%s\[\] = INC(?:GFX|BIN)_U(?:32|16)\(([^;]+)\);' % pic, gfx)
    return [p.replace('.4bpp', '.png') for p in re.findall(r'"(graphics/[^"]+\.(?:png|4bpp))"', m.group(1))]


def split_frames(img, bg):
    wdt = img.width
    def content_width(cw):
        worst = 0
        for i in range(wdt // cw):
            xs = [x for x in range(cw) for y in range(img.height) if img.getpixel((i * cw + x, y)) != bg]
            if xs:
                worst = max(worst, max(xs) - min(xs) + 1)
        return worst
    if wdt % 32 == 0 and wdt // 32 in (9, 10, 18, 20) and content_width(32) <= 20:
        cw = 32
    else:
        cw = 16
    return [img.crop((i * cw, 0, i * cw + cw, img.height)) for i in range(wdt // cw)], cw


def hist_of(frames, bg):
    h = {}
    for f in frames:
        for cnt, c in f.getcolors(100000):
            if c != bg:
                h[c] = h.get(c, 0) + cnt
    return h


def pal_error(h, pal):
    c = np.array(list(h), float); w = np.array(list(h.values()), float)
    p = np.array(pal[1:], float)
    d = (((c[:, None, :] - p[None]) ** 2) * W).sum(-1).min(1)
    return (np.sqrt(d) * w).sum() / w.sum()


def kmeans_pal(h, k=15):
    cols = np.array(list(h), float); wts = np.sqrt(np.array(list(h.values()), float))
    if len(cols) <= k:
        cent = cols
    else:
        order = np.argsort(-wts)
        cent = cols[order[:k]].copy()
        for _ in range(30):
            a = (((cols[:, None, :] - cent[None]) ** 2) * W).sum(-1).argmin(1)
            for j in range(k):
                m = a == j
                if m.any():
                    cent[j] = (cols[m] * wts[m, None]).sum(0) / wts[m].sum()
    cent = [tuple(int(round(v)) for v in c) for c in cent]
    cent.sort(key=lambda c: -(c[0] * 3 + c[1] * 4 + c[2] * 2))
    return [(0, 0, 0)] + cent + [(0, 0, 0)] * (15 - len(cent))


def to_indexed(frames, pal, bg, fw, fh):
    out = Image.new('P', (fw * len(frames), fh), 0)
    out.putpalette([v for c in pal for v in c] + [0] * (768 - 48))
    p = np.array(pal[1:], float)
    for i, f in enumerate(frames):
        x0 = (f.width - fw) // 2
        y0 = f.height - fh
        for y in range(fh):
            for x in range(fw):
                c = f.getpixel((x0 + x, y0 + y))
                if c == bg:
                    continue
                d = (((np.array(c, float) - p) ** 2) * W).sum(-1)
                out.putpixel((i * fw + x, y), int(d.argmin()) + 1)
    return out


def pick(frames, n_target):
    if n_target in (9, 18) and len(frames) >= n_target:
        return frames[:n_target]
    if n_target == 3:
        return frames[:3]
    if n_target == 4:
        return frames[:3] + [frames[9] if len(frames) > 9 else frames[0]]
    raise ValueError('frames %d -> %d' % (len(frames), n_target))


jobs = []
for sub in ('NPC', 'PLAYER/E'):
    d = os.path.join(PACK, sub)
    for fn in sorted(os.listdir(d)):
        base = fn[:-4]
        if not base.isdigit():
            continue
        n = int(base)
        name = IDS[n]
        if sub == 'PLAYER/E':
            if name not in ('RIVAL_BRENDAN_NORMAL', 'RIVAL_MAY_NORMAL'):
                continue
        if name == 'RAYQUAZA_STILL':
            continue
        jobs.append((name, os.path.join(d, fn)))

new_tags = []
info_edits = {}   # info symbol -> dict(field -> value)
pic_wide = set()
report = []
for name, path in jobs:
    gi, tab, pic, ow, oh, tag = info_of(name)
    img = Image.open(path).convert('RGB')
    bg = img.getpixel((0, 0))
    frames, cw = split_frames(img, bg)
    paths = pic_paths(pic)
    # number of frames the game sheet(s) hold
    sizes = [Image.open(p).size for p in paths]
    n_target = sum(sz[0] // ow for sz in sizes)
    chosen = pick(frames, n_target)
    hist = hist_of(chosen, bg)
    # wide sprites keep 32x32 frames
    fw = ow
    if cw == 32 and ow == 16:
        xs = [x for f in chosen for x in range(32) for y in range(f.height) if f.getpixel((x, y)) != bg]
        if min(xs) < 8 or max(xs) > 23:
            fw = 32
            pic_wide.add(pic)
            info_edits.setdefault(gi, {}).update({'size': '512', 'width': '32', 'height': '32',
                                                 'oam': '&gObjectEventBaseOam_32x32', 'subspriteTables': 'sOamTables_32x32'})
    fh = 32 if fw == 32 else oh
    errs = {t: pal_error(hist, read_pal(p)) for t, p in SHARED.items()}
    best = min(errs, key=errs.get)
    if errs[best] <= MAX_SHARED_ERROR and name not in ('RIVAL_BRENDAN_NORMAL', 'RIVAL_MAY_NORMAL'):
        pal = read_pal(SHARED[best]); newtag = best
    else:
        pal = kmeans_pal(hist)
        newtag = 'OBJ_EVENT_PAL_TAG_SFR_' + name
        write_pal('graphics/object_events/palettes/sfr_hoenn/%s.pal' % name.lower(), pal)
        new_tags.append((newtag, name))
    if newtag != tag:
        info_edits.setdefault(gi, {})['paletteTag'] = newtag
    # write the sheet(s): frames are spread over the pic's files in order
    k = 0
    for p, sz in zip(paths, sizes):
        cnt = sz[0] // ow
        out = to_indexed(chosen[k:k + cnt], pal, bg, fw, fh)
        out.save(p)
        k += cnt
    report.append('%-22s %2d frames %dx%d  %s (%.1f)' % (name, n_target, fw, fh, newtag.replace('OBJ_EVENT_PAL_TAG_', ''), errs[best]))

# ---- C changes ----
def strip_block(text):
    return re.sub(r'// Super Fire Red: FRHoenn begin.*?// Super Fire Red: FRHoenn end\n', '', text, flags=re.S)

# palette tags
ev = strip_block(open(EVOBJ).read())
defs = ''.join('#define %-40s 0x%04X\n' % (t, TAG_BASE + i) for i, (t, _) in enumerate(new_tags))
ev = ev.replace('#define OBJ_EVENT_PAL_TAG_NONE ', '// Super Fire Red: FRHoenn begin\n' + defs + '// Super Fire Red: FRHoenn end\n#define OBJ_EVENT_PAL_TAG_NONE ', 1)
open(EVOBJ, 'w').write(ev)

g = strip_block(open(GFX).read())
g += '// Super Fire Red: FRHoenn begin\n' + ''.join(
    'const u16 gObjectEventPal_Sfr%s[] = INCGFX_U16("graphics/object_events/palettes/sfr_hoenn/%s.pal", ".gbapal");\n'
    % (n.title().replace('_', ''), n.lower()) for _, n in new_tags) + '// Super Fire Red: FRHoenn end\n'
for pic in pic_wide:
    g = re.sub(r'(%s\[\] = INCGFX_U32\("[^"]+", "\.4bpp", )"-mwidth 2 -mheight 4"' % pic, r'\1"-mwidth 4 -mheight 4"', g)
open(GFX, 'w').write(g)

mv = strip_block(open(MOVE).read())
entries = ''.join('    {gObjectEventPal_Sfr%s, %s},\n' % (n.title().replace('_', ''), t) for t, n in new_tags)
anchor = '    {gObjectEventPal_Npc1,                  OBJ_EVENT_PAL_TAG_NPC_1},\n'
mv = mv.replace(anchor, '// Super Fire Red: FRHoenn begin\n' + entries + '// Super Fire Red: FRHoenn end\n' + anchor, 1)
open(MOVE, 'w').write(mv)

inf = open(INFO).read()
for gi, edits in info_edits.items():
    m = re.search(r'(const struct ObjectEventGraphicsInfo %s = \{)(.*?)(\n\};)' % gi, inf, re.S)
    b = m.group(2)
    for field, val in edits.items():
        b = re.sub(r'(\.%s = )[^,]+,' % field, r'\g<1>%s,' % val, b)
    inf = inf[:m.start(2)] + b + inf[m.end(2):]
open(INFO, 'w').write(inf)

# sheets built by spritesheet_rules.mk (Brendan/May) get the matching tile width
rules = open('spritesheet_rules.mk').read()
for pic in pic_wide:
    for p in pic_paths(pic):
        p4 = p.replace('graphics/object_events/pics/', '$(OBJEVENTGFXDIR)/').replace('.png', '.4bpp')
        rules = re.sub(r'(%s: %%\.4bpp: %%\.png\n\t\$\(GFX\) \$< \$@ )-mwidth 2 -mheight 4' % re.escape(p4), r'\g<1>-mwidth 4 -mheight 4', rules)
open('spritesheet_rules.mk', 'w').write(rules)

pt = open(PICS).read()
for pic in pic_wide:
    pt = re.sub(r'(overworld_(?:frame|ascending_frames)\(%s, )2, 4' % pic, r'\g<1>4, 4', pt)
open(PICS, 'w').write(pt)

print('\n'.join(report))
print('%d sprites, %d own palettes, %d drawn 32 px wide' % (len(report), len(new_tags), len(pic_wide)))
