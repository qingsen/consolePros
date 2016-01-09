#include "CMap.h"
#include "CWall.h"
#include "CFloor.h"
#include "stdafx.h"
#include "string.h"

CCMap::CCMap(void)
{
	 mapData[0][0] = new CCWall();
	 mapData[0][1] = new CCWall();
	 mapData[0][2] = new CCWall();
	 mapData[0][3] = new CCWall();
	 mapData[0][4] = new CCWall();
	 mapData[0][5] = new CCWall();
	 mapData[0][6] = new CCWall();
	 mapData[0][7] = new CCWall();
	 mapData[0][8] = new CCWall();
	 mapData[0][9] = new CCWall();

	 mapData[1][0] = new CCWall();
	 mapData[1][1] = new CCFloor();
	 mapData[1][2] = new CCFloor();
	 mapData[1][3] = new CCFloor();
	 mapData[1][4] = new CCFloor();
	 mapData[1][5] = new CCFloor();
	 mapData[1][6] = new CCFloor();
	 mapData[1][7] = new CCFloor();
	 mapData[1][8] = new CCFloor();
	 mapData[1][9] = new CCWall();

	 mapData[2][0] = new CCWall();
	 mapData[2][1] = new CCFloor();
	 mapData[2][2] = new CCFloor();
	 mapData[2][3] = new CCFloor();
	 mapData[2][4] = new CCFloor();
	 mapData[2][5] = new CCFloor();
	 mapData[2][6] = new CCFloor();
	 mapData[2][7] = new CCFloor();
	 mapData[2][8] = new CCFloor();
	 mapData[2][9] = new CCWall();

	 mapData[3][0] = new CCWall();
	 mapData[3][1] = new CCFloor();
	 mapData[3][2] = new CCFloor();
	 mapData[3][3] = new CCFloor();
	 mapData[3][4] = new CCFloor();
	 mapData[3][5] = new CCFloor();
	 mapData[3][6] = new CCFloor();
	 mapData[3][7] = new CCFloor();
	 mapData[3][8] = new CCFloor();
	 mapData[3][9] = new CCWall();

	 mapData[4][0] = new CCWall();
	 mapData[4][1] = new CCFloor();
	 mapData[4][2] = new CCFloor();
	 mapData[4][3] = new CCFloor();
	 mapData[4][4] = new CCFloor();
	 mapData[4][5] = new CCFloor();
	 mapData[4][6] = new CCFloor();
	 mapData[4][7] = new CCFloor();
	 mapData[4][8] = new CCFloor();
	 mapData[4][9] = new CCWall();

	 mapData[5][0] = new CCWall();
	 mapData[5][1] = new CCFloor();
	 mapData[5][2] = new CCFloor();
	 mapData[5][3] = new CCFloor();
	 mapData[5][4] = new CCFloor();
	 mapData[5][5] = new CCFloor();
	 mapData[5][6] = new CCFloor();
	 mapData[5][7] = new CCFloor();
	 mapData[5][8] = new CCFloor();
	 mapData[5][9] = new CCWall();

	 mapData[6][0] = new CCWall();
	 mapData[6][1] = new CCFloor();
	 mapData[6][2] = new CCFloor();
	 mapData[6][3] = new CCFloor();
	 mapData[6][4] = new CCFloor();
	 mapData[6][5] = new CCFloor();
	 mapData[6][6] = new CCFloor();
	 mapData[6][7] = new CCFloor();
	 mapData[6][8] = new CCFloor();
	 mapData[6][9] = new CCWall();

	 mapData[7][0] = new CCWall();
	 mapData[7][1] = new CCFloor();
	 mapData[7][2] = new CCFloor();
	 mapData[7][3] = new CCFloor();
	 mapData[7][4] = new CCFloor();
	 mapData[7][5] = new CCFloor();
	 mapData[7][6] = new CCFloor();
	 mapData[7][7] = new CCFloor();
	 mapData[7][8] = new CCFloor();
	 mapData[7][9] = new CCWall();

	 mapData[8][0] = new CCWall();
	 mapData[8][1] = new CCFloor();
	 mapData[8][2] = new CCFloor();
	 mapData[8][3] = new CCFloor();
	 mapData[8][4] = new CCFloor();
	 mapData[8][5] = new CCFloor();
	 mapData[8][6] = new CCFloor();
	 mapData[8][7] = new CCFloor();
	 mapData[8][8] = new CCFloor();
	 mapData[8][9] = new CCWall();

	 mapData[9][0] = new CCWall();
	 mapData[9][1] = new CCWall();
	 mapData[9][2] = new CCWall();
	 mapData[9][3] = new CCWall();
	 mapData[9][4] = new CCWall();
	 mapData[9][5] = new CCWall();
	 mapData[9][6] = new CCWall();
	 mapData[9][7] = new CCWall();
	 mapData[9][8] = new CCWall();
	 mapData[9][9] = new CCWall();
}


CCMap::~CCMap(void)
{
}

bool CCMap::isWall(CCPoint pos)
{
	if ( 0 == strcmp(mapData[pos.x][pos.y]->texture,mapData[0][0]->texture))
	{
		return true;
	}
	return false;
}
