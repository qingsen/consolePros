#pragma once

class Point
{
public: 
	Point();
	Point(int x,int y);
	~Point();

	int x;
	int y;

	bool isEqual(Point p);//�ж����������
};