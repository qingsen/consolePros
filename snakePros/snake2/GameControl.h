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
	
	//��
	Snake *_snake;

	//��ͼ
	CCMap *_map;

	//ʳ��
	CCFood *_food;

	//��ʼ��Ϸ
	void run();

private:

	void init();
	void reset();
	void showMap();
	void handleInput(char c);
	void collisionCheck(CCPoint next);
};

