#include "Snake.h"


Snake::Snake(void)
{
	_direction = RIGHT;

	//头
	head = new SnakeHead();
	snakeVec.push_back(head);
	head->positon = CCPoint(1,1);

	//尾巴
	tail = new SnakeTail();
	snakeVec.push_back(tail);
}


Snake::~Snake(void)
{
	if (NULL != head)
	{
		delete(head);
		head = NULL;
	}
	if (NULL != tail)
	{
		delete(tail);
		head = NULL;
	}
}


CCPoint Snake::getNextPosition()
{
	CCPoint temp = head->positon;
	switch(_direction)
	{
	case UP:
		{
			temp.x --;
		}break;
	case DOWN: 
		{
			temp.x ++;
		} break;
	case LEFT:
		{
			temp.y --;
		}break;
	case RIGHT:
		{
			temp.y ++;
		}break;
	}
	return temp;
}

void Snake::move(Direction dir)
{
	vector <CCSprite *>::iterator iter;
	for (iter = snakeVec.end() - 1; iter != snakeVec.begin(); iter --)
	{
		CCSprite *spr = *iter;
		CCSprite *befor = *(iter-1);
		spr->positon = befor->positon;
	}

	//处理头
	head->positon = getNextPosition();
}

CCSprite *Snake::getCompose(CCPoint pos)
{
	vector <CCSprite *>::iterator iter;
	for (iter = snakeVec.begin(); iter != snakeVec.end() ; iter ++)
	{
		CCSprite *spr = *iter;
		if (pos.isEqual(spr->positon))
		{
			return spr;
		}
	}
	return NULL;
}

void Snake::eat()
{
	//创建一个身体
	SnakeBody *body = new SnakeBody;
	body->positon = tail->positon;

	//添加到容器
	snakeVec.insert(snakeVec.end()-1,body);
}

void Snake::setPosition(CCPoint pos)
{
	head->positon = pos;
}

bool Snake::isBody(CCPoint pos)
{
	for (int i = 0; i < snakeVec.size(); i ++)
	{
		if (pos.isEqual(snakeVec[i]->positon))
		{
			return true;
		}
	}
	return false;
}