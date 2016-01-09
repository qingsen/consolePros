#pragma once
#include "Snake.h"
#include "CMap.h"
#include "Snake.h"
#include "CFood.h"

typedef enum 
{
	GAME_NOR,
	GAME_OVER
}GameStatus;

class GameControl
{
public:
	GameControl(void);
	~GameControl(void);

	GameStatus _status;
	
	//蛇
	Snake *_snake;

	//地图
	CCMap *_map;

	//食物
	CCFood *_food;

	//开始游戏
	void run();

private:

	void init();
	void reset();
	void showMap();
	void handleInput(char c);
	void collisionCheck(CCPoint next);
};

