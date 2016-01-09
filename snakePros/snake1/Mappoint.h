#pragma once
class Mappoint
{
public:
	Mappoint(void);
	~Mappoint(void);
	Mappoint(int row,int col);
	void pointmove(int rmove,int cmove);

	int row;
	int col;
};

