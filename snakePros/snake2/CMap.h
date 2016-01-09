#pragma once

#include "CSprite.h"
#include "Global.h"


class CCMap
{
public:
	CCMap(void);
	~CCMap(void);

	CCSprite *mapData[MAP_ROW][MAP_COL];

	bool isWall(CCPoint pos);
};

