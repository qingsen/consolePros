#include "StdAfx.h"
#include "Sprite.h"
#include "time.h"
#include "stdlib.h"
#include "windows.h"


Sprite::Sprite(void)
{
}
Sprite::Sprite(Mappoint position,char *look)
{
	this->position=position;
	this->look=look;
}

Sprite::~Sprite(void)
{
}
void Sprite::setposition()
{
	srand((int)time(NULL));
	position.row=rand()%8+1;
	position.col=rand()%8+1;
}
