#pragma once
class Map
{
public:
	Map(void);
	~Map(void);

    void printfmap();  //打印地 图
	void setmap(char a[][10][3]);  //设置地图

	char map_[10][10][3];    //存放地图
};

