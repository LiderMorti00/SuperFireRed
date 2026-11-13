import re,os,struct
from PIL import Image, ImageDraw
ROOT=os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','..','..')+'/'
H=open(ROOT+'src/data/tilesets/headers.h').read()
G=open(ROOT+'src/data/tilesets/graphics.h').read()+open(ROOT+'src/graphics.c').read()
M=open(ROOT+'src/data/tilesets/metatiles.h').read()
def info(sym):
    m=re.search(r'const struct Tileset %s =\s*\{(.*?)\};'%sym,H,re.S)
    b=m.group(1)
    g=lambda k:re.search(r'\.%s = (\w+)'%k,b).group(1)
    tiles=re.search(r'%s\[\] = INC\w+\("([^"]+)"'%g('tiles'),G).group(1)
    pm=re.search(r'%s\[\]\[16\] =\s*\{(.*?)\};'%g('palettes'),G,re.S).group(1)
    pals=re.findall(r'"([^"]+)\.pal"',pm) or re.findall(r'"([^"]+)\.gbapal"',pm)
    meta=re.search(r'%s\[\] = INCBIN_U16\("([^"]+)"'%g('metatiles'),M).group(1)
    attr=re.search(r'%s\[\] = INCBIN_\w+\("([^"]+)"'%g('metatileAttributes'),M).group(1)
    return dict(tiles=ROOT+tiles, pals=[ROOT+p+'.pal' for p in pals], meta=ROOT+meta, attr=ROOT+attr, dir=os.path.dirname(ROOT+meta), secondary='TRUE' in re.search(r'\.isSecondary = (\w+)',b).group(1))
def readpal(p):
    if not os.path.exists(p): return [(0,0,0)]*16
    L=open(p).read().split('\n')[3:19]
    return [tuple(int(x) for x in l.split()) for l in L if l.strip()]
def loadtiles(path):
    im=Image.open(path); px=im.load(); w,h=im.size
    return [[[px[tx*8+x,ty*8+y]&15 for x in range(8)] for y in range(8)] for ty in range(h//8) for tx in range(w//8)]
class Pair:
    def __init__(s,prim,sec):
        s.P=info(prim); s.S=info(sec)
        s.frlg='Frlg' in prim
        s.np=640 if s.frlg else 512; s.npal=7 if s.frlg else 6
        s.pt=loadtiles(s.P['tiles']); s.st=loadtiles(s.S['tiles'])
        pp=[readpal(p) for p in s.P['pals']]; sp=[readpal(p) for p in s.S['pals']]
        s.palsrc=[('P',i) if i<s.npal else ('S',i) for i in range(16)]
        s.pal=[(pp[i] if i<s.npal else sp[i]) if i<len(pp) and i<len(sp) else [(0,0,0)]*16 for i in range(16)]
        s.pm=open(s.P['meta'],'rb').read(); s.sm=open(s.S['meta'],'rb').read()
        s.per=24
        s.nsec=len(s.sm)//24
    def entries(s,m):
        data,i=(s.pm,m) if m<s.np else (s.sm,m-s.np)
        return struct.unpack_from('<12H',data,i*24)
    def tile(s,n):
        if n<s.np: return s.pt[n] if n<len(s.pt) else [[0]*8]*8
        n-=s.np; return s.st[n] if n<len(s.st) else [[0]*8]*8
    def metatile(s,m,mark=None):
        e=s.entries(m)
        img=Image.new('RGB',(16,16),s.pal[0][0]); px=img.load()
        for layer in range(3):
            for k in range(4):
                v=e[layer*4+k]; t=s.tile(v&0x3ff); pi=(v>>12)&15; pal=s.pal[pi]
                for y in range(8):
                    for x in range(8):
                        c=t[7-y if v&0x800 else y][7-x if v&0x400 else x]
                        if c==0: continue
                        col=pal[c]
                        if mark and (pi,c) in mark: col=(255,0,255)
                        px[(k%2)*8+x,(k//2)*8+y]=col
        return img
    def sheet(s,start,count,scale=2,mark=None,cols=16):
        rows=(count+cols-1)//cols
        img=Image.new('RGB',(cols*(16*scale+2)+40,rows*(16*scale+2)),(255,255,255)); d=ImageDraw.Draw(img)
        for i in range(count):
            m=start+i
            x=40+(i%cols)*(16*scale+2); y=(i//cols)*(16*scale+2)
            img.paste(s.metatile(m,mark).resize((16*scale,16*scale),Image.NEAREST),(x,y))
            if i%cols==0: d.text((0,y+8),'%03x'%m,fill=(0,0,0))
        return img
