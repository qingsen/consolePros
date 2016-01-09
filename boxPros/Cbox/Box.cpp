// Box.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "windows.h"
#include "conio.h"

char end[]="☆";
char player[]="♀";
char box[]="★";
char flor[]="  ";
char wall[]="■";

int level=0; //第几关
char map[10][10][3];
char remap[10][10][3]; //旧地图用来返回一步

typedef struct
{
	int h;
	int l;
}Position;
Position play[4]; //人物的四个位置，现在，下个，再下个，一个用来返回一步初始化人物位置

typedef struct 
{
	Position pos;
	int endposition[4];  //设置最多四个箱子
	char map_[10][10][3];
}Map;
 Map pass[2]={
	    {{1,1},{37,47,57,57},  {"■","■","■","■","■","  ","  ","  ","  ","  ",
								"■","♀","  ","  ","■","  ","  ","  ","  ","  ",
								"■","  ","★","★","■","■","■","■","■","  ", 
								"■","  ","★","  ","■","■","■","☆","■","  ",
								"■","■","■","  ","■","■","■","☆","■","  ",
								"  ","■","■","  ","  ","  ","  ","☆","■","  ",
								"  ","■","  ","  ","  ","■","  ","  ","■","  ",
								"  ","■","  ","  ","  ","■","■","■","■","  ",
								"  ","■","■","■","■","■","  ","  ","  ","  ",
								"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
								}
		},
		  {{4,2},{52,53,62,63},{"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
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
		   }
			};

 void judge(int i,int j);   //人下个位置响应判断
 void intokey();   //按键输入事件 
 void printfmap();  //打印地 图
 void mapinit();  //每关地图初始化
 void nowendposition();   //判断人是不是在结束位置
 int gamewin();   //游戏过关判断
 void exchangeemap(char a[][10][3],char b[][10][3]);  //a地图换成b地图

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{
		int k=1;  //用来跳出下面的while循坏
		mapinit(); //地图初始化
		printfmap();    //打印地图
		while(k)
		{
			intokey();  //按键输入
			printfmap();
			if(gamewin()) //判断游戏是否过关
			{
				printf("YOU WIN");
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
	case 'w':  judge(--play[1].h,play[1].l);break;
	case 's':  judge(++play[1].h,play[1].l);break;
	case 'a':  judge(play[1].h,--play[1].l);break;
	case 'd':  judge(play[1].h,++play[1].l);break;
	case 'b':  mapinit();break;
	case 'r':  exchangeemap(map,remap),play[1]=play[3],play[0]=play[1],play[2]=play[1]; break;
	default:   break;
	}
}

//人下个位置判断
void judge(int i,int j)
{
	exchangeemap(remap,map);//更新旧地图
	play[3]=play[0]; //更新旧地图人的位置
	if (strcmp(map[play[1].h][play[1].l],wall)) //下个位置不是墙
	{
		if (strcmp(map[play[1].h][play[1].l],flor)==0||strcmp(map[play[1].h][play[1].l],end)==0)  //下个位置是地板或结束位置
		{
			strcpy(map[play[1].h][play[1].l],player); //按键响应时，这个位置变成人
			nowendposition();  //判断原本位置是否是结束位，
			play[0]=play[1]; 
			play[2]=play[1];  
			
		}
		else //下个位置是箱子
		{   
			//指向箱子下个位置
			play[2]=play[1];
			play[2].h+=play[1].h-play[0].h;
			play[2].l+=play[1].l-play[0].l;
			if (strcmp(map[play[2].h][play[2].l],wall)&&strcmp(map[play[2].h][play[2].l],box)) //箱子的下个位置既不是墙，也不是箱子
			{
				strcpy(map[play[1].h][play[1].l],player);
				strcpy(map[play[2].h][play[2].l],box);
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
		if (play[0].h*10+play[0].l==pass[level].endposition[i]) //按键未响应时位置是否是结束位
		{
			i=4; //如果是结束位，就结束判断
			strcpy(map[play[0].h][play[0].l],end); //是结束位，原本位就变成结束字符串
		}
		else
		{
			strcpy(map[play[0].h][play[0].l],flor); //不是结束位，原本位就成地板
		}
	}
}

//游戏过关判断
int gamewin()
{  
	int n=0;
	for (int i=0;i<4;i++)
	{
		if (strcmp(map[pass[level].endposition[i]/10][pass[level].endposition[i]%10],box)==0) //判断每个结束位是否被箱子所占
		{
			n++;
		}
	}
	if(n==4) return 1;  //如果都被箱子所占，那么就过关
	else return 0;	
}

//每关地图初始化
void mapinit()
{
	play[1]=pass[level].pos;
	play[2]=play[1];
	play[0]=play[1];
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			strcpy(map[i][j],pass[level].map_[i][j]);
		}
	}
}

//a地图换成b地图
 void exchangeemap(char a[][10][3],char b[][10][3])
 {
	 for (int i=0;i<10;i++)
	 {
		 for (int j=0;j<10;j++)
		 {
			 strcpy(a[i][j],b[i][j]);
		 }
	 }
 }

//打印地 图
void printfmap()
{
	system("CLS");
	for (int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%s",map[i][j]);
		}
		printf("\n");
	}
	printf("This is pass %d\n",level+1);
	printf("Key 'b' to restart\n");
	printf("Key 'r' to return\n");
}