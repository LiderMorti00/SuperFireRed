#ifndef GUARD_REGIONS_H
#define GUARD_REGIONS_H

#include "global.h"
#include "constants/regions.h"

enum KantoSubRegion GetKantoSubregion(u32 mapSecId);

static inline enum Region GetRegionForSectionId(u32 sectionId)
{
    if (sectionId >= KANTO_MAPSEC_START && sectionId < MAPSEC_SPECIAL_AREA)
        return REGION_KANTO;
    return REGION_HOENN;
}

static inline enum Region GetCurrentRegion(void)
{
    return GetRegionForSectionId(gMapHeader.regionMapSectionId);
}

// Super Fire Red: Kanto and Hoenn share one build, so things that used to depend
// on IS_FRLG now check where the player is (or which tileset style the map uses).
static inline bool32 IsInKanto(void)
{
    return GetCurrentRegion() == REGION_KANTO;
}

#define IS_FRLG_MAP_LAYOUT (gMapHeader.mapLayout->isFrlg)

#endif // GUARD_REGIONS_H
