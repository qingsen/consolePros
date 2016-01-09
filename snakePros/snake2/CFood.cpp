#include "CFood.h"


CCFood::CCFood(void)
{
	texture = "ก่";
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
