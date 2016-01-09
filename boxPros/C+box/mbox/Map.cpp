#include "StdAfx.h"
#include "Map.h"
#include "string.h"
#include "windows.h"


Map::Map(void)
{
}

Map::~Map(void)
{ 
}

//打印地图
void Map::printfmap()
{
	extern int level;  //外部变量 关卡
	system("CLS");
	for (int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%s",map_[i][j]);
		}
		printf("\n");
	}
	printf(" This is pass %d\n",level+1);
	printf(" Key 'b' to back\n");
	printf(" Key 'r' to restart\n");
}

//设置地图
void Map::setmap(char a[][10][3])
{
	for(int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			strcpy(map_[i][j],a[i][j]);
		}
	}
}
