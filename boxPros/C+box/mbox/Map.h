#pragma once
class Map
{
public:
	Map(void);
	~Map(void);

    void printfmap();  //��ӡ�� ͼ
	void setmap(char a[][10][3]);  //���õ�ͼ

	char map_[10][10][3];    //��ŵ�ͼ
};

