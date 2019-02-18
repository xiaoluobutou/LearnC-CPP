/*
**		̰������Ϸ��һ������С��Ϸ��һ�����ڷ��Χǽ�Χǽ���������һ�仨��
**	ͨ���������ĸ����������������������ĸ������ƶ�����ͷײ�����䣬�򻨶�
**	���Ե���������䳤��ͬʱ�Ƿ֣������ֳ��ֻ��䣬�ȴ������ԣ���������ƶ�
**	��ײ��ǽ�����彻����ͷײ���Լ�������Ϸ����������C���Կγ���Ƶ���������
**	������C���Ա��ʵ��һ����̰���ߡ�����Ϸ������Ҫ�����£�
**
**��1���ü��̵ķ���������ߵ����������ƶ���
**��2����Ϸ��Ϊ�����Ѷȣ�SLUGΪ���٣�ÿ��һ�仨��1�֣�WORMΪ���٣�ÿ��һ��
**	   ����2�֣�PYTHONΪ���٣�ÿ��һ�仨��3�֡�
**��3����ϷĿ�꣺������Ļ�������ɰ���С�ߣ��ںڿ��в�ͣ�Ի�����ÿ��һ�仨��
**	   �ߵ����嶼��ĸ���һЩ����Ϸ���Ѷ�Ҳ��
**     ��֮�Ӵ�
**��4����Ϸ��ֹ����ֹ����1������ͷײ��ǽ�ϣ���ֹ����2���������γ�һ��Ȧ��Ҳ
**	   ������ͷ����������κ�һ����
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

#define U 1
#define D 2 
#define L 3
#define R 4

#define SLUG 250 //����
#define WORM 200//����
#define PYTHON 150//����

//�ߵĽṹ��
typedef struct Snake
{
	int x;
	int y;
	struct Snake *next;
}snake;

//����ȫ�ֱ���

//�ܷ� :score �� ÿ��ʳ��ķ���:add
int score=0,add=2;

//�ߵ�״̬��up down left right ��Ϸ���ʱ��:sleeptime
int status,sleeptime=200;

// ��ͷָ��:*head,ʳ��ָ��:*food���������õ�ָ��:*q
snake *head,*food,*q;

//��Ϸ�˳� ײǽ:endgamestatus=1 2.ײ���Լ�endgamestatus=2, 3.Esc�˳�endgamestatus=3
int endgamestatus=0; 

/****ȫ�ֺ���****/

void Pos();				//���ÿ���̨���λ��

/*��Ϸ��ʼ��*/

void gamestart();		//��ʼ��Ϸ
void gamerule();		//��Ϸ�������
void initlevel();		//��ʼ����Ϸ�Ѷ�
void createmap();		//������ͼ
void initsnake();		//��ʼ������
void createfood();		//��ʼ��ʳ��

/*��Ϸ��*/

void gamecircle();		//!!!��Ϸ��ʼѭ��
void snakemove();		//!!!������ƶ�
void level();			//�ܷ֣���Ϸ�ȼ���ÿ��ʳ��÷�
void pause();			//��ͣ
void biteself();		//ײ���Լ� 2
void bitewall();		//ײ��ǽ 1

/*������Ϸ*/

void endgame();								//��Ϸ�˳� 1��ײǽ 2��ײ���Լ�  

int main()
{
	gamestart();
	gamecircle();
	return 0;
}


void Pos(int x ,int y)						//���ù��λ��
{
	HANDLE hout;							//�������ھ������
	COORD pos={0,0};						//����������
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//�Դ��ڽ���ʵ���������������
	pos.X=x;								//����x����
	pos.Y=y;								//����y����
	SetConsoleCursorPosition(hout,pos);		//���ÿ���̨�������λ��
}	

void gamestart()							//��ʼ��Ϸ
{
	gamerule();
	initlevel();							//��ʼ����Ϸ�Ѷ�
	createmap();
	createfood();
	initsnake();

}

void gamerule()								//��Ϸ����
{	
	system("color 03");						//������ɫcolor 0�����ɫ3������ɫ
	system("title ̰����");
	system("mode 100,30");					//�����к���
	Pos(40,12);
	printf("��ӭ����̰������Ϸ");
	Pos(40,25);
	system("pause");						//�����������
	system("cls");
	Pos(25,12);
	printf("���ܴ�ǽ������ҧ���Լ�");
	Pos(25,13);
	printf("�á�.��.��.���ֱ�����ߵ��ƶ�.");
	Pos(40,25);
	system("pause");
	system("cls");							//����

}

void initlevel()							//��ʼ����Ϸ�Ѷ�
{	int i;
	Pos(30,13);
	printf("��ѡ����Ϸ�Ѷ�(1.�� 2.�� 3.��):");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			sleeptime=PYTHON;				//���Ѷ�
			add=3;
			break;
		case 2:
			sleeptime=WORM;					//�е��Ѷ�
			add=2;
			break;
		case 3:
			sleeptime=SLUG;					//���Ѷ�
			add=1;
			break;
		default :
			system("cls");
			Pos(30,12);
			printf("����ȼ�������������:");
			initlevel();
			break;
	}
	system("cls");
}

void createmap()							//������ͼ
{
	int i;
	for(i=0;i<=98;i+=2)
	{
		Pos(i,0);
		printf("��");
		Pos(i,27);
		printf("��");
	}
	
	for(i=1;i<=27;i++)
	{
		Pos(0,i);
		printf("��");
		Pos(66,i);
		printf("��");
		Pos(98,i);
		printf("��");
	}
	Pos(72,13);
	printf("Space:��ʼ/��ͣ");

	for(i=68;i<=98;i+=2)
	{
		Pos(i,9);
		printf("��");
	}
}

void initsnake()							//!!!��ʼ������
{
	snake *p;
	int i;
	head = (snake *)malloc(sizeof(snake));
	
	head->next=NULL;
	head->x=40;
	head->y=5;
	for(i=1;i<5;i++)						// !!!����ͷ�巨��ʼ������
	{
		p=(snake *)malloc(sizeof(snake));
		p->x=40+2*i;
		p->y=5;
		p->next=head;
		head=p;
	}

	while(p!=NULL)							//!!�������
	{
		Pos(p->x,p->y);
		printf("��");
		p=p->next;
	}
}

void createfood()							//!!!��ʼ��ʳ��
{
	snake *food_1;
	srand((unsigned)time(NULL));
	food_1=(snake *)malloc(sizeof(snake));

/*Coord����������*/
Coord:
	while((food_1->x%2)!=0)
	{
		food_1->x=rand()%64+1;
	}
	food_1->y=rand()%26+1;
	q=head;
	while(q!=NULL)							//ʳ���Ƿ��������ص������//��ת��Coord�������´���
	{
		if(q->x==food_1->x && q->y==food_1->y)
			goto Coord;						//��ת��coord
		q=q->next;
	}

	food=food_1;							//ȫ�ֱ���foodΪfood_1λ��:������ͷ��ʳ���ص��ж�
	/*���ʳ��*/
	Pos(food_1->x,food_1->y);
	printf("��");
}



void gamecircle()//��Ϸ��ʼѭ��
{
	status=R;
	while(1)
	{
		level();												//����ܷ֣��Ѷȣ���ÿ��ʳ��ķ���
		if(GetAsyncKeyState(VK_UP) && status !=D)				//GetAsyncKeyState()�ӿڹ����ǻ�ȡ���̻������ļ�λֵ
		{   status=U;}											//��ȡ��VK_UPΪ�Ϸ����������״̬status =U
		else if(GetAsyncKeyState(VK_DOWN) && status!=U)		
		{	status=D;}
		else if(GetAsyncKeyState(VK_LEFT) && status!=R)
		{	status=L;}
		else if(GetAsyncKeyState(VK_RIGHT) && status!=L)
		{	status=R;}
		else if(GetAsyncKeyState(VK_SPACE))
		{	pause(); }
		Sleep(sleeptime);										//��ʱ����Sleep
		snakemove();											//��������״̬������status��ֵ�����ƶ�
		biteself();												//�ж��Ƿ�ײ���Լ�
		bitewall();												//�ж��Ƿ�ײ��ǽ
	}
}

void snakemove()//�����ƶ�
{	//�µ� ��ͷλ��ָ��
	snake *nexthead; 
	/*���������ƶ�*/
	if(status==R)
	{	nexthead=(snake *)malloc(sizeof(snake));
		nexthead->x=head->x+2;   //��ͷ���� ����ͷX�����2   !!!��Ϊ��ռ�����ֽ�
		nexthead->y=head->y;
	/*ˢ����ͷλ�ò���ֵ������ָ��q */
		nexthead->next=head;
		head=nexthead;
		q=head;
		if(head->x==food->x && head->y==food->y)//�����ͷ��ʳ��λ���ص�����ͷ���Ӷ���β����ʧ
		{
		
			while(q!=NULL)//��ӡ�µ���ͷ
			{	Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			score+=add;//�ܷ�����
			createfood(); //�ؽ�ʳ��
		}
		else //û�гԵ�ʳ���β��ʧ����ͷ����
		{
			while(q->next->next!=NULL)//��ӡ�µ���ͷ��
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);//���β��Ϊ��
			printf(" ");
			free(q->next);//��������ռ�
			q->next=NULL;//Ϊ�˺����Ĳ���������ָ������Ϊ��
		}
	}

	/*�����ƶ�ͬ�������ƣ��ı�*/
	//��ͷ���� ����ͷX�����2  !!��Ϊ��ռ�����ֽ�
	if(status==L)
	{	
		nexthead=(snake *)malloc(sizeof(snake));
		nexthead->x=head->x-2;
		nexthead->y=head->y;
		nexthead->next=head;
		head=nexthead;
		q=head;
		if(head->x==food->x && head->y==food->y)
		{
			while(q!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			score+=add;
			createfood();
		}
		else 
		{
			while(q->next->next!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
	/*�����ƶ�ͬ�������ƣ��ı�*/
	//��ͷ���� ����ͷY����-1  !!��Ϊ��ռ1�е�λ��
	if(status==U)
	{	nexthead=(snake *)malloc(sizeof(snake));
		nexthead->x=head->x;
		nexthead->y=head->y-1;
		nexthead->next=head;
		head=nexthead;
		q=head;
		if(head->x==food->x && head->y==food->y)
		{
			while(q!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			score+=add;
			createfood();
		}
		else
		{
			while(q->next->next!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
	/*�����ƶ�ͬ�������ƣ��ı�*/
	//��ͷ���� ����ͷY����+1  !!��Ϊ��ռ�����ֽ�
	if(status==D)
	{
		nexthead=(snake *)malloc(sizeof(snake));
		nexthead->x=head->x;
		nexthead->y=head->y+1;
		nexthead->next=head;
		head=nexthead;
		q=head;
		if(head->x==food->x && head->y==food->y)
		{
			while(q!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			score+=add;
			createfood();
		}
		else 
		{
			while(q->next->next!=NULL)
			{
				Pos(q->x,q->y);
				printf("��");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
 }

 void level()//�ܷ֣���Ϸ�ȼ���ÿ��ʳ��÷֣�
{
		Pos(72,3);
		printf("�÷�: %d",score);
		Pos(72,4);
		printf("��Ϸ�ȼ�:");
		if(add==20)
		printf("��");
		else if(add==30)
		printf("��");
		else if(add==10)
		printf("��");
		Pos(72,5);
		printf("ÿ������÷�: %d",add);
}

 void pause()//��ͣ
{
	while(1)
	{
		Sleep(300);
		if(GetAsyncKeyState(VK_SPACE))					//���space����ѭ��������Ϸ
			 break; 
	}
}

void bitewall()//ײ��ǽ 1
{
	if(head->x==0 || head->x==66 || head->y==0 || head->y==27)	//xyֵ��ǽ��xyֵ��� ���ж���ͷλ��ײ��ǽ
	{
		endgamestatus=1;
		endgame();
	}
}
void biteself()//ײ���Լ� 2			
{
	q=head->next;										//������ͷ !!!��ͷ����ͷ���
	while(q!=NULL)										//�����е���������ͷ��������ж�
	{
		if(q->x==head->x && q->y==head->y)				//��ͷxyֵ�������xyֵ��� ���ж���ͷλ��ײ���Լ�
		{
			endgamestatus=2;							//����״̬Ϊ2
			endgame();									//��������
		}
		q=q->next;
	}
}


void endgame()//��Ϸ�˳� 
{
	if(endgamestatus==1)								//1��ײǽ 
	{
		Pos(24,14);
		printf("��ĳɼ�: %d",score);
		Pos(20,13);
		printf("��Ϸ����: ��ײ����ǽ!");
	}
	else if(endgamestatus==2)							//2��ײ���Լ�  
	{
		Pos(24,14);
		printf("��ĳɼ�: %d",score);
		Pos(20,13);
		printf("��Ϸ����: �벻Ҫײ���Լ�");
	}
	
	Pos(24,15);
	system("pause");
	exit(0);											//!!!�˳�����
}