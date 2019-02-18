/*
**		贪吃蛇游戏是一个经典小游戏，一条蛇在封闭围墙里，围墙里随机出现一朵花，
**	通过按键盘四个光标键控制蛇向上下左右四个方向移动，蛇头撞倒花朵，则花朵
**	被吃掉，蛇身体变长，同时记分，接着又出现花朵，等待蛇来吃，如果蛇在移动
**	中撞到墙或身体交叉蛇头撞倒自己身体游戏结束。本次C语言课程设计的任务是综
**	合运用C语言编程实现一个“贪吃蛇”的游戏。具体要求如下：
**
**（1）用键盘的方向键控制蛇的上下左右移动。
**（2）游戏分为三种难度，SLUG为慢速，每吃一朵花得1分；WORM为中速，每吃一朵
**	   花得2分；PYTHON为快速，每吃一朵花得3分。
**（3）游戏目标：操纵屏幕上那条可爱的小蛇，在黑框中不停吃花，而每吃一朵花，
**	   蛇的身体都变的更长一些，游戏的难度也会
**     随之加大。
**（4）游戏终止：终止条件1——蛇头撞到墙上；终止条件2——蛇身形成一个圈，也
**	   就是蛇头碰到自身的任何一处。
*/

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"

#define U 1
#define D 2 
#define L 3
#define R 4

#define SLUG 250 //低速
#define WORM 200//中速
#define PYTHON 150//高速

//蛇的结构体
typedef struct Snake
{
	int x;
	int y;
	struct Snake *next;
}snake;

//定义全局变量

//总分 :score ， 每个食物的分数:add
int score=0,add=2;

//蛇的状态：up down left right 游戏间隔时间:sleeptime
int status,sleeptime=200;

// 蛇头指针:*head,食物指针:*food，遍历蛇用的指针:*q
snake *head,*food,*q;

//游戏退出 撞墙:endgamestatus=1 2.撞到自己endgamestatus=2, 3.Esc退出endgamestatus=3
int endgamestatus=0; 

/****全局函数****/

void Pos();				//设置控制台光标位置

/*游戏初始化*/

void gamestart();		//开始游戏
void gamerule();		//游戏规则介绍
void initlevel();		//初始化游戏难度
void createmap();		//创建地图
void initsnake();		//初始化蛇身
void createfood();		//初始化食物

/*游戏中*/

void gamecircle();		//!!!游戏开始循环
void snakemove();		//!!!蛇身的移动
void level();			//总分，游戏等级，每个食物得分
void pause();			//暂停
void biteself();		//撞到自己 2
void bitewall();		//撞到墙 1

/*结束游戏*/

void endgame();								//游戏退出 1：撞墙 2：撞到自己  

int main()
{
	gamestart();
	gamecircle();
	return 0;
}


void Pos(int x ,int y)						//设置光标位置
{
	HANDLE hout;							//创建窗口句柄变量
	COORD pos={0,0};						//创建光标变量
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//对窗口进行实例化，获得输出句柄
	pos.X=x;								//设置x坐标
	pos.Y=y;								//设置y坐标
	SetConsoleCursorPosition(hout,pos);		//设置控制台光标所在位置
}	

void gamestart()							//开始游戏
{
	gamerule();
	initlevel();							//初始化游戏难度
	createmap();
	createfood();
	initsnake();

}

void gamerule()								//游戏规则
{	
	system("color 03");						//设置颜色color 0代表黑色3代表青色
	system("title 贪吃蛇");
	system("mode 100,30");					//设置行和列
	Pos(40,12);
	printf("欢迎来到贪吃蛇游戏");
	Pos(40,25);
	system("pause");						//按任意键继续
	system("cls");
	Pos(25,12);
	printf("不能穿墙，不能咬到自己");
	Pos(25,13);
	printf("用↑.↓.←.→分别控制蛇的移动.");
	Pos(40,25);
	system("pause");
	system("cls");							//清屏

}

void initlevel()							//初始化游戏难度
{	int i;
	Pos(30,13);
	printf("请选择游戏难度(1.高 2.中 3.低):");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			sleeptime=PYTHON;				//高难度
			add=3;
			break;
		case 2:
			sleeptime=WORM;					//中等难度
			add=2;
			break;
		case 3:
			sleeptime=SLUG;					//低难度
			add=1;
			break;
		default :
			system("cls");
			Pos(30,12);
			printf("输入等级错误重新输入:");
			initlevel();
			break;
	}
	system("cls");
}

void createmap()							//创建地图
{
	int i;
	for(i=0;i<=98;i+=2)
	{
		Pos(i,0);
		printf("■");
		Pos(i,27);
		printf("■");
	}
	
	for(i=1;i<=27;i++)
	{
		Pos(0,i);
		printf("■");
		Pos(66,i);
		printf("■");
		Pos(98,i);
		printf("■");
	}
	Pos(72,13);
	printf("Space:开始/暂停");

	for(i=68;i<=98;i+=2)
	{
		Pos(i,9);
		printf("■");
	}
}

void initsnake()							//!!!初始化蛇身
{
	snake *p;
	int i;
	head = (snake *)malloc(sizeof(snake));
	
	head->next=NULL;
	head->x=40;
	head->y=5;
	for(i=1;i<5;i++)						// !!!采用头插法初始化蛇身
	{
		p=(snake *)malloc(sizeof(snake));
		p->x=40+2*i;
		p->y=5;
		p->next=head;
		head=p;
	}

	while(p!=NULL)							//!!输出蛇身
	{
		Pos(p->x,p->y);
		printf("■");
		p=p->next;
	}
}

void createfood()							//!!!初始化食物
{
	snake *food_1;
	srand((unsigned)time(NULL));
	food_1=(snake *)malloc(sizeof(snake));

/*Coord：区域声明*/
Coord:
	while((food_1->x%2)!=0)
	{
		food_1->x=rand()%64+1;
	}
	food_1->y=rand()%26+1;
	q=head;
	while(q!=NULL)							//食物是否与蛇身重叠如果是//跳转到Coord：出重新创建
	{
		if(q->x==food_1->x && q->y==food_1->y)
			goto Coord;						//跳转回coord
		q=q->next;
	}

	food=food_1;							//全局变量food为food_1位置:用于蛇头和食物重叠判断
	/*输出食物*/
	Pos(food_1->x,food_1->y);
	printf("Ψ");
}



void gamecircle()//游戏开始循环
{
	status=R;
	while(1)
	{
		level();												//输出总分，难度，和每个食物的分数
		if(GetAsyncKeyState(VK_UP) && status !=D)				//GetAsyncKeyState()接口功能是获取键盘缓冲区的键位值
		{   status=U;}											//获取到VK_UP为上方向键，蛇身状态status =U
		else if(GetAsyncKeyState(VK_DOWN) && status!=U)		
		{	status=D;}
		else if(GetAsyncKeyState(VK_LEFT) && status!=R)
		{	status=L;}
		else if(GetAsyncKeyState(VK_RIGHT) && status!=L)
		{	status=R;}
		else if(GetAsyncKeyState(VK_SPACE))
		{	pause(); }
		Sleep(sleeptime);										//延时函数Sleep
		snakemove();											//根据蛇身状态变量：status的值进行移动
		biteself();												//判断是否撞到自己
		bitewall();												//判断是否撞到墙
	}
}

void snakemove()//蛇身移动
{	//新的 蛇头位置指针
	snake *nexthead; 
	/*蛇身向右移动*/
	if(status==R)
	{	nexthead=(snake *)malloc(sizeof(snake));
		nexthead->x=head->x+2;   //蛇头向右 则蛇头X坐标加2   !!!因为■占两个字节
		nexthead->y=head->y;
	/*刷新蛇头位置并赋值给遍历指针q */
		nexthead->next=head;
		head=nexthead;
		q=head;
		if(head->x==food->x && head->y==food->y)//如果蛇头和食物位置重叠：蛇头增加而蛇尾不消失
		{
		
			while(q!=NULL)//打印新的蛇头
			{	Pos(q->x,q->y);
				printf("■");
				q=q->next;
			}
			score+=add;//总分增加
			createfood(); //重建食物
		}
		else //没有吃到食物，蛇尾消失，蛇头增加
		{
			while(q->next->next!=NULL)//打印新的蛇头、
			{
				Pos(q->x,q->y);
				printf("■");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);//输出尾部为空
			printf(" ");
			free(q->next);//销毁链表空间
			q->next=NULL;//为了后续的操作，链表指向设置为空
		}
	}

	/*向左移动同其他相似：改变*/
	//蛇头向左 则蛇头X坐标加2  !!因为■占两个字节
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
				printf("■");
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
				printf("■");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
	/*向上移动同其他相似：改变*/
	//蛇头向上 则蛇头Y坐标-1  !!因为■占1行的位置
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
				printf("■");
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
				printf("■");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
	/*向左移动同其他相似：改变*/
	//蛇头向左 则蛇头Y坐标+1  !!因为■占两个字节
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
				printf("■");
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
				printf("■");
				q=q->next;
			}
			Pos(q->next->x,q->next->y);
			printf("  ");
			free(q->next);
			q->next=NULL;
		}
	}
 }

 void level()//总分，游戏等级，每个食物得分；
{
		Pos(72,3);
		printf("得分: %d",score);
		Pos(72,4);
		printf("游戏等级:");
		if(add==20)
		printf("中");
		else if(add==30)
		printf("高");
		else if(add==10)
		printf("低");
		Pos(72,5);
		printf("每个事物得分: %d",add);
}

 void pause()//暂停
{
	while(1)
	{
		Sleep(300);
		if(GetAsyncKeyState(VK_SPACE))					//如果space跳出循环继续游戏
			 break; 
	}
}

void bitewall()//撞到墙 1
{
	if(head->x==0 || head->x==66 || head->y==0 || head->y==27)	//xy值与墙的xy值相等 则判断蛇头位置撞到墙
	{
		endgamestatus=1;
		endgame();
	}
}
void biteself()//撞到自己 2			
{
	q=head->next;										//跳过蛇头 !!!蛇头和蛇头相等
	while(q!=NULL)										//将所有的蛇身与蛇头进行相等判断
	{
		if(q->x==head->x && q->y==head->y)				//蛇头xy值与蛇身的xy值相等 则判断蛇头位置撞到自己
		{
			endgamestatus=2;							//结束状态为2
			endgame();									//结束函数
		}
		q=q->next;
	}
}


void endgame()//游戏退出 
{
	if(endgamestatus==1)								//1：撞墙 
	{
		Pos(24,14);
		printf("你的成绩: %d",score);
		Pos(20,13);
		printf("游戏结束: 你撞到了墙!");
	}
	else if(endgamestatus==2)							//2：撞到自己  
	{
		Pos(24,14);
		printf("你的成绩: %d",score);
		Pos(20,13);
		printf("游戏结束: 请不要撞到自己");
	}
	
	Pos(24,15);
	system("pause");
	exit(0);											//!!!退出程序
}