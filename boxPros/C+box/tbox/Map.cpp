#include "stdafx.h"
#include "Map.h"
#include "stdlib.h"
#include "string.h"

Map::Map()
{	
	for (int i=0;i<MAP_ROW;i++)
	{
		for (int j=0;j<MAP_COL;j++)
		{
			sMap[i][j]=(Sprite *)malloc(sizeof(Sprite));
		}
	}
}
Map::~Map()
{

}
//Map::Map(const Map &a)
//{
//	for (int i=0;i<MAP_ROW;i++)
//	{
//		for (int j=0;j<MAP_COL;j++)
//		{
//			sMap[i][j]=(Sprite *)malloc(sizeof(Sprite));
//		}
//	}
//	for (int i=0;i<MAP_ROW;i++)
//	{
//		for (int j=0;j<MAP_COL;j++)
//		{
//			sMap[i][j]->textrue=a.sMap[i][j]->textrue;
//		}
//	}
//}

void Map::changemap(Map a)
{
	for (int i=0;i<MAP_ROW;i++)
	{
		for (int j=0;j<MAP_COL;j++)
		{
			sMap[i][j]->textrue=a.sMap[i][j]->textrue;
		}
	}
}
