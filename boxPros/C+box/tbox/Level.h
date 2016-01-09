#pragma once
#include "Map.h"
#include "Player.h"
#include "Box.h"
#include "End.h"
#include "Wall.h"
#include "Floor.h"
#include "Sprite.h"

class Level
{
public:
	Level();
	~Level();

	//地图
	Map map,oldmap,intimap;
	Box box;
	int endnumber;
	//玩家
	Player player,oldplayer,intiplayer;
	//目的地
	End end[3];
	//	墙
	Wall wall;
	//空地
	Floor floor;
	
	//运行
	void run();
	//人物和箱子移动状态
	void getMove(int x1,int y1);
	//判断某个位置是否是玩家
	bool isPlayer(Point p);
	//判断某个位置是结束点
	bool isEnd(Point p);
	bool gamewin();


private:
	//显示地图
	void showMap();
	//修改数据
	void contrData();
};