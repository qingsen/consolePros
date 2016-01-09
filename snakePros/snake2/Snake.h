#pragma once
#include "SnakeHead.h"
#include "SnakeTail.h"
#include "SnakeBody.h"
#include "CSprite.h"

#include <vector>
using namespace std;

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}Direction;

class Snake
{
public:
	Snake(void);
	~Snake(void);

	//蛇头
	SnakeHead *head;
	//存放蛇的容器
	vector <CCSprite *> snakeVec;
	//蛇尾
	SnakeTail *tail;

	//方向
	Direction _direction;

	//移动一格
	void move(Direction dir);

	//吃食物
	void eat();

	//获得蛇的当前位置
	CCPoint getPosition();
	void setPosition(CCPoint pos);

	//蛇的下一个位置
	CCPoint getNextPosition();

	//获得蛇的某一部分
	CCSprite *getCompose(CCPoint pos);

	bool isBody(CCPoint pos);
};

