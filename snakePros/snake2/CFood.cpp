#include "CFood.h"


CCFood::CCFood(void)
{
	texture = "��";
}


CCFood::~CCFood(void)
{
}

bool CCFood::isFood(CCPoint pos)
{
	if (pos.isEqual(this->positon))
	{
		return true;
	}
	return false;
}
