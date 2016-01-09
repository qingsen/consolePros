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
	//放在构造函数初始化没数据，因为这只是关卡类，没数据
	intiplayer=player;
	oldmap.changemap(map);
	intimap.changemap(map);

	//显示地图
	showMap();
	while(!gamewin())
	{
		//修改数据
		contrData();
		//显示地图
		showMap();
	}
	printf("YOU WIN");
	Sleep(1500);
}

//显示地图
void Level::showMap()
{
	system("CLS");
	for (int i=0;i<MAP_ROW;i++)
	{
		for (int j=0;j<MAP_COL;j++)
		{		
			if (isPlayer(Point(i,j)))
			{
				printf("%s",player.textrue);//打印任务				
			}
			else if (isEnd(Point(i,j)))
			{
				if (strcmp(map.sMap[i][j]->textrue,box.textrue)==0)//如果结束位为箱子就打印箱子，否则打印终点
				{
					printf("%s",map.sMap[i][j]->textrue);
				} 
				else
				{	
					printf("%s",end[0].textrue);	//打印终点	
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

 //判断该位置是否为玩家
bool Level::isPlayer(Point p)
{
	if (player.p1.isEqual(p))
	{
		return true;
	}
	return false;
}

//判断该位置是否为结束点
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
	if(n==endnumber) return 1;  //如果都被箱子所占，那么就过关
	else return 0;	
}
//操作数据
void Level::contrData()
{

	char input=getch();	
	//键盘输入，控制移动方向
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
	if (strcmp(map.sMap[player.p1.x+x1][player.p1.y+y1]->textrue,wall.textrue))//判断箱子没有撞墙的时候
	{
		if (strcmp(map.sMap[player.p1.x+x1][player.p1.y+y1]->textrue,box.textrue)==0)//当人物下一个位置为箱子的的时候
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
