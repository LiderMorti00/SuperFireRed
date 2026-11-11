#!/usr/bin/env python3
# Extracts ORAS trainers (Altissimo1 site) into one JSON file.
# Usage: python3 -I tools/sfr/extract_oras_trainers.py <altissimo1.github.io checkout> tools/sfr/data/oras_trainers.json
import json, glob, os, re, sys
from html import unescape
ALT, OUT = sys.argv[1], sys.argv[2]
res = {}
for f in sorted(glob.glob(os.path.join(ALT, 'Main-Series/Hoenn-Locations/*.html'))):
    s = open(f).read()
    if 'id="pokemon-oras-trainers"' not in s: continue
    i = s.index('id="pokemon-oras-trainers"')
    j = s.find('id="pokemon-rse', i)
    if j < 0: j = len(s)
    t = s[i:j]
    rows = []
    for tab in re.finditer(r'<table[^>]*>(.*?)</table>', t, re.S):
        cap = re.search(r'<caption>(.*?)</caption>', tab.group(1), re.S)
        cap = unescape(re.sub(r'<[^>]+>', '', cap.group(1))) if cap else ''
        for row in re.findall(r'<tr[^>]*>(.*?)</tr>', tab.group(1), re.S):
            cells = re.findall(r'<td[^>]*>(.*?)</td>', row, re.S)
            if len(cells) < 2: continue
            name = unescape(re.sub(r'<[^>]+>', '', cells[0])).strip()
            party = []
            for line in re.split(r'<br\s*/?>', cells[1]):
                line = unescape(re.sub(r'<[^>]+>', '', line)).strip()
                m = re.match(r'(.+?)\s+lv\.\s*(\d+)', line)
                if m: party.append([m.group(1).strip(), int(m.group(2))])
            notes = unescape(re.sub(r'<[^>]+>', ' ', cells[2])).strip() if len(cells) > 2 else ''
            if party:
                rows.append({'trainer': name, 'party': party, 'notes': re.sub(r'\s+', ' ', notes), 'table': cap})
    res[os.path.basename(f)[:-5]] = rows
json.dump(res, open(OUT, 'w'), indent=1, ensure_ascii=False)
print(sum(len(v) for v in res.values()), 'rows')
