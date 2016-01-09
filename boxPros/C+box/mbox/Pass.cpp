#include "StdAfx.h"
#include "Pass.h"
#include "string.h"


Pass::Pass(void)
{
}

Pass::Pass(Position pos,int endposition[4],char tu[10][10][3])
{
	this->pos=pos;
	for (int i=0;i<4;i++)
	{
			this->endposition[i]=endposition[i];
	}
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			strcpy(map_[i][j],tu[i][j]);
		}
	}
}

Pass::~Pass(void)
{
}
