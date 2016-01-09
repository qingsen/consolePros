#pragma once
#include "CPoint.h"

class CCSprite
{
public:
	CCSprite(void);
	virtual ~CCSprite(void);

	//×ø±ê
	CCPoint positon;
	//ÎÆÀí
	char *texture;
};

