#pragma once
#include "CPoint.h"

class CCSprite
{
public:
	CCSprite(void);
	virtual ~CCSprite(void);

	//����
	CCPoint positon;
	//����
	char *texture;
};

