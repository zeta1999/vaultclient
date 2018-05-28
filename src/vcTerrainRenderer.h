#ifndef vcTerrainRenderer_h__
#define vcTerrainRenderer_h__

#include "udPlatform/udMath.h"

struct vcQuadTreeNode;
struct vcTerrainRenderer;

void vcTerrainRenderer_Init(vcTerrainRenderer **ppTerrainRenderer);
void vcTerrainRenderer_Destroy(vcTerrainRenderer **ppTerrainRenderer);

void vcTerrainRenderer_BuildTiles(vcTerrainRenderer *pTerrainRenderer, const vcQuadTreeNode *pNodeList, int nodeCount, int leafNodeCount);
void vcTerrainRenderer_Render(vcTerrainRenderer *pTerrainRenderer, const udDouble4x4 &viewProjection);

#endif//vcTerrainRenderer_h__