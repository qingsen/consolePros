#include "StdAfx.h"
#include "Mappoint.h"


Mappoint::Mappoint(void)
{
}
Mappoint::Mappoint(int row,int col)
{
	this->row=row;
	this->col=col;
}

Mappoint::~Mappoint(void)
{
}
void Mappoint::pointmove(int rmove,int cmove)
{
	row+=rmove;
	col+=cmove;
}