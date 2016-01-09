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

	//��ͷ
	SnakeHead *head;
	//����ߵ�����
	vector <CCSprite *> snakeVec;
	//��β
	SnakeTail *tail;

	//����
	Direction _direction;

	//�ƶ�һ��
	void move(Direction dir);

	//��ʳ��
	void eat();

	//����ߵĵ�ǰλ��
	CCPoint getPosition();
	void setPosition(CCPoint pos);

	//�ߵ���һ��λ��
	CCPoint getNextPosition();

	//����ߵ�ĳһ����
	CCSprite *getCompose(CCPoint pos);

	bool isBody(CCPoint pos);
};

