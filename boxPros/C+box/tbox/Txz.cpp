// Txz.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Level.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Level *p[3];
	Level_1 lev1;
	Level_2 lev2;
	Level_3 lev3;
	p[0]=&lev1;
	p[1]=&lev2;
	p[2]=&lev3;
	while(1)
	{
		for (int i=0;i<3;)
		{
			p[i]->run();
			if (p[i]->gamewin())
			{
				i++;
			}
		}
	}
	while (1);
	return 0;
}

