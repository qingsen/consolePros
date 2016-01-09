#include "stdafx.h"
#include "Point.h"

Point::Point()
{

}
Point::Point(int x,int y)
{
	this->x=x;
	this->y=y;
}

Point::~Point()
{

}

bool Point::isEqual(Point p)
{
	if ((x==p.x)&&(y==p.y))
	{
		return true;
	}
	return false;
}