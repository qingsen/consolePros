#pragma once
#include "Sprite.h"
#include "Global.h"

class Map
{
public:
	Map();
	/*Map(const Map &a);*/
	~Map();	
	void changemap(Map a);
	Sprite *sMap[MAP_ROW][MAP_COL];		
};