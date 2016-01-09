#include "StdAfx.h"
#include "Level_2.h"


Level_2::Level_2(void)
{
	endnumber=3;
	player.p1.x=1;
	player.p1.y=1;

	end[0].p1.x=3;
	end[0].p1.y=7;
	end[1].p1.x=4;
	end[1].p1.y=7;
	end[2].p1.x=5;
	end[2].p1.y=7;

	//初始化数据
	map.sMap[0][0]=new Wall();
	map.sMap[0][1]=new Wall();
	map.sMap[0][2]=new Wall();
	map.sMap[0][3]=new Wall();
	map.sMap[0][4]=new Wall();
	map.sMap[0][5]=new Floor();
	map.sMap[0][6]=new Floor();
	map.sMap[0][7]=new Floor();
	map.sMap[0][8]=new Floor();
	map.sMap[0][9]=new Floor();

	map.sMap[1][0]=new Wall();
	map.sMap[1][1]=new Floor();
	map.sMap[1][2]=new Floor();
	map.sMap[1][3]=new Floor();
	map.sMap[1][4]=new Wall();
	map.sMap[1][5]=new Floor();
	map.sMap[1][6]=new Floor();
	map.sMap[1][7]=new Floor();
	map.sMap[1][8]=new Floor();
	map.sMap[1][9]=new Floor();

	map.sMap[2][0]=new Wall();
	map.sMap[2][1]=new Floor();
	map.sMap[2][2]=new Box();
	map.sMap[2][3]=new Box();
	map.sMap[2][4]=new Wall();
	map.sMap[2][5]=new Wall();
	map.sMap[2][6]=new Wall();
	map.sMap[2][7]=new Wall();
	map.sMap[2][8]=new Wall();
	map.sMap[2][9]=new Floor();

	map.sMap[3][0]=new Wall();
	map.sMap[3][1]=new Floor();
	map.sMap[3][2]=new Box();
	map.sMap[3][3]=new Floor();
	map.sMap[3][4]=new Wall();
	map.sMap[3][5]=new Wall();
	map.sMap[3][6]=new Wall();
	map.sMap[3][7]=new Floor();
	map.sMap[3][8]=new Wall();
	map.sMap[3][9]=new Floor();

	map.sMap[4][0]=new Wall();
	map.sMap[4][1]=new Wall();
	map.sMap[4][2]=new Wall();
	map.sMap[4][3]=new Floor();
	map.sMap[4][4]=new Wall();
	map.sMap[4][5]=new Wall();
	map.sMap[4][6]=new Wall();
	map.sMap[4][7]=new Floor();
	map.sMap[4][8]=new Wall();
	map.sMap[4][9]=new Floor();

	map.sMap[5][0]=new Floor();
	map.sMap[5][1]=new Wall();
	map.sMap[5][2]=new Wall();
	map.sMap[5][3]=new Floor();
	map.sMap[5][4]=new Floor();
	map.sMap[5][5]=new Floor();
	map.sMap[5][6]=new Floor();
	map.sMap[5][7]=new Floor();
	map.sMap[5][8]=new Wall();
	map.sMap[5][9]=new Floor();

	map.sMap[6][0]=new Floor();
	map.sMap[6][1]=new Wall();
	map.sMap[6][2]=new Floor();
	map.sMap[6][3]=new Floor();
	map.sMap[6][4]=new Floor();
	map.sMap[6][5]=new Wall();
	map.sMap[6][6]=new Floor();
	map.sMap[6][7]=new Floor();
	map.sMap[6][8]=new Wall();
	map.sMap[6][9]=new Floor();

	map.sMap[7][0]=new Floor();
	map.sMap[7][1]=new Wall();
	map.sMap[7][2]=new Floor();
	map.sMap[7][3]=new Floor();
	map.sMap[7][4]=new Floor();
	map.sMap[7][5]=new Wall();
	map.sMap[7][6]=new Wall();
	map.sMap[7][7]=new Wall();
	map.sMap[7][8]=new Wall();
	map.sMap[7][9]=new Floor();

	map.sMap[8][0]=new Floor();
	map.sMap[8][1]=new Wall();
	map.sMap[8][2]=new Wall();
	map.sMap[8][3]=new Wall();
	map.sMap[8][4]=new Wall();
	map.sMap[8][5]=new Wall();
	map.sMap[8][6]=new Floor();
	map.sMap[8][7]=new Floor();
	map.sMap[8][8]=new Floor();
	map.sMap[8][9]=new Floor();

	map.sMap[9][0]=new Floor();
	map.sMap[9][1]=new Floor();
	map.sMap[9][2]=new Floor();
	map.sMap[9][3]=new Floor();
	map.sMap[9][4]=new Floor();
	map.sMap[9][5]=new Floor();
	map.sMap[9][6]=new Floor();
	map.sMap[9][7]=new Floor();
	map.sMap[9][8]=new Floor();
	map.sMap[9][9]=new Floor();
}


Level_2::~Level_2(void)
{
	//释放内存
	for (int i=0;i<MAP_ROW;i++)
	{
		for(int j=0;j<MAP_COL;j++)
		{
			delete(map.sMap[i][j]);
		}
	}
}
