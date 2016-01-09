#pragma once
#include "Map.h"
#include "Player.h"
#include "Box.h"
#include "End.h"
#include "Wall.h"
#include "Floor.h"
#include "Sprite.h"

class Level
{
public:
	Level();
	~Level();

	//��ͼ
	Map map,oldmap,intimap;
	Box box;
	int endnumber;
	//���
	Player player,oldplayer,intiplayer;
	//Ŀ�ĵ�
	End end[3];
	//	ǽ
	Wall wall;
	//�յ�
	Floor floor;
	
	//����
	void run();
	//����������ƶ�״̬
	void getMove(int x1,int y1);
	//�ж�ĳ��λ���Ƿ������
	bool isPlayer(Point p);
	//�ж�ĳ��λ���ǽ�����
	bool isEnd(Point p);
	bool gamewin();


private:
	//��ʾ��ͼ
	void showMap();
	//�޸�����
	void contrData();
};