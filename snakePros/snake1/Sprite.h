#pragma once
#include "Mappoint.h"
class Sprite
{
 public:
	Sprite(void);
	~Sprite(void);
	Sprite(Mappoint position,char *look);
	void setposition();

	Mappoint position;
	char *look;
};

