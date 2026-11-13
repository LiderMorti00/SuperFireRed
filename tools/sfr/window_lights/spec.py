# window glass spec: (primary, secondary-or-None for primary palette) -> list
E='gTileset_General'; F='gTileset_General_Frlg'
def r(a,b): return set(range(a,b+1))
SPEC = {
 # primary palettes: (family primary, pal, color) -> exclusions by secondary {sec: set}
 'primary': [
  (E,1,9), (E,1,10), (E,5,9), (E,5,10),
  (F,3,10), (F,3,11),
 ],
 'primary_exclude': {
  'gTileset_Slateport': {0x37a,0x37b,0x37c,0x381,0x382,0x383,0x384,0x385,0x389,0x38a,0x38b,0x38c,0x38d,0x393},
  'gTileset_Mauville': r(0x3bb,0x3ce)|{0x3d4},
  'gTileset_Fallarbor': r(0x353,0x36c),
  'gTileset_BattleFrontierOutsideWest': 'ALL', 'gTileset_BattleFrontierOutsideEast': 'ALL',
  'gTileset_FuchsiaCity': {0x333,0x334,0x335},
  'gTileset_SeviiIslands67': {0x2db,0x2dc,0x2dd},
 },
 # outdoor secondaries that get primary-glass windows
 'families': {
  E: ['gTileset_Petalburg','gTileset_Rustboro','gTileset_Dewford','gTileset_Slateport','gTileset_Mauville','gTileset_Lavaridge','gTileset_Fallarbor','gTileset_Fortree','gTileset_Lilycove','gTileset_Mossdeep','gTileset_Sootopolis','gTileset_EverGrande','gTileset_Pacifidlog'],
  F: ['gTileset_PalletTown','gTileset_ViridianCity','gTileset_PewterCity','gTileset_CeruleanCity','gTileset_VermilionCity','gTileset_CeladonCity','gTileset_LavenderTown','gTileset_SaffronCity','gTileset_FuchsiaCity','gTileset_CinnabarIsland','gTileset_IndigoPlateau','gTileset_SeviiIslands123','gTileset_SeviiIslands45','gTileset_SeviiIslands67'],
 },
 # secondary palettes: sec -> [(pal, color, exclusions)]
 'secondary': {
  'gTileset_Petalburg': [(10,6,set()),(10,7,set()),(11,8,set()),(11,9,set())],
  'gTileset_Rustboro': [(9,9,set()),(9,10,set())],
  'gTileset_Mauville': [(7,15,set())],
  'gTileset_Fallarbor': [(7,9,set()),(7,10,set())],
  'gTileset_Lilycove': [(8,10,set()),(9,9,set()),(9,10,set())],
  'gTileset_Mossdeep': [(8,9,set()),(8,10,set())],
  'gTileset_EverGrande': [(8,9,r(0x213,0x217)),(8,10,r(0x213,0x217))],
  'gTileset_PalletTown': [(p,c,set()) for p in (8,9,10) for c in (8,9,10)],
  'gTileset_PewterCity': [(8,8,set()),(8,9,set()),(8,10,set()),(9,8,set()),(9,9,set()),(9,10,set()),(11,5,set()),(11,6,set()),(11,12,set())],
  'gTileset_VermilionCity': [(9,8,set()),(9,9,set()),(9,14,set())],
  'gTileset_CeladonCity': [(8,5,set()),(8,6,set()),(8,7,set()),(10,10,set()),(10,11,set()),(10,12,set())],
  'gTileset_LavenderTown': [(10,12,set()),(10,13,set()),(10,14,set())],
  'gTileset_SaffronCity': [(9,13,set()),(9,14,set()),(10,13,set()),(10,14,set())],
  'gTileset_FuchsiaCity': [(8,10,set()),(8,11,set()),(8,12,set())],
  'gTileset_CinnabarIsland': [(9,9,set()),(9,10,set())],
  'gTileset_IndigoPlateau': [(10,8,set()),(10,9,set()),(11,8,set()),(11,9,{0x318,0x31b}),(11,13,{0x318,0x31b}),(11,14,set()),(11,15,{0x318,0x31b})],
  'gTileset_SeviiIslands45': [(9,14,set()),(9,15,set())],
 },
}
