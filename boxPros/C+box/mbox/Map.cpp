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

//��ӡ��ͼ
void Map::printfmap()
{
	extern int level;  //�ⲿ���� �ؿ�
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

//���õ�ͼ
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
