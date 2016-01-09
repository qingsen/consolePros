// Box.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "string.h"
#include "windows.h"
#include "conio.h"

char end[]="��";
char player[]="��";
char box[]="��";
char flor[]="  ";
char wall[]="��";

int level=0; //�ڼ���
char map[10][10][3];
char remap[10][10][3]; //�ɵ�ͼ��������һ��

typedef struct
{
	int h;
	int l;
}Position;
Position play[4]; //������ĸ�λ�ã����ڣ��¸������¸���һ����������һ����ʼ������λ��

typedef struct 
{
	Position pos;
	int endposition[4];  //��������ĸ�����
	char map_[10][10][3];
}Map;
 Map pass[2]={
	    {{1,1},{37,47,57,57},  {"��","��","��","��","��","  ","  ","  ","  ","  ",
								"��","��","  ","  ","��","  ","  ","  ","  ","  ",
								"��","  ","��","��","��","��","��","��","��","  ", 
								"��","  ","��","  ","��","��","��","��","��","  ",
								"��","��","��","  ","��","��","��","��","��","  ",
								"  ","��","��","  ","  ","  ","  ","��","��","  ",
								"  ","��","  ","  ","  ","��","  ","  ","��","  ",
								"  ","��","  ","  ","  ","��","��","��","��","  ",
								"  ","��","��","��","��","��","  ","  ","  ","  ",
								"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
								}
		},
		  {{4,2},{52,53,62,63},{"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ",
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
		   }
			};

 void judge(int i,int j);   //���¸�λ����Ӧ�ж�
 void intokey();   //���������¼� 
 void printfmap();  //��ӡ�� ͼ
 void mapinit();  //ÿ�ص�ͼ��ʼ��
 void nowendposition();   //�ж����ǲ����ڽ���λ��
 int gamewin();   //��Ϸ�����ж�
 void exchangeemap(char a[][10][3],char b[][10][3]);  //a��ͼ����b��ͼ

int _tmain(int argc, _TCHAR* argv[])
{
	while(1)
	{
		int k=1;  //�������������whileѭ��
		mapinit(); //��ͼ��ʼ��
		printfmap();    //��ӡ��ͼ
		while(k)
		{
			intokey();  //��������
			printfmap();
			if(gamewin()) //�ж���Ϸ�Ƿ����
			{
				printf("YOU WIN");
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
	case 'w':  judge(--play[1].h,play[1].l);break;
	case 's':  judge(++play[1].h,play[1].l);break;
	case 'a':  judge(play[1].h,--play[1].l);break;
	case 'd':  judge(play[1].h,++play[1].l);break;
	case 'b':  mapinit();break;
	case 'r':  exchangeemap(map,remap),play[1]=play[3],play[0]=play[1],play[2]=play[1]; break;
	default:   break;
	}
}

//���¸�λ���ж�
void judge(int i,int j)
{
	exchangeemap(remap,map);//���¾ɵ�ͼ
	play[3]=play[0]; //���¾ɵ�ͼ�˵�λ��
	if (strcmp(map[play[1].h][play[1].l],wall)) //�¸�λ�ò���ǽ
	{
		if (strcmp(map[play[1].h][play[1].l],flor)==0||strcmp(map[play[1].h][play[1].l],end)==0)  //�¸�λ���ǵذ�����λ��
		{
			strcpy(map[play[1].h][play[1].l],player); //������Ӧʱ�����λ�ñ����
			nowendposition();  //�ж�ԭ��λ���Ƿ��ǽ���λ��
			play[0]=play[1]; 
			play[2]=play[1];  
			
		}
		else //�¸�λ��������
		{   
			//ָ�������¸�λ��
			play[2]=play[1];
			play[2].h+=play[1].h-play[0].h;
			play[2].l+=play[1].l-play[0].l;
			if (strcmp(map[play[2].h][play[2].l],wall)&&strcmp(map[play[2].h][play[2].l],box)) //���ӵ��¸�λ�üȲ���ǽ��Ҳ��������
			{
				strcpy(map[play[1].h][play[1].l],player);
				strcpy(map[play[2].h][play[2].l],box);
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
		if (play[0].h*10+play[0].l==pass[level].endposition[i]) //����δ��Ӧʱλ���Ƿ��ǽ���λ
		{
			i=4; //����ǽ���λ���ͽ����ж�
			strcpy(map[play[0].h][play[0].l],end); //�ǽ���λ��ԭ��λ�ͱ�ɽ����ַ���
		}
		else
		{
			strcpy(map[play[0].h][play[0].l],flor); //���ǽ���λ��ԭ��λ�ͳɵذ�
		}
	}
}

//��Ϸ�����ж�
int gamewin()
{  
	int n=0;
	for (int i=0;i<4;i++)
	{
		if (strcmp(map[pass[level].endposition[i]/10][pass[level].endposition[i]%10],box)==0) //�ж�ÿ������λ�Ƿ�������ռ
		{
			n++;
		}
	}
	if(n==4) return 1;  //�������������ռ����ô�͹���
	else return 0;	
}

//ÿ�ص�ͼ��ʼ��
void mapinit()
{
	play[1]=pass[level].pos;
	play[2]=play[1];
	play[0]=play[1];
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			strcpy(map[i][j],pass[level].map_[i][j]);
		}
	}
}

//a��ͼ����b��ͼ
 void exchangeemap(char a[][10][3],char b[][10][3])
 {
	 for (int i=0;i<10;i++)
	 {
		 for (int j=0;j<10;j++)
		 {
			 strcpy(a[i][j],b[i][j]);
		 }
	 }
 }

//��ӡ�� ͼ
void printfmap()
{
	system("CLS");
	for (int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%s",map[i][j]);
		}
		printf("\n");
	}
	printf("This is pass %d\n",level+1);
	printf("Key 'b' to restart\n");
	printf("Key 'r' to return\n");
}