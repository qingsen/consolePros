#include "stdafx.h"
#include "Level.h"
#include <conio.h>
#include "Point.h"
#include <Windows.h>
#include <string.h>


Level::Level()
{
}
Level::~Level()
{
}

void Level::run()
{
	//���ڹ��캯����ʼ��û���ݣ���Ϊ��ֻ�ǹؿ��࣬û����
	intiplayer=player;
	oldmap.changemap(map);
	intimap.changemap(map);

	//��ʾ��ͼ
	showMap();
	while(!gamewin())
	{
		//�޸�����
		contrData();
		//��ʾ��ͼ
		showMap();
	}
	printf("YOU WIN");
	Sleep(1500);
}

//��ʾ��ͼ
void Level::showMap()
{
	system("CLS");
	for (int i=0;i<MAP_ROW;i++)
	{
		for (int j=0;j<MAP_COL;j++)
		{		
			if (isPlayer(Point(i,j)))
			{
				printf("%s",player.textrue);//��ӡ����				
			}
			else if (isEnd(Point(i,j)))
			{
				if (strcmp(map.sMap[i][j]->textrue,box.textrue)==0)//�������λΪ���Ӿʹ�ӡ���ӣ������ӡ�յ�
				{
					printf("%s",map.sMap[i][j]->textrue);
				} 
				else
				{	
					printf("%s",end[0].textrue);	//��ӡ�յ�	
				}
			}
			else
			{
				printf("%s",map.sMap[i][j]->textrue);
			}			
		}
		printf("\n");
	}	
	printf(" Key 'b' to back\n");
	printf(" Key 'r' to restart");
}

 //�жϸ�λ���Ƿ�Ϊ���
bool Level::isPlayer(Point p)
{
	if (player.p1.isEqual(p))
	{
		return true;
	}
	return false;
}

//�жϸ�λ���Ƿ�Ϊ������
bool Level::isEnd(Point p)
{	
	for (int i=0;i<endnumber;i++)
	{
		if (end[i].p1.isEqual(p))
		{
			return true; 
		}
	}
	return false;
}

bool Level::gamewin()
{
	int n=0;
	for (int i=0;i<endnumber;i++)
	{
		if (strcmp(map.sMap[end[i].p1.x][end[i].p1.y]->textrue,box.textrue)==0)
		{
			n++;
		}
	}
	if(n==endnumber) return 1;  //�������������ռ����ô�͹���
	else return 0;	
}
//��������
void Level::contrData()
{

	char input=getch();	
	//�������룬�����ƶ�����
	switch(input)
	{
	case 'a':case 'A':	getMove(0,-1);break;		
	case 's':case 'S':	getMove(1,0);break;	
	case 'd':case 'D':	getMove(0,1);break;	
	case 'w':case 'W':	getMove(-1,0);break;
	case 'b':case 'B':  player=oldplayer,map.changemap(oldmap);break;
	case 'r':case 'R':  player=intiplayer,map.changemap(intimap);break;
	default: break;
	}		
}

void Level::getMove(int x1,int y1)
{
    oldmap.changemap(map);
	if (strcmp(map.sMap[player.p1.x+x1][player.p1.y+y1]->textrue,wall.textrue))//�ж�����û��ײǽ��ʱ��
	{
		if (strcmp(map.sMap[player.p1.x+x1][player.p1.y+y1]->textrue,box.textrue)==0)//��������һ��λ��Ϊ���ӵĵ�ʱ��
		{	
			if (strcmp(map.sMap[player.p1.x+x1+x1][player.p1.y+y1+y1]->textrue,box.textrue)&&strcmp(map.sMap[player.p1.x+x1+x1][player.p1.y+y1+y1]->textrue,wall.textrue))
			{
				oldplayer=player;
				player.p1.x+=x1;
				player.p1.y+=y1;                                          

				map.sMap[player.p1.x][player.p1.y]->textrue=floor.textrue;
				map.sMap[player.p1.x+x1][player.p1.y+y1]->textrue=box.textrue;
			}
		}
		else
		{	oldplayer=player;			
			player.p1.x+=x1;
			player.p1.y+=y1;
		}
	}
}
