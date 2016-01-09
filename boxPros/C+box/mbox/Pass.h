#pragma once
#include "position.h"
#include "Map.h"
class Pass :
	public Map
{
public:
	Pass(void);
	Pass(Position pos,int endposition[4],char tu[10][10][3]);//每关数据初始化
	~Pass(void);

	Position pos;
	int endposition[4];
};

