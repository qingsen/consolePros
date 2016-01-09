// Snake1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Mappoint.h"
#include "Sprite.h"
#include "windows.h"
#include "conio.h"
#include "string.h"

char key='s';
char oldkey;
int  snakelength=1;
char slook[]="●";
char flook[]="★";
char wall[]="■";
char flor[]="  ";
char map[10][10][3];
char map1[10][10][3]={  "■","■","■","■","■","■","■","■","■","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",	
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","  ","  ","  ","  ","  ","  ","  ","  ","■",
						"■","■","■","■","■","■","■","■","■","■",
					};

Sprite snakehead(Mappoint(3,3),slook);
Sprite food(Mappoint(5,6),flook);
Sprite snakebody[50];

void intokey(); //按键输入
void judge(int &x,int &y);//按键处理
void snakemove(); //蛇移动处理
void changemap();//修改地图
void printfmap(); //打印地图
bool gameover();//游戏结束判断
bool foodisbody(); //判断随机生成的食物是否在蛇的身上

int _tmain(int argc, _TCHAR* argv[])
{
	snakebody[0]=snakehead;
	while(!gameover())
	{
		changemap();
		printfmap();
		Sleep(600);
		intokey();	
	}
	system("CLS");
	printf(" GAME OVER");
	while(1);
	return 0;
}

//按键输入
void intokey()
{
	key=kbhit()==1?getch():key;
	switch(key)
	{
	case 'w':  judge(--snakehead.position.row,snakehead.position.col);break;
	case 's':  judge(++snakehead.position.row,snakehead.position.col);break;
	case 'a':  judge(snakehead.position.row,--snakehead.position.col);break;
	case 'd':  judge(snakehead.position.row,++snakehead.position.col);break;
	default:   key=oldkey,intokey();break;
	}
}

//按键处理
void judge(int &x,int &y)
{
	  if (strcmp(map[snakehead.position.row][snakehead.position.col],flook)==0)
	  {
		  snakebody[snakelength++]=food;
		  food.setposition();
		  while (foodisbody())
		  {
			  food.setposition();
		  }
		  snakemove();
	  }
	  if (strcmp(map[snakehead.position.row][snakehead.position.col],flor)==0)
	  {
		  snakemove();
	  }
	  if (snakehead.position.row==snakebody[1].position.row&&snakehead.position.col==snakebody[1].position.col)
	  {
		  snakehead=snakebody[0];
		  key=oldkey;
		  intokey();
	  }
	  oldkey=key;
}

//蛇移动处理
void snakemove()
{ 
	if (snakelength>1)
	{
		for (int i=snakelength-1;i>0;i--)
		{
			snakebody[i]=snakebody[i-1];
		}
	}
  snakebody[0]=snakehead;
}

//修改地图
void changemap()
{
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			strcpy(map[i][j],map1[i][j]);
		}
	}
	strcpy(map[food.position.row][food.position.col],flook);
	for (int i=0;i<snakelength;i++)
	{
		strcpy(map[snakebody[i].position.row][snakebody[i].position.col],slook);
	}
}

//打印地图
void printfmap()
{
	system("CLS");
	printf("  Score:%d\n",snakelength-1);
	for (int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%s",map[i][j]);
		}
		printf("\n");
	}
}

//游戏结束判断
bool gameover()
{
	if (strcmp(map[snakehead.position.row][snakehead.position.col],wall)==0||strcmp(map[snakehead.position.row][snakehead.position.col],slook)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断随机生成的食物是否在蛇的身上
bool foodisbody()
{
	if (strcmp(map[food.position.row][food.position.col],slook)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}