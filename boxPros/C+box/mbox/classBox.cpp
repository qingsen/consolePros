// classBox.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Look.h"
#include "Map.h"
#include "Pass.h"
#include "Position.h"
#include "windows.h"
#include "conio.h"

Look end("��");
Look player="��";
Look box="��";
Look flor="  ";
Look wall="��";

int level=0; //�ڼ���
Map map[2];  //map[0]��ǰ��ͼ��map[1]���ص�ͼ

Position play[4]; //������ĸ�λ�ã����ڣ��¸������¸���һ����������һ����ʼ������λ��

Position pos[2]={Position(1,1),Position(4,2)};
int endposition[2][4]={{37,47,57,57},{52,53,62,63}};
char passmap[2][10][10][3]={
				{"��","��","��","��","��","  ","  ","  ","  ","  ",
				"��","��","  ","  ","��","  ","  ","  ","  ","  ",
				"��","  ","��","��","��","��","��","��","��","  ", 
				"��","  ","��","  ","��","��","��","��","��","  ",
				"��","��","��","  ","��","��","��","��","��","  ",
				"  ","��","��","  ","  ","  ","  ","��","��","  ",
				"  ","��","  ","  ","  ","��","  ","  ","��","  ",
				"  ","��","  ","  ","  ","��","��","��","��","  ",
				"  ","��","��","��","��","��","  ","  ","  ","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
			    },
				{"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				"  ","��","��","��","��","��","��","��","  ","  ",
				"  ","��","  ","  ","  ","  ","  ","��","��","��",
				"��","��","��","��","��","��","  ","  ","  ","��",
				"��","  ","��","  ","��","  ","  ","��","  ","��",
				"��","  ","��","��","��","  ","��","  ","��","��",
				"��","��","��","��","��","  ","  ","  ","��","  ",
				"  ","��","��","��","��","��","��","��","��","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
				}
						   };

Pass pass[2]={Pass(pos[0],endposition[0],passmap[0]),Pass(pos[1],endposition[1],passmap[1])};//�ؿ����ݳ�ʼ��

void judge(int &i,int &j);   //���¸�λ����Ӧ�ж�
void intokey();   //���������¼� 
void mapinit(int level);  //ÿ�ص�ͼ��ʼ��
void nowendposition();   //�ж����ǲ����ڽ���λ��
int gamewin();   //��Ϸ�����ж�

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{
		int k=1;  //�������������whileѭ��
		mapinit(level); //��ͼ��ʼ��
		pass[level].printfmap(); //��ӡ�ڼ��صĳ�ʼ��ͼ
		while(k)
		{
			intokey();  //��������
			map[0].printfmap();
			if(gamewin()) //�ж���Ϸ�Ƿ����
			{
				system("CLS");
				printf(" YOU WIN\n");
				printf(" Prepare for the next pass");
				Sleep(2000);
				k=0;
				level++;
				if (level>1)
				{
					level=0;
				}
			}
		}
	}
	return 0;
}

//���������¼�
void intokey()
{
	char key=getch();
	//�����ж�
	switch(key)
	{
	case 'w':  judge(--play[1].row,play[1].col);break;
	case 's':  judge(++play[1].row,play[1].col);break;
	case 'a':  judge(play[1].row,--play[1].col);break;
	case 'd':  judge(play[1].row,++play[1].col);break;
	case 'r':  mapinit(level);break;  //���¿�ʼ
	case 'b':  map[0]=map[1],play[1]=play[3],play[0]=play[1],play[2]=play[1]; break;//����һ��
	default:   break;
	}
}

//���¸�λ����Ӧ�ж�
void judge(int &i,int &j)
{
	map[1]=map[0];  //���¾ɵ�ͼ
	play[3]=play[0]; //���¾ɵ�ͼ�˵�λ��
	if (strcmp(map[0].map_[play[1].row][play[1].col],wall.look)) //�¸�λ�ò���ǽ
	{
		if (strcmp(map[0].map_[play[1].row][play[1].col],flor.look)==0||strcmp(map[0].map_[play[1].row][play[1].col],end.look)==0)  //�¸�λ���ǵذ�����λ��
		{ 
			strcpy(map[0].map_[play[1].row][play[1].col],player.look); //������Ӧʱ�����λ�ñ����
			nowendposition();  //�ж�ԭ��λ���Ƿ��ǽ���λ��
			play[0]=play[1]; 
			play[2]=play[1];  

		}
		else //�¸�λ��������
		{   
			//ָ�������¸�λ��
			play[2]=play[1];
			play[2].row+=play[1].row-play[0].row;
			play[2].col+=play[1].col-play[0].col;
			if (strcmp(map[0].map_[play[2].row][play[2].col],wall.look)&&strcmp(map[0].map_[play[2].row][play[2].col],box.look)) //���ӵ��¸�λ�üȲ���ǽ��Ҳ��������
			{
				strcpy(map[0].map_[play[1].row][play[1].col],player.look);
				strcpy(map[0].map_[play[2].row][play[2].col],box.look);
				nowendposition();
				play[0]=play[1];
				play[2]=play[1];
			}
			else
			{
				play[1]=play[0];
				play[2]=play[0];
			}
		}
	}
	else
	{
		play[1]=play[0];
	}
}

//�ж����ǲ����ڽ���λ��
void nowendposition()
{
	for (int i=0;i<4;i++)
	{
		if (play[0].row*10+play[0].col==pass[level].endposition[i]) //����δ��Ӧʱλ���Ƿ��ǽ���λ
		{
			i=5; //����ǽ���λ���ͽ����ж�
			strcpy(map[0].map_[play[0].row][play[0].col],end.look); //�ǽ���λ��ԭ��λ�ͱ�ɽ����ַ���
		}
		else
		{
			strcpy(map[0].map_[play[0].row][play[0].col],flor.look); //���ǽ���λ��ԭ��λ�ͳɵذ�
		}
	}
}

//��Ϸ�����ж�
int gamewin()
{  
	int n=0;
	for (int i=0;i<4;i++)
	{
		if (strcmp(map[0].map_[pass[level].endposition[i]/10][pass[level].endposition[i]%10],box.look)==0) //�ж�ÿ������λ�Ƿ�������ռ
		{
			n++;
		}
	}
	if(n==4) return 1;  //�������������ռ����ô�͹���
	else return 0;	
}

//ÿ�ص�ͼ��ʼ��
void mapinit(int level)
{
	play[1]=pass[level].pos;
	play[2]=play[1];
	play[0]=play[1];
	map[0].setmap(pass[level].map_);
}
