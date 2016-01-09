#include "GameControl.h"
#include "Windows.h"
#include "conio.h"


GameControl::GameControl(void)
{
	_map = NULL;
	_food = NULL;
	_snake = NULL;
}


GameControl::~GameControl(void)
{
	if (NULL != _map)
	{
		delete(_map);
		_map = NULL;
	}
	
	if (NULL != _snake)
	{
		delete(_snake);
		_snake = NULL;
	}

	if (NULL != _food)
	{
		delete(_food);
		_food = NULL;
	}

}

void GameControl::run()
{
	//初始化
	init();

	while(1)
	{
		if (GAME_OVER == _status)
		{
			printf("GameOver! press any key to continue");
			getch();
			//重新开始游戏
			reset();
		}
		//检测按键事件
		if (kbhit())
		{
			//有按键
			char input = getch();
			//修改数据
			handleInput(input);
		}
		else
		{
			//碰撞检测
			CCPoint next = _snake->getNextPosition();
			collisionCheck(next);

			//蛇前进一步
			_snake->move(_snake->_direction);

			//显示地图
			showMap(); 
			Sleep(500);
		}

// 		//显示地图
// 		showMap(); 
// 		Sleep(500);
// 		//判断游戏是否结束
// 		if (GAME_OVER == _status)
// 		{
// 			printf("GameOver! press any key to continue");
// 			getch();
// 			//重新开始游戏
// 			reset();
// 		}
// 		else
// 		{
// 			//检测按键事件
// 			if (kbhit())
// 			{
// 				tempDir = _snake->_direction;
// 				//有按键
// 				char input = getch();
// 				//修改数据
// 				handleInput(input);
// 			}
// 
// 			//碰撞检测
// 			CCPoint next = _snake->getNextPosition();
// 			collisionCheck(next);
// 
// 			//蛇前进一步
// 			_snake->move(_snake->_direction);
// 		}
 	}
}



void GameControl::init()
{
	//初始化游戏状态
	_status = GAME_NOR;

	//初始化地图
	if (NULL == _map)
	{
		_map = new CCMap;
	}
	
	//蛇
	if (NULL == _snake)
	{
		_snake = new Snake;
	}
	
	//食物
	if (NULL == _food)
	{ 
		_food = new CCFood;
		//_food->positon = CCPoint::randPoint(MAP_ROW,MAP_COL);
		_food->positon = CCPoint(1,5);
	}
}

void GameControl::showMap()
{
	system("CLS");
	//打印地图
	for (int i = 0; i < MAP_ROW; i ++)
	{
		for (int j = 0; j < MAP_COL; j ++)
		{
			//判断当前位置是否是蛇
			CCSprite *spr = _snake->getCompose(CCPoint(i,j));
			if (spr)
			{
				printf("%s",spr->texture);
			}
			else if (_food->isFood(CCPoint(i,j)))
			{
				printf("%s",_food->texture);
			}
			else
			{
				printf("%s",_map->mapData[i][j]->texture);
			}
		}
		printf("\n");
	}
	//打印蛇

	//打印食物
}

void GameControl::handleInput(char c)
{
	switch(c)
	{
	case 'a':
		//如果反方向则不让动
		if (_snake->_direction != RIGHT)
		{
			_snake->_direction = LEFT;
		}
		break;
	case 's':
		if (_snake->_direction != UP)
		{
			_snake->_direction = DOWN;
		}
		break;
	case 'w':
		if (_snake->_direction != DOWN)
		{
			_snake->_direction = UP;
		}
		break;
	case 'd':
		if (_snake->_direction != LEFT)
		{
			_snake->_direction = RIGHT;
		}
		break;
	}
}

void GameControl::reset()
{

	//游戏状态
	_status = GAME_NOR;

	//蛇
	if (_snake)
	{
		delete(_snake);
		_snake = NULL;
	}
	_snake = new Snake;
	_snake->setPosition(CCPoint(5,5));

	//食物
	_food->positon = CCPoint::randPoint(MAP_ROW,MAP_COL);
}

void GameControl::collisionCheck(CCPoint next)
{
	if (_food->isFood(next))
	{
		//碰到食物
		_snake->eat();

		//修改食物的坐标
		_food->positon = CCPoint::randPoint(MAP_ROW,MAP_COL);
	}
	else if (_map->isWall(next))
	{
		_status = GAME_OVER;
	}
	else if (_snake->isBody(next))
	{
		_status = GAME_OVER;
	}
}