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
	//��ʼ��
	init();

	while(1)
	{
		if (GAME_OVER == _status)
		{
			printf("GameOver! press any key to continue");
			getch();
			//���¿�ʼ��Ϸ
			reset();
		}
		//��ⰴ���¼�
		if (kbhit())
		{
			//�а���
			char input = getch();
			//�޸�����
			handleInput(input);
		}
		else
		{
			//��ײ���
			CCPoint next = _snake->getNextPosition();
			collisionCheck(next);

			//��ǰ��һ��
			_snake->move(_snake->_direction);

			//��ʾ��ͼ
			showMap(); 
			Sleep(500);
		}

// 		//��ʾ��ͼ
// 		showMap(); 
// 		Sleep(500);
// 		//�ж���Ϸ�Ƿ����
// 		if (GAME_OVER == _status)
// 		{
// 			printf("GameOver! press any key to continue");
// 			getch();
// 			//���¿�ʼ��Ϸ
// 			reset();
// 		}
// 		else
// 		{
// 			//��ⰴ���¼�
// 			if (kbhit())
// 			{
// 				tempDir = _snake->_direction;
// 				//�а���
// 				char input = getch();
// 				//�޸�����
// 				handleInput(input);
// 			}
// 
// 			//��ײ���
// 			CCPoint next = _snake->getNextPosition();
// 			collisionCheck(next);
// 
// 			//��ǰ��һ��
// 			_snake->move(_snake->_direction);
// 		}
 	}
}



void GameControl::init()
{
	//��ʼ����Ϸ״̬
	_status = GAME_NOR;

	//��ʼ����ͼ
	if (NULL == _map)
	{
		_map = new CCMap;
	}
	
	//��
	if (NULL == _snake)
	{
		_snake = new Snake;
	}
	
	//ʳ��
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
	//��ӡ��ͼ
	for (int i = 0; i < MAP_ROW; i ++)
	{
		for (int j = 0; j < MAP_COL; j ++)
		{
			//�жϵ�ǰλ���Ƿ�����
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
	//��ӡ��

	//��ӡʳ��
}

void GameControl::handleInput(char c)
{
	switch(c)
	{
	case 'a':
		//������������ö�
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

	//��Ϸ״̬
	_status = GAME_NOR;

	//��
	if (_snake)
	{
		delete(_snake);
		_snake = NULL;
	}
	_snake = new Snake;
	_snake->setPosition(CCPoint(5,5));

	//ʳ��
	_food->positon = CCPoint::randPoint(MAP_ROW,MAP_COL);
}

void GameControl::collisionCheck(CCPoint next)
{
	if (_food->isFood(next))
	{
		//����ʳ��
		_snake->eat();

		//�޸�ʳ�������
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