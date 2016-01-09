#include "CPoint.h"
#include "stdafx.h"
#include "time.h"
#include "stdlib.h"
//int CCPoint::count = 0;

CCPoint::CCPoint(void)
{
	//count ++;
}

CCPoint::CCPoint(int x,int y):x(x),y(y)
{
	//count ++;
}


CCPoint::~CCPoint(void)
{

}

bool CCPoint::isEqual( CCPoint p )
{
	if ( (x == p.x) && (y == p.y) )
	{
		return true;
	}
	return false;
}

CCPoint CCPoint::randPoint(int maxRow, int maxCol)
{
	srand(( unsigned int )time(NULL));
	int r = rand()%(maxRow-2) + 1;
	int c = rand()%(maxCol-2) + 1;
	return CCPoint(r,c);
}