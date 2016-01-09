#pragma once

class Point
{
public: 
	Point();
	Point(int x,int y);
	~Point();

	int x;
	int y;

	bool isEqual(Point p);//判断两个点相等
};