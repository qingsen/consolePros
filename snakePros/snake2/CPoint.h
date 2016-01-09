#pragma once
class CCPoint
{
public:
	CCPoint(void);
	CCPoint(int x, int y);

	~CCPoint(void);

	int x;
	int y;

	bool isEqual( CCPoint p );

	static CCPoint randPoint(int maxRow, int maxCol);
};

