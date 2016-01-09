#pragma once
#include "csprite.h"
class CCFood :
	public CCSprite
{
public:
	CCFood(void);
	~CCFood(void);

	bool isFood(CCPoint pos);
};

