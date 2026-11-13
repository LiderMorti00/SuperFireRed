# Super Emerald: night window lights. Marks window glass colours as lights (.pla next to the
# tileset palette) and, where a glass colour is shared with non-window tiles, copies it to a
# free palette slot and repaints only the window tiles. One-shot: run once on clean tilesets.
# Usage: python3 tools/sfr/window_lights/apply.py [--dry]
import sys,json,struct,collections,os
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
from tslib import info, readpal, ROOT
from spec import SPEC
from PIL import Image
DRY='--dry' in sys.argv
L=json.load(open(ROOT+'data/layouts/layouts.json'))['layouts']
fam=collections.defaultdict(set)
for l in L:
    if 'primary_tileset' in l and l['secondary_tileset'] not in ('0',0,None): fam[l['primary_tileset']].add(l['secondary_tileset'])
class TS:
    def __init__(s,sym):
        s.sym=sym; s.i=info(sym)
        s.img=Image.open(s.i['tiles']); s.px=s.img.load(); s.w=s.img.size[0]//8
        s.meta=open(s.i['meta'],'rb').read(); s.n=len(s.meta)//24
        s.dirty=False
    def entries(s,i): return struct.unpack_from('<12H',s.meta,i*24)
    def pix(s,t,x,y): return s.px[(t%s.w)*8+x,(t//s.w)*8+y]&15
    def setpix(s,t,x,y,v):
        old=s.px[(t%s.w)*8+x,(t//s.w)*8+y]; s.px[(t%s.w)*8+x,(t//s.w)*8+y]=(old&~15)|v; s.dirty=True
cache={}
def ts(sym):
    if sym not in cache: cache[sym]=TS(sym)
    return cache[sym]
def npfor(prim): return (640,7) if 'Frlg' in prim else (512,6)
def palfile(prim,sec,pi):
    np_,npal=npfor(prim)
    return (ts(prim) if pi<npal else ts(sec)).i['pals'][pi]+'' if False else (info(prim)['pals'][pi] if pi<npal else info(sec)['pals'][pi])
def tileref(prim,sec,v):
    np_,npal=npfor(prim); n=v&0x3ff
    return (ts(prim),n) if n<np_ else (ts(sec),n-np_)
def uses(prim,sec,pi,ci,include_primary):
    """metatiles (as ('P'|sec, id)) whose entries reference palette pi and contain color ci"""
    out=[]
    np_,_=npfor(prim)
    lists=[]
    if include_primary: lists.append(('P',ts(prim),0))
    if sec: lists.append((sec,ts(sec),np_))
    for tag,T,off in lists:
        for i in range(T.n):
            hit=False
            for v in T.entries(i):
                if (v>>12)&15!=pi: continue
                tt,n=tileref(prim,sec or prim,v)
                if n>=tt.img.size[0]//8*(tt.img.size[1]//8): continue
                if any(tt.pix(n,x,y)==ci for y in range(8) for x in range(8)): hit=True;break
            if hit: out.append((tag,i+off))
    return out
def used_indices(prim,secs,pi):
    used=set()
    np_,_=npfor(prim)
    for tag,T in [('P',ts(prim))]+[(s,ts(s)) for s in secs]:
        for i in range(T.n):
            for v in T.entries(i):
                if (v>>12)&15!=pi: continue
                tt,n=tileref(prim,tag if tag!='P' else next(iter(secs)),v)
                if n>=tt.img.size[0]//8*(tt.img.size[1]//8): continue
                for y in range(8):
                    for x in range(8): used.add(tt.pix(n,x,y))
    return used
report=[]
plas=collections.defaultdict(set)   # palfile -> indices
paledits={}                          # palfile -> {idx: rgb}
def do(prim,pi,ci,windows_by_sec,conflict_secs,secs_all):
    """windows_by_sec: {sec or 'P': set of metatile ids}; if nothing to exclude -> direct"""
    pf=palfile(prim,secs_all[0],pi)
    if not conflict_secs:
        plas[pf].add(ci); report.append(('direct',os.path.basename(os.path.dirname(os.path.dirname(pf))),pi,ci)); return
    used=used_indices(prim,secs_all,pi) if pi<npfor(prim)[1] else used_indices(prim,secs_all,pi)
    pal=readpal(pf)
    taken=used|set(paledits.get(pf,{}))|plas[pf]|{0}
    free=[i for i in range(1,16) if i not in taken]
    if not free:
        report.append(('NOFREE',pf,pi,ci)); return
    f=free[0]
    paledits.setdefault(pf,{})[f]=pal[ci]; plas[pf].add(f)
    # recolor tiles of window metatiles
    np_,npal=npfor(prim)
    done=set(); n_t=0
    for sec,ms in windows_by_sec.items():
        T=ts(prim) if sec=='P' else ts(sec)
        off=0 if sec=='P' else np_
        for m in ms:
            for v in T.entries(m-off):
                if (v>>12)&15!=pi: continue
                tt,n=tileref(prim, sec if sec!='P' else secs_all[0], v)
                key=(tt.sym,n)
                if key in done: continue
                done.add(key)
                for y in range(8):
                    for x in range(8):
                        if tt.pix(n,x,y)==ci: tt.setpix(n,x,y,f)
                n_t+=1
    report.append(('dup',os.path.basename(os.path.dirname(os.path.dirname(pf))),pi,ci,'->',f,'tiles',n_t))
# --- primary items
for prim,pi,ci in SPEC['primary']:
    secs=[s for s in SPEC['families'][prim]]
    allsecs=sorted(fam[prim])
    excl=SPEC['primary_exclude']
    # conflicts: excluded uses, or uses in non-family secondaries
    windows={}; conflict=[]
    pu=uses(prim,None,pi,ci,True)
    windows['P']={m for _,m in pu}
    for s in allsecs:
        u={m for t,m in uses(prim,s,pi,ci,False)}
        if not u: continue
        if s not in secs: conflict.append(s); continue
        ex=excl.get(s,set())
        if ex=='ALL': conflict.append(s); continue
        if u&ex: conflict.append(s)
        windows[s]=u-ex
    # primary glass colours are marked directly: the conflicting uses are indoor maps, caves,
    # the Battle Frontier glass walls or the Battle Tent awnings (no free primary colour left)
    do(prim,pi,ci,windows,[],allsecs if allsecs else secs)
    print(prim,pi,ci,'conflicts',conflict)
# --- secondary items
for sec,items in SPEC['secondary'].items():
    prim='gTileset_General_Frlg' if sec in SPEC['families']['gTileset_General_Frlg'] else 'gTileset_General'
    for pi,ci,ex in items:
        u={m for t,m in uses(prim,sec,pi,ci,False)}
        do(prim,pi,ci,{sec:u-ex},[sec] if u&ex else [],[sec])
for r_ in report: print(r_)
if DRY: sys.exit()
for pf,ix in plas.items():
    pla=pf[:-4]+'.pla'
    old=set()
    if os.path.exists(pla): old={int(l) for l in open(pla) if l.strip() and not l.startswith('#')}
    open(pla,'w').write('# Window glass lit at night\n'+''.join('%d\n'%i for i in sorted(ix|old)))
    os.utime(pf,None)
for pf,ed in paledits.items():
    pal=readpal(pf)
    for i,c in ed.items(): pal[i]=c
    open(pf,'w').write('JASC-PAL\r\n0100\r\n16\r\n'+''.join('%d %d %d\r\n'%c for c in pal))
for T in cache.values():
    if T.dirty: T.img.save(T.i['tiles'])
print('written')
