// classBox.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Look.h"
#include "Map.h"
#include "Pass.h"
#include "Position.h"
#include "windows.h"
#include "conio.h"

Look end("☆");
Look player="♀";
Look box="★";
Look flor="  ";
Look wall="■";

int level=0; //第几关
Map map[2];  //map[0]当前地图，map[1]返回地图

Position play[4]; //人物的四个位置，现在，下个，再下个，一个用来返回一步初始化人物位置

Position pos[2]={Position(1,1),Position(4,2)};
int endposition[2][4]={{37,47,57,57},{52,53,62,63}};
char passmap[2][10][10][3]={
				{"■","■","■","■","■","  ","  ","  ","  ","  ",
				"■","♀","  ","  ","■","  ","  ","  ","  ","  ",
				"■","  ","★","★","■","■","■","■","■","  ", 
				"■","  ","★","  ","■","■","■","☆","■","  ",
				"■","■","■","  ","■","■","■","☆","■","  ",
				"  ","■","■","  ","  ","  ","  ","☆","■","  ",
				"  ","■","  ","  ","  ","■","  ","  ","■","  ",
				"  ","■","  ","  ","  ","■","■","■","■","  ",
				"  ","■","■","■","■","■","  ","  ","  ","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
			    },
				{"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				"  ","■","■","■","■","■","■","■","  ","  ",
				"  ","■","  ","  ","  ","  ","  ","■","■","■",
				"■","■","★","■","■","■","  ","  ","  ","■",
				"■","  ","♀","  ","★","  ","  ","★","  ","■",
				"■","  ","☆","☆","■","  ","★","  ","■","■",
				"■","■","☆","☆","■","  ","  ","  ","■","  ",
				"  ","■","■","■","■","■","■","■","■","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				}
						   };

Pass pass[2]={Pass(pos[0],endposition[0],passmap[0]),Pass(pos[1],endposition[1],passmap[1])};//关卡内容初始化

void judge(int &i,int &j);   //人下个位置响应判断
void intokey();   //按键输入事件 
void mapinit(int level);  //每关地图初始化
void nowendposition();   //判断人是不是在结束位置
int gamewin();   //游戏过关判断

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{
		int k=1;  //用来跳出下面的while循坏
		mapinit(level); //地图初始化
		pass[level].printfmap(); //打印第几关的初始地图
		while(k)
		{
			intokey();  //按键输入
			map[0].printfmap();
			if(gamewin()) //判断游戏是否过关
			{
				system("CLS");
				printf(" YOU WIN\n");
				printf(" Prepare for the next pass");
				Sleep(2000);
				k=0;
				level++;
				if (level>1)
				{
					level=0;
				}
			}
		}
	}
	return 0;
}

//按键输入事件
void intokey()
{
	char key=getch();
	//按键判断
	switch(key)
	{
	case 'w':  judge(--play[1].row,play[1].col);break;
	case 's':  judge(++play[1].row,play[1].col);break;
	case 'a':  judge(play[1].row,--play[1].col);break;
	case 'd':  judge(play[1].row,++play[1].col);break;
	case 'r':  mapinit(level);break;  //重新开始
	case 'b':  map[0]=map[1],play[1]=play[3],play[0]=play[1],play[2]=play[1]; break;//返回一步
	default:   break;
	}
}

//人下个位置响应判断
void judge(int &i,int &j)
{
	map[1]=map[0];  //更新旧地图
	play[3]=play[0]; //更新旧地图人的位置
	if (strcmp(map[0].map_[play[1].row][play[1].col],wall.look)) //下个位置不是墙
	{
		if (strcmp(map[0].map_[play[1].row][play[1].col],flor.look)==0||strcmp(map[0].map_[play[1].row][play[1].col],end.look)==0)  //下个位置是地板或结束位置
		{ 
			strcpy(map[0].map_[play[1].row][play[1].col],player.look); //按键响应时，这个位置变成人
			nowendposition();  //判断原本位置是否是结束位，
			play[0]=play[1]; 
			play[2]=play[1];  

		}
		else //下个位置是箱子
		{   
			//指向箱子下个位置
			play[2]=play[1];
			play[2].row+=play[1].row-play[0].row;
			play[2].col+=play[1].col-play[0].col;
			if (strcmp(map[0].map_[play[2].row][play[2].col],wall.look)&&strcmp(map[0].map_[play[2].row][play[2].col],box.look)) //箱子的下个位置既不是墙，也不是箱子
			{
				strcpy(map[0].map_[play[1].row][play[1].col],player.look);
				strcpy(map[0].map_[play[2].row][play[2].col],box.look);
				nowendposition();
				play[0]=play[1];
				play[2]=play[1];
			}
			else
			{
				play[1]=play[0];
				play[2]=play[0];
			}
		}
	}
	else
	{
		play[1]=play[0];
	}
}

//判断人是不是在结束位置
void nowendposition()
{
	for (int i=0;i<4;i++)
	{
		if (play[0].row*10+play[0].col==pass[level].endposition[i]) //按键未响应时位置是否是结束位
		{
			i=5; //如果是结束位，就结束判断
			strcpy(map[0].map_[play[0].row][play[0].col],end.look); //是结束位，原本位就变成结束字符串
		}
		else
		{
			strcpy(map[0].map_[play[0].row][play[0].col],flor.look); //不是结束位，原本位就成地板
		}
	}
}

//游戏过关判断
int gamewin()
{  
	int n=0;
	for (int i=0;i<4;i++)
	{
		if (strcmp(map[0].map_[pass[level].endposition[i]/10][pass[level].endposition[i]%10],box.look)==0) //判断每个结束位是否被箱子所占
		{
			n++;
		}
	}
	if(n==4) return 1;  //如果都被箱子所占，那么就过关
	else return 0;	
}

//每关地图初始化
void mapinit(int level)
{
	play[1]=pass[level].pos;
	play[2]=play[1];
	play[0]=play[1];
	map[0].setmap(pass[level].map_);
}
