#!/usr/bin/env python3
# Usage: python3 -I tools/sfr/extract_oras_wild.py <altissimo1.github.io checkout> tools/sfr/data/oras_wild.json
# Extracts ORAS wild encounter data (Altissimo1 site) into one JSON file.
import json, glob, os, re, sys
ALT = sys.argv[1]; OUT = sys.argv[2]
def load(f):
    s = open(f).read(); s = s[s.index('{'):].rstrip().rstrip(';'); return json.loads(s)
areas = {}
for f in sorted(glob.glob(os.path.join(ALT, 'Main-Series/javascript/ORAS/*.js'))):
    key = os.path.basename(f)[:-3]
    d = load(f); e = d['encounters']; out = {}
    for k, v in e.items():
        if isinstance(v, dict):
            for kk, vv in v.items(): out[kk] = vv
        else:
            out['walking' if k == 'tall_grass' and 'walking' not in e else k] = v
    for k in out:
        out[k] = [{'rate': x['rate'], 'options': [{'name': o['name'], 'level': o['level'], 'games': o['games']} for o in x['options']]} for x in out[k]]
    areas[key] = out
# DexNav lists from the HTML pages
dexnav = {}
for f in sorted(glob.glob(os.path.join(ALT, 'Main-Series/Hoenn-Locations/*.html'))):
    s = open(f).read()
    if 'id="pokemon-oras"' not in s: continue
    i = s.index('id="pokemon-oras"'); j = s.find('id="pokemon-oras-items"', i)
    t = s[i:j]; base = os.path.basename(f)[:-5]; cur = base
    for m in re.finditer(r'data-location-id="([^"]+)"|<h4>([^<]*)</h4>', t):
        if m.group(1): cur = m.group(1); continue
        if not m.group(2).startswith('DexNav'): continue
        k = t.find('<table', m.end()); e = t.find('</table>', k); tab = t[k:e]
        for row in re.findall(r'<tr[^>]*>(.*?)</tr>', tab, re.S):
            cells = [re.sub(r'<[^>]+>', '', c).strip() for c in re.findall(r'<td[^>]*>(.*?)</td>', row, re.S)]
            cells = [c for c in cells if c]
            if len(cells) >= 2 and re.match(r'^[\d\-–, ]+$', cells[-1]):
                dexnav.setdefault(cur, []).append({'name': cells[-2], 'level': cells[-1]})
json.dump({'areas': areas, 'dexnav': dexnav}, open(OUT, 'w'), indent=1, ensure_ascii=False)
print(len(areas), 'areas;', len(dexnav), 'dexnav lists')
