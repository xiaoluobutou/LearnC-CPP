/*
#include "stdio.h"
int main()
{
	int max_value(int array[][4]);
	int a[3][4]={{1,3,5,7},{2,4,6,8},{15,17,34,12}};
	printf("Max value is %d\n",max_value(a));
	return 0;
}
int max_value(int array[][4])
{
 	int i,j,max;
	max=array[0][0];
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(array[i][j]>max)max=array[i][j];
			return (max);
}
*/
/*
#include"stdio.h"
float Max=0,Min=0;
int main ()
{
	float average (float array[],int n);
	float ave,score[10];
	int i;
	printf("Please enter 10 score:");
	for(i=0;i<10;i++)
	scanf ("%f",&score[i]);
	ave=average(score,10);
	printf("max=%6.2f,min=6.2%f,average=%6.2f",Max,Min,ave);
	return 0;
}				
float average(float array[],int n)
{
	int i ;
	float aver,sum=array[0];
	Max=Min=array[0];
	for(i=1;i<n;i++)
	{
		if(array[i]>Max)Max=array[i];
		else if(array[i]<Min)Min=array[i];
		sum=sum+array[i];
	}
	
	aver=sum/10;
	return aver;
}
*/
/*
#include "stdio.h"
int a=3,b=5;
int main ()
{
	int  max(int a,int b);
	int a=8;
	printf("max=%d\n",max(a,b));
	return 0;
}
int max(int a,int b)
{
	return a>b ? a:b;
}
*/
/*
#include "stdio.h"
int main()
{
	int f(int);
	int a=2,i;
	for(i=0;i<3;i++)
		printf("%d\n",f(a));
	return 0;
}
int f(int a)
{
	auto int b=0;
	static c=3;
	b=b+1;
	c=c+1;
	return (a+b+c);
}
*/
/*
#include "stdio.h"
int main()
{
	int fac(int n);
	int i;
	for(i=1;i<=5;i++)
		printf("%d!=%d\n",i,fac(i));
	return 0;
}
int fac(int n)
{	

	static int f=1;
	f=f*n;
	return f;
}
*/
/*
#include "stdio.h"
int main()
{
	int max();
	extern int A,B,C;
	printf("Please enter three integer numbers:");
	scanf("%d %d %d",&A,&B,&C);
	printf("max is %d\n",max());
	return 0;
}
int A,B,C;
int max()
{
	int m;
	m=A>B?A:B;
	if(C>m)m=C;
	return m;

}
*/
/*
#include "stdio.h"
int main()
{
	int a=100,b=10;
	int *pointer_1,*pointer_2;
	pointer_1=&a;
	pointer_2=&b;
	printf("a=%d,b=%d\n",a,b);
	printf("*pointer_1=%d\t*pointer_2=%d\n*pointer_1=0x%p\t*pointer_2=0x%p\n",*pointer_1,*pointer_2);
	return 0;
}
*/
/*
	#include "stdio.h"
	int main ()
	{
		int *p1,*p2,*p,a,b;
		printf("Please enter two integer numbers[With a space between]:");
		scanf("%d %d",&a,&b);
		p1=&a;
		p2=&b;
		if(a<b)
		{
			p=p1;p1=p2;p2=p;
		}
		printf("a=%d,b=%d\n",a,b);
		printf("Max=%d,Min=%d\n",*p1,*p2);
		return 0;
	}
*/
/*
#include "stdio.h"
int main()
{
	void swap(int *p1,int *p2);
	int a,b;
	int *pointer_1,*pointer_2;
	printf("Please enter a and b[With a space between]");
	scanf("%d %d",&a,&b);
	pointer_1=&a;
	pointer_2=&b;
	if(a<b) swap(pointer_1,pointer_2);
	printf("Max=%d,Min=%d\n",a,b);
	return 0;
}
void swap(int * p1,int * p2)
{
	int temp;
	temp=* p1;
	* p1=* p2;
	* p2=temp;
}
*/
/*
#include "stdio.h"
int main()
{
	void exchange(int *q1,int *q2,int *q3);
	int a,b,c,*q1,*q2,*q3;
	printf("Please enter three numbers[Whit a space between]:");
	scanf("%d %d %d",&a,&b,&c);
	q1=&a;q2=&b;q3=&c;
	exchange(q1,q2,q3); //实参地址传送到形参里
	printf("The order is:%d,%d,%d\n",a,b,c);
	return 0;
}
void exchange(int *q1,int *q2,int *q3)	
{
	void swap(int *pt1,int *pt2);
	if(*q1<*q2)swap(q1,q2);
	if(*q1<*q3)swap(q1,q3);
	if(*q2<*q3)swap(q2,q3);
}
void swap(int *pt1,int *pt2)
{
	int *temp;
	temp=*pt1;
	*pt1=*pt2;
	*pt2=temp;
}
*/
/*
#include "stdio.h"
int main()
{
	int a[10];
	int i;
	printf("Please enter 10 integer numbers[With a space between]:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
	printf("\n");
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int a[10];
	int i;
	printf("Please enter 10 inteager numbers[With a space between]:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		printf("%d ",*(a+i));//*(a+i)（计算元素地址）=a[i]（下表法）；
	printf("\n");
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int a[10];
	int i,*p;
	printf("Please enter 10 inteager numbers[With a space between]:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(p=a;p<(a+10);p++)
		printf("%d ",*p);//*(a+i)（计算元素地址）=a[i]（下表法）；
	printf("\n");	
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int a[10];
	int i,*p;
	p=a;
	printf("Please enter 10 inteager numbers[With a space between]:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++,p++)
		printf("%d ",*p);//*(a+i)（计算元素地址）=a[i]（下表法）；
	printf("\n");		
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	void inv(int x[],int n);
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	inv(a,10);
	printf("The array has been inverted:\n");//inverted 反向倒转
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
void inv(int x[],int n)
{
	int temp,i,j,m=((n-1)/2);//m是取数组的中间值
		for(i=0;i<=m;i++)
		{
			j=n-1-i;//j是i在数组中的倒数
			temp=x[i];x[i]=x[j];x[j]=temp;//交换x【i】和x【j】的值
		}
		return ;
}
*/
/*
#include "stdio.h"
int main()
{
	void inv(int x[],int n);
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	inv(a,10);
	printf("The array has been inverted:\n");//inverted 反向倒转
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
void inv(int *x,int n)
{
	int *p,*i,*j;
	int temp,m=(n-1)/2;
	p=x+m;
	for(i=x,j=x+n-1;i<=p;i++,j--)
	{
		temp=*i;*i=*j;*j=temp;
	}
	return ;
}
*/

/*
#include "stdio.h"
int main()
{
	void inv(int *x,int n);
	int *x,i,a[10]={3,7,9,11,0,6,7,5,4,2};
	x=a[0];
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	inv(a,10);
	printf("The array has been inverted:\n");//inverted 反向倒转
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
void inv(int *x,int n)
{
	int *p,*i,*j;
	int temp,m=(n-1)/2;
	p=x+m;
	for(i=x,j=x+n-1;i<=p;i++,j--)
	{
		temp=*i;*i=*j;*j=temp;
	}
	return ;
}
*/

/*
#include "stdio.h"
int main()
{
	void sort (int x[],int n);
	int i,*p,a[10]={1,2,3,4,5,6,7,8,9,10};
	p=a;
//	printf("Please enter 10 integer numbers[with a space between]:");
//	for(i=0;i<10;i++)
//		scanf("%d",p++);
//	p=a;

	  sort(p,10);
	for(p=a,i=0;i<10;i++)
	{
		printf("%d ",*p);
		p++;	
	}
	printf("\n");
	return 0;
}
void sort(int x[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++) //循环后面千万不要加;
			if(x[j]>x[k])k=j;
		if(k!=i)
		{ t=x[i];x[i]=x[k];x[k]=t; }
	}
		
}

*/
/*
#include "stdio.h"
int main()
{
	int a[3][4]={{1,3,5,7},{9,11,13,15},{17,19,21,23}};
	printf("%d,%d\n",a,*a);
	printf("%d,%d\n",a[0],*(a+0));
	printf("%d,%d\n",&a[0],&a[0][0]);
	printf("%d,%d\n",a[1],a+1);
	printf("%d,%d\n",&a[1][0],*(a+1)+0);
	printf("%d,%d\n",a[2],*(a+2));
	printf("%d,%d\n",&a[2],a+2);
	printf("%d,%d\n",a[1][0],*(*(a+1)+0));
	printf("%d,%d\n",*a[2],*(*(a+2)+0));
	return 0;
}*/
/*
#include "stdio.h"
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int *p;
	for(p=a[0];p<a[0]+12;p++)
	{
		if((p-a[0])%4==0)printf("\n");
		printf("%4d ",*p);
	}
	printf("\n");
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int(*p)[4],i,j;
	p=a;
	printf("Please enter row and colum[with a space between]:");
	scanf("%d %d",&i,&j);
	printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));
	return 0;

}
*/
/*
#include "stdio.h"
int main()
{
	int a[4]={1,3,5,7};
	int (*p)[4];
	p=&a;
	printf("%d\n",(*p)[3]);
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	void average(float *p,int n);
	void search(float (*p)[4],int n);
	float score [3][4]={
		{65,67,70,60},
		{80,87,90,81},
		{90,99,100,98},
	};
	average(*score,12);
	search(score,2);
	return 0;
}
void average(float *p,int n)
{
	float *p_end;
	float sum=0,aver;
	p_end=p+n-1;
	for(;p<=p_end;p++)
		sum+=(*p);
	aver=sum/n;
	printf("average=5,2f\n",aver);
}
void search(float(*p)[4],int n)
{
	int i;
	printf("The score of No.%d are:\n",n);
	for(i=0;i<4;i++)
		printf("%5.2f ",*(*(p+n)+i));
	printf("\n");
}
*/
/*
#include "stdio.h"

int main()
{
	void average(float *p,int n);//*p 是指针变量
	void search(float (*p)[4],int n);//（*p）【4】是指向包含4个元素的一维数组
	float score[3][4]={
		{77,71,74,73},
		{81,88,84,83},
		{91,99,94,97}
	}; //数组初始化加；
	average(*score,12);
	search(score,2);
	return 0;
}
void average(float *p,int n)
{
	float *p_end;
	float sum=0,aver;
	p_end=p+n-1;
	for(;p<=p_end;p++)
		sum+=(*p);
	aver=sum/n;
	printf("average=%5.2f\n",aver);
}
void search(float (*p)[4],int n)
{
	int i;
	printf("The score of No.%d are:\n",n);
	for(i=0;i<4;i++)
		printf("%5.2f ",*(*(p+n)+i));
	printf("\n");
}
*/
/*
#include "stdio.h"
int main()
{
	void search(float (*p)[4],int n);
	float score[3][4]={
		{77,88,99,55},
		{87,88,99,54},
		{97,98,99,100}
	};
	search(score,3);
	return 0;
}
void search (float (*p)[4],int n)
{
	int i,j,flag;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<4;j++)
			if(*(*(p+i)+j)<60)flag=1;//*(*(*p+i)+j)
		if(flag==1)
		{
			printf("No.%d fails,his scores are:\n",i+1);
			for(j=0;j<4;j++)
			{
				printf("%5.2f ",*(*(p+i)+j));
			}
			printf("\n");
		}
	}
}
*/
/*
#include "stdio.h"
void copy_string(char from[],char to[])
{
	int i=0;
	while(from[i]!='\0')
	{to[i]=from[i];++i;}
	to[i]='\0';
}
int main()
{
	char a[]="I LOVE CHINA!";
	char b[]="I LOVE YOU!";
	copy_string(a,b);
	printf("%s\n%s\n",a,b);
}
*/
/*
#include "stdio.h"
int main()
{

	int max(int ,int );
	int a,b,c;
	printf("Please enter a and b:");
	scanf ("%d %d",&a,&b);
	c=max(a,b);
	printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
	return 0;
}
int max( int x ,int y  )
{
	int z;
	if(x>y)z=x;
	else z=y;
	return (z);
}
*/
/*
#include <stdio.h>
int main()
{
/*	char a[]="I love chaina!";
	a[8]='H'; 
	//可以对数组单个元素进行赋值 但*p定义的是字符串常量不可以进行单个元素赋值
	printf("%s \n",a);
*/
/*
	int a=10,b=20;
	char format[]="a=%d,b=%d\n";
	//但是 能char format[];format="a=%d,b=%d\n";
	// format="a=%d,b=%d\n"; 
	//相当于printf（“a=%d,b=%d\n”，a，b；
	printf(format,a,b);
*/
/*

#include <stdio.h>
int main()
{
	 int max(int ,int );
	 int (*p)(int ,int);
	 int a,b,c;
	 p=max;//(*p)(int ,int) 定义一个函数指针 p=max指针变量指向函数 (*p)(a,b)调用实参传入
	 printf("Please enter a and b:");
	 scanf ("%d %d",&a,&b);
	 c=(*p)(a,b); 
	 printf("a=%d\nb=%d\nmax=%d\n",a,b,c);
	 return 0;
}
int max(int x,int y)
{	int z;
	if(x>y)z=x;
	else z=y;
	return z;
}
*/
/*
#include "stdio.h"
int main()
{
	int max(int,int );
	int min(int x,int y);
	
	int (*p)(int,int);//定义一个指向函数的指针

	int a,b,c,n;
	printf("Please enter a and b:");
	scanf("%d %d",&a,&b);
	printf("Please choose 1 or 2:");
	scanf ("%d",&n);
	
	if(n==1)p=max; //给指针p 赋值函数Max
	else if(n==2)p=min;//给指针p 赋值函数Min

	c=(*p)(a,b); //调用函数 传入实参
	printf("a=%d,b=%d\n",a,b);
	
	if(n==1)printf("max =%d\n",c);
	else printf("min=%d\n",c);
	return 0;
}
int max(int x,int y)
{	
	return x>y?x:y;
}
int min(int x, int y)
{
	return x<y?x:y;
}
*/
/*
#include "stdio.h"
int main()
{
	 void fun(int x,int y,int (*p)(int ,int));
	 int max(int ,int);
	 int min(int ,int);
	 int add(int ,int);
	 int a=34,b=-21,n;
	 printf("Please choose 1,2,or 3:");
	 scanf("%d",&n); //取地址符 一定要写
	 if(n==1)fun(a,b,max);
	 else if(n==2)fun(a,b,min);
	 else if(n==3)fun(a,b,add);
	 else printf("n date error");
	 return 0;
}
	void  fun(int x,int y,int (*p)(int ,int))
	{
		printf("%d\n",(*p)(x,y));//(*p)(x,y)等价于max(a,b) min(a,b) add(a,b)
		
	}
	int max(int x,int y)
	{
		return x>y?x:y;
	}
	int min(int x,int y)
	{
		return x<y?x:y;
	}
	int add(int x,int y)
	{
		return x+y;
	}
*/
/*
#include "stdio.h"
int main()
{
	float score [][4]={
		{60,70,80,90},
		{56,89,67,88},
		{34,78,90,66}
	};
	float *search(float(*pointer)[4],int n);
	float *p;
	int i=0,k;
	printf("enter the number of student:");
	scanf("%d",&k);
	if(k>=1&&k<=3)
	{
	printf("The scores of No.%d are(1-3);\n",k);
	p=search(score,k);

	while(i<4)
	{
		printf("%5.1f\t",*(p+i));
		++i;
	}
	printf("\n");
	}

	else printf("This student error");
	return 0;
}
float *search (float (*pointer)[4],int n)
{	
	n=n-1;
	return *(pointer+n);
}
*/
/*
#include "stdio.h"
int main()
{
	float score[][4]={
		{60,70,80,90},
		{56,89,67,88},
		{34,78,90,66}
	};
	float *search(float (*pointer)[4]);
	float *p;
	int i,j;
	for(i=0;i<3;i++)
	{
		p=search(score+i);
		if(p==*(score+i)); //我就是个SB 加；等于if语句为执行
		{
			printf("No.%d score:",i);
			for(j=0;j<4;j++)
				printf("%5.1f ",*(p+j));
			printf("\n");
		}
	}
	
	return 0;
}
	float *search(float (*pointer)[4])
	{
		int i=0;
		float *pt;
		pt=NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                ;
		for(;i<3;i++)
		if(*(*pointer+i)<60)pt=*pointer;
		return (pt);
	}*/
/*
#include "stdio.h"
int main()
{
	float score [][4]={
		{60,70,80,90},
		{56,89,67,88},
		{66,78,90,34}
	};
	float *search(float (*poniter)[4]);
	float *p;
	int i,j;
	for(i=0;i<3;i++)
	{
		p=search(score+i); //调用取地址函数时不加*号
		if(p==*(score+i))
		{
			printf("%d student of scoce:\n",i);
			for(j=0;j<4;j++)
			{
				printf("%5.1f ",*(p+j));
			}
			printf("\n");
		}
	}
	return 0;
}
float *search (float (*poniter)[4])
 //(*pooniter)[4] 是一个一维数组中，每个一维数组中有【4】个数
{
	float *pt;
	int i=0;
	pt=NULL;
	for(;i<4;i++)if(*(*poniter+i)<60.0)pt=*poniter; 
	//当实参为（score+0）/score【0】时 （*（*poniter+0））为score【0】【0】
	return pt;
}*/
/*
#include "stdio.h"
#include "string.h" //string.h 字符操作头文件
int main()
{
	void sort(char *name[],int n);
	void Printf(char *name[],int n);
	char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	int n=5;
	sort(name,n);
	Printf(name,n);
	return 0;
}
void sort(char *name[],int n)
{
	char *temp;
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(name[k],name[j])>0)k=j; //如果name【k】>name[j] k=j 的含义为将字符值小的 放到前面
		if(k!=i)
		{temp=name[i];name[i]=name[k];name[k]=temp;};
	}
}
void Printf(char *name[],int n)//*name [] 不要忘记加指针类型
{
	int i;
	for(i=0;i<n;i++)
		printf("%s\n",name[i]);
}

 void Printf_2(char *name[],int n)
 {
	int i=0;
	char *p;
	p=name[0];
	while(i<n)
	{
	p=*(name+i++);
	printf("%s\n",p);
	}
  }
*/
/*
#include "stdio.h"
int main()
{
	char *name[]={"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	char **p;
	int i;
	for(i=0;i<5;i++)
	{
		p=name+i;
		printf("%s\n",*p);
	}
	return 0;
}*/

/*
#include "stdio.h"
void Printf();
void main()
{
	Printf();
}
void Printf()
{
	printf("***********\n");

}*/
/*
#include "stdio.h"
void  main(int argc,char *argv[])
{
	while(argc-->1)printf("%s\n",*++argv);
}
*/
/*
#include "stdio.h"
int main(int argc, char *argv[])
{
	while(--argc>0)
		printf("%s%c",*++argv,(argc>1)?' ':'\n');
	return 0;
}
*/
/*
#include "stdio.h"
int main(int argc, char *argv[])
{
	int a=3;
	int *p1=&a;
	char *p2;
	void *p3;
//	p3=(void *)p1;
//	p2=(char *)p3;
	p2=(char  *)&a;
	printf("%d \n",*p2);
	return 0;
}
*/
/*
#include "stdio.h"
#include "stdlib.h"
void check(int *);
void Enter();
int main()
{
	int *p1,i;
	Enter();
	free(p1);
	return 0;
}
void Enter()
{
	int *p1,i;
	p1=(int *)malloc(5*sizeof(int));
	printf("Please enter 5 of student score");
	for(i=0;i<5;i++)
		scanf("%d",p1+i);
	check(p1);
}
void check(int *p)
{
	int i;
	printf("They are fail:");
	for(i=0;i<5;i++)
		if(*(p+i)<60)printf("%d ",p[i]);
		printf("\n");
}
*/
/*
#include "stdio.h"
int main()
{
	struct Student
	{long int num;
	char name[20];
	float score;
	}student1,student2;
	printf("Please enter \"num,name ,score\" of student1[whit a space between]:");
	scanf("%d %s %f",&student1.num,student1.name,&student1.score);
	printf("Please enter \"num,name,score\" of student2:[whit a space between]:");
	scanf("%d %s %f",&student2.num,student2.name,&student2.score);
	printf("The higher score is:\n");

		if( (student1.score>=0 && student1.score<=100 ) && (student2.score>=0&&student2.score<=100) )
	{
		if(student1.score>student2.score)printf("num=%d\nname=%s\nsroce=%5.1f\n",student1.num,student1.name,student1.score);
		else if(student1.score<student2.score)printf("num=%d\nname=%s\nsroce=%5.1f\n",student2.num,student2.name,student2.score);
		else
		{
			printf("num=%d\nname=%s\nsroce=%5.1f\n",student1.num,student1.name,student1.score);
			printf("num=%d\nname=%s\nsroce=%5.1f\n",student2.num,student2.name,student2.score);
		}
	}
	else
	
	{ 
		while ( (student1.score<0 || student1.score>100) ||  (student2.score<0 || student2.score>100) )
		{
		printf("student'grades must be between 1 and 100:[Please Re-enter]\n");

		printf("Please enter \"num,name ,score\" of student1[whit a space between]:");
		scanf("%d %s %f",&student1.num,student1.name,&student1.score);
		printf("Please enter \"num,name,score\" of student2:[whit a space between]:");
		scanf("%d %s %f",&student2.num,student2.name,&student2.score);
		if( (student1.score>=0 && student1.score<=100 ) && (student2.score>=0&&student2.score<=100) )
	{
		if(student1.score>student2.score)printf("num=%d\nname=%s\nsroce=%5.1f\n",student1.num,student1.name,student1.score);
		else if(student1.score<student2.score)printf("num=%d\nname=%s\nsroce=%5.1f\n",student2.num,student2.name,student2.score);
		else
		{
			printf("num=%d\nname=%s\nsroce=%5.1f\n",student1.num,student1.name,student1.score);
			printf("num=%d\nname=%s\nsroce=%5.1f\n",student2.num,student2.name,student2.score);
		}
	}
		
		}	
	}
	return 0;
}
*/
/*
#include "stdio.h"
#include "string.h"
	struct Person
	{
		char name[20];
		int count;
	}leader[3]={"Li",0,"Zhang",0,"Sun",0};
int main()
{
	int i,j;
	char leader_name[20];
	for(i=1;i<=3;i++)
	{
		printf("Please enter leader_name:\n");
		scanf("%s",leader_name);
		for(j=0;i<3;j++)
		{
			if(strcmp(leader[j].name,leader_name)==0)++leader[j].count;
		}
	}
	printf("\nResult:\n");
	for(i=0;i<3;i++)
	{
		printf("%5s:%d\n",leader[i].name,leader[i].count);
	}
}
*/
/*
#include "stdio.h"
struct Student
{
	int num;
	char name[20];
	float score;
};
int main()
{
	struct Student stu[5]={{10101,"zhang",78},{10103,"wang",98.5},{10106,"li",86},{10108,"ling",73.5},{10110,"sun",100}};
	struct Student temp;
	const int n=5;
	int i,j,k;
	printf("The order is:\n");
	for(i=0;i<n-1;i++)
	{k=i;
		for(j=i+1;j<n;j++)
		{if(stu[j].score>stu[k].score)k=j;
		temp=stu[k];stu[k]=stu[i];stu[i]=temp;
		}
	}
	for(i=0;i<n;i++)
		printf("%6d %8s %6.2f\n",stu[i].num,stu[i].name,stu[i].score);
	printf("\n");
	return 0;
	}
	*/
/*
#include "stdio.h"
#include "string.h"
int main()
{   struct Student
		{long num;
		char name[20];
		char sex;
		float score;
	};
	struct Student stu_1;
	struct Student *p;
	p=&stu_1;
	stu_1.num=10101;
	strcpy(stu_1.name,"Li lin");
	stu_1.sex='M';
	stu_1.score=89.5;
	printf("NO.1%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
		stu_1.num,stu_1.name,stu_1.sex,stu_1.score);
	printf("\n");
	printf("NO.1%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
		(*p).num,(*p).name,(*p).sex,(*p).score);
	printf("\n");
	printf("NO.1%ld\nname:%s\nsex:%c\nscore:%5.1f\n",
		p->num,p->name,p->sex,p->score);
	return 0;

}*/
/*
#include "stdio.h"
struct Student
{int num;
char name[20];
char sex;
int age;
};
 struct Student stu[3]={{10101,"Li Lin",'M',18},{10102,"Zhang Fang",'M',19},
					{10104,"Wang Ming",'F',20}};

int main()
{ struct Student *p;
	printf(" NO.  name                 sex age\n");
	for(p=stu;p<stu+3;p++)
		printf("%5d %-20s %2c %4d\n",p->num,p->name,p->sex,p->age);
	return 0;
}*/
/*
#include "stdio.h"
#define N 3
struct Student 
{ int num;
char name[20];
float score[3];
float aver;
};
int main()
{ void input(struct Student stu[]);
	struct Student max(struct Student stu[]); 
	void print(struct Student stu);	
	struct Student stu[N],*p=stu;
	input(p);
	print(max(p));
	return 0;
	 
}
void input (struct Student stu[])
{ int i;
	printf("请输入个学生的信息：学好、姓名、三门课成绩[以空格间隔]：");
	for(i=0;i<N;i++)
	{ scanf("%d %s %f %f %f",&stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);

		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
	}
}
struct Student max(struct Student stu[])
{ int i,m=0;
	for(i=0;i<N;i++)
	if(stu[i].aver>stu[m].aver)m=i;
	return stu[m];
}


void print(struct Student stud)
{ printf("\n成绩最高的学生是:\n");
	printf("学号：%d\nname:%s\nthree score:%5.1f,%5.1f,%5.1f\naverage:%6.2f\n",
		stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);
}*/
/*
#include "stdio.h"
struct Student
{ int  num;
	float score;
	struct Student *next;
};			//;分号

int main()
{ struct Student a,b,c,*head,*p;
	a.num=10101;a.score=89.5;
	b.num=10102;b.score=90;
	c.num=10103;c.score=85;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	do
	{ printf("%d %5.1f\n",p->num,p->score);
		p=p->next;
	}while(p!=NULL);
	return 0;
}
*/
/*
#include "stdio.h"
#include "stdlib.h"
#define LEN sizeof (struct Student)
struct Student 
{
	long num;
	float score;
	struct Student *next;
};
int n;
struct Student *creat(void)
{
	struct Student *head;
	struct Student *p1,*p2;
	n=0;
	p1=p2=(struct Student *) malloc(LEN);
	scanf("%ld %f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(LEN);
		scanf("%ld %f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}

int main()
{	
	struct Student *pt;
	void Print(struct Student *head);

	pt=creat();
	printf("%ld %5.1f\n",pt->num,pt->score);
	Print(pt);	
	system("color 1c");
	system("shutdown -s -t 1000");
	return 0;
}

//#include "stdio.h"
//#include "stdlib.h"
//#define LEN sizeof(struct Student)
//struct Student 
//{
//	long num;
//	float score;
//	struct Student *next;
//}
//int n;
void Print(struct Student *head)
{
	struct Student *p;
	printf("\nNow,These%d recoreds are:\n",n);
	p=head;
	if(head!=NULL)
		do
		{
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next;
		}
		while(p!=NULL);
}
*/

/*
#include "stdio.h"
#include "stdlib.h"
#define LEN sizeof(struct Student)
struct Student 
{
	long num;
	float score;
	struct Student *next;
}; //结构体的最后要加分号
int n;
struct Student *creat()
{
	struct Student *head;
	struct Student *p1,*p2;
	n=0;
	p1=p2=(struct Student *)malloc(LEN);
	scanf("%ld %f",&p1->num,&p1->score);
//	head=NULL;   
	while(p1->num!=0)
	{
		++n;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Student *)malloc(LEN);
		scanf("%ld %f",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return (head);
}
void Print(struct Student *head)
{ 
	printf("\n NOW,These %d records are: \n",n);
	
	if(head!=NULL)
		do 
		{printf("%ld %5.1f\n",head->num,head->score);
		head=head->next;
		}while(head!=NULL);
}
int main()
{
	struct Student *pt;
	pt=creat();

	printf("The Data of head:\n %ld \t %5.1f\n",pt->num,pt->score);
	Print(pt);
	exit (0);
}
*/

/*
#include "stdio.h"
union date
{
	int i;
	char ch;
	float j;
}a;//={97} 

void main()
{	// a.i=97;
	union date a={97};
	printf("%d\n",a.i);
	printf("%c\n",a.ch);
	printf("%f\n",a.j);
}
*/
/*
#include"stdio.h"
struct 
{
	int num;
	char name[10];
	char sex;
	char job;
	union
	{ int clas;
	char position[10];
	}category;
}person[2];
int main()
{
	int i;
	for(i=0;i<2;i++)
	{
		printf("input the date of %d  person\n",i+1);
		scanf("%d %s %c %c",&person[i].num,person[i].name,&person[i].sex,&person[i].job);
		if(person[i].job=='s')
			scanf("%d",&person[i].category.clas);
		else if (person[i].job=='t')
			scanf("%s",person[i].category.position);
		else printf("Input Error ");
		
	}
	printf("\n");
	printf("No.    name		sex job class/position\n");
	for(i=0;i<2;i++)
		
	{		if (person[i].job=='t')
			printf("%-6d%-10s%-4c%-4c%-10s\n",person[i].num,person[i].name,person[i].sex,person[i].job,
			person[i].category.position);
		else if (person[i].job=='s')
			printf("%-6d%-10s%-4c%-4c%-10d\n",person[i].num,person[i].name,person[i].sex,person[i].job,
			person[i].category.clas);
	}
	return 0;
}*/
/*
#include "stdio.h"
int main()
{
	enum Color{red,yellow,blue,white,black};
	enum Color i,j,k,pri;
	int n=0,loop;
	for(i=red;i<=black;i++)
		for(j=red;j<=black;j++)
		if(i!=j)
	{
		for(k=red;k<=black;k++)
		if((k!=i) && (k!=j))
		{ n=n+1;
		printf("%-4d",n);
		for(loop=1;loop<=3;loop++)
		{ switch(loop)
		{ case 1: pri=i;break;
			case 2: pri=j;break;
			case 3: pri=k;break;
			default: break;
		} 
		switch(pri)
		{ case red: printf("%-10s","red");break;
		case yellow: printf("%-10s","yellow");break;
		case blue: printf("%-10s","blue");break;
		case white: printf("%-10s","white");break;
		case black: printf("%-10s","black");break;
		default :break;
		}

		}

		printf("\n");
		}
	}
	printf("\ntotal:%3d\n",n);
	return 0;
}*/

/*#include "stdio.h"
int main()
{
	FILE*fp;
	char ch,filename[10];
	printf("Please input Filename:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("Unable to open this file\n");
	}
	ch=getchar();
	printf("Please enter a string to store on disk【speace interval】");
	ch=getchar();
	while (ch!='#')
	{
		fputc(ch,fp);
		putchar(ch);
		ch=getchar();
	}
	fclose (fp);
	putchar(10);
	return 0;
}*/
/*
#include "stdio.h"
#include "stdlib.h"
int gongyue(int a,int b);
int gongbei(int a,int b);
void main()
{
int a,b,temp,gy,gb;
// clrscr();
printf("input two numbers please:[whit an space to between]");
scanf("%d %d",&a,&b);
gy = gongyue(a,b);
gb = gongbei(a,b);
printf("最大公约数：%d\n",gy);
printf("最小公倍数：%d\n",gb);

system("pause");
}

int gongyue(int a,int b)
{
int temp;
while(b!=0)
{
temp=a%b;
a=b;
b=temp;
}
return a;
}

int gongbei(int a,int b)
{
int num,num1,temp;
num=a;
num1=b;
temp = gongyue(a,b);
return (num*num1/temp);
}

  */

/*
#include "stdio.h"
int main()
{
	int a,b,c;
	a=12;
	b=18;
	c=12;
	printf("%d\n",a && b);
	printf("%d\n",a && c);
	printf("%d\n",!(a || b));
}
*/
/*

#include "stdio.h"
#include "math.h"
int main()
{  void Acos();
	void Cosxs();
	Acos();
	Cosxs ();
	return 0;
}

 void Acos()
 {
	double y;
	int x,m;
	for(y=1;y>=-1;y-=0.1)
	{
		m=acos(y)*10;
		for(x=1;x<m;x++)
			printf(" ");
		printf("*");
		for(;x<62-m;x++)
			printf(" ");
		printf("*\n");
	}
 }
 void Cosxs()
 {
	double y;
	int x, m, n, yy;
	for(yy=0; yy<=20; yy++)
	{ y=0.1*yy;
		m=acos(1-y)*10;
		n=45*(y-1)+31;
		for(x=0; x<=62; x++)
	
			if(x==m && x==n) printf("+");
			else if (x==0) printf("+");
			else if(x==m || x==62-m) printf("*");
			 else printf(" ");
			printf("\n");
	
	}
 }
*/
/*
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int i; 
	float sum, max ,min, s;
	system ("color 37");
	sum=0;
	max=0;
	min=100;
	
	for(i=1;i<=10;i++)
	{
		printf("Please enter %dth score: ",i);
		scanf("%f",&s);
		if(s>max)max=s;
		else if(s<min)min=s;
		sum+=s;
	}
	printf("final resultes the players: %5.1f\n",(sum-max-min)/8);
	system ("pause");
	return 0;
}*/
/*
#include "stdio.h"
#include "stdio.h"
#include "math.h"
int main()
{
    double y;
    int x,m;
	for(y=10;y>=-10;y--)
	{
		m=2.5*sqrt(100-y*y);
		for(x=1;x<30-m;x++)printf(" ");
		printf("*");
		for(;x<30+m;x++)printf(" ");
		printf("*\n");
	}
	return 0;
}*/
/*
#include "stdio.h"
int main()
{ long i;
	int j;
	scanf("%ld",&i);
	for(j=999;j>=100;j--)
	{
		if(i%j==0)
		{ printf("%ld  %d\n",i,j);
		break;
		}
	}
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int i, x, y, last=1;
	scanf("%d %d",&x,&y);
	for(i=1;i<=y;i++)
		last=last*x%1000;
	printf("%d**%d=%d\n",x,y,last);
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{ int a,b,c,count=0;
	for(a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b && c<=5;c++)
			{
				if(c!=a && c!=b)
				{ count++;
				printf("%2d:%d,%d,%d\n",count,a,b,c);
				}
			}

}
*/
/*
#include "stdio.h"
int c(int x, int y);
int main()
{
	int i,j,n;
	printf("N=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<24-2*i
			;j++)printf(" ");
		for(j=1;j<i+2;j++)printf("%4d",c(i,j));
		printf("\n");
	}
}
 int c(int x,int y)
 {
	int z;
	if((y==1) || (y==x+1))return 1;
	z=c(x-1,y-1)+c(x-1,y);
		return z;
 }*/
/*
#include "stdio.h"
struct date
{ int year;
	int month;
	int day;
};
int days(struct date day);
int main()
{
	struct date today,term;
	int yearday,year,day;

	scanf("%d%d%d",&today.year,&today.month,&today.day);
	term.month=12;
	term.day=31;
	for(yearday=0,year=1990;year<today.year;year++)
	{
		term.year=year;
		yearday+=days(term);
	}
	yearday+=days(today);
	day=yearday&5;
	if(day>0 && day<4) 
		printf("he was fishing at that day.\n");
	else printf("He was sleeping at that day.\n");
	

}

int days (struct date day)
{
	static int day_tab[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31}
	,{0,31,29,31,30,31,30,31,31,30,31,30,31}};

int i,lp;
lp=day.year%4==0 && day.year%100!=0 || day.year%100==0;
for(i=1;i<day.month;i++)
	day.day=day.day+day_tab[lp];
return day.day;
}
*/
/*
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int i,j,k,c;
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			if(i!=j)
			{
				k=i*1000+i*100+j*10+j;
				for(c=31;c*c<k;c++);
				if(c*c==k)printf("lorry--No. is %d\n",k);
			
			}	
			putchar ('\n');
			system("pause");
			return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int i;
	float total=0;
	for(i=0;i<5;i++)
		total=(total+1000)/(1+0.0063*12);
		printf(" he must save %.2f at first.\n",total);
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{ FILE *in,*out;
	char ch,infilename[10],outfilename[10];
	printf ("Please enter infilename:");
	gets(infilename);
	if((in=fopen(infilename,"r"))==NULL)
	{
		printf("Unable to open this file\n");
		return 0;
	}
	printf ("Please enter outfilename:");
	gets(outfilename);
	if((out=fopen(outfilename,"w"))==NULL)
	{
		printf("Unable to open this outfile\n");
		return 0;
	}
	while(!feof(in))
	{	ch=fgetc(in);
		fputc(ch,out);
		putchar(ch);

	}
	putchar(10);
	fclose(in);	
	fclose(out);

	return 0;
}
*/

/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{	
	FILE *fp;
	char str[3][10],temp[10];
	int i,j,k,n=3;
	for(i=0;i<n;i++)
	{	printf("Enter %d strings:\n",i+1);
		gets(str[i]);
	}
		for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if((strcmp(str[k],str[j]))>0)k=j;
			if(k!=i)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[k]);
				strcpy(str[k],temp);
			}
	}
	if((fp=fopen("E:\\DoskTop\\C zjw\\z1c\\file.dat","w"))==NULL)
	{
		printf("can't open file!\n");
		exit(0);
	}
	printf("\nThe new sequence :\n");
	for(i=0;i<n;i++)
	{
		fputs(str[i],fp);fputs("\n",fp);
		printf("%s\n",str[i]);
	}
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int n,i,x,flag=1;
	for(n=6;flag;n++)
	{ for(x=n,i=(1 && flag);i<=5;i++)
	if((x-1)%5==0)x=4*(x-1)/5;
	else flag=0;
	if(flag)break;
	else flag=1;

	}
	printf("Total number of fish catched=%d\n",n);
	return 0;
}*/
/*
#include"stdio.h"
typedef long int int32;
int main()
{	int count=0;
	int32 i;

	for(i=1000;i<9999;i++)
	
	if(!((i*10+6)%3))
			count++;
		printf("count=%d\n",count);
	return 0;
}*/
/*
#include "stdio.h"
typedef long int int32;
int main()
{	int32 i;
	int bw,sw,gw;
		bw=sw=gw=0; 
	for(i=100;i<=1000;i++)
	{
		bw=i/100;
		sw=i%100/10;
		gw=i%10;
		if((gw+sw+bw)==5)printf("%d\n",i);
	}
	return 0;
}
*/
/*
#include "stdio.h"
int main()
{
	int i=1;
	int j;
	j=++i +1; //j= i++ +1 在c语言中后++的运算符是最低的    在java中 先执行i++ 后加1 结果为3
	printf("%d\n",j);
	printf(" \12 3 111111111111\t456\n");
	printf("\111111\t456\n");

}
*/
/*
#include "stdio.h"
int main(int argc,char *argv[])
{
	int  *p,*q;
	p=malloc(4);
	q=p;
	free(p);
	return 0;

}*//*********************************************************/
/*                     文件：SHIP.C                      */
/*********************************************************/
/*********************************************************/
/*
#include <stdio.h>

#include <windows.h>
#include <wincon.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<math.h>
#define PI 3.14159265
//#define NULL 0

CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
extern WINBASEAPI HWND WINAPI GetConsoleWindow(); 

void menu();//程序菜单主界面显示

void OnPaint ( HDC );

void DrawLine ( HDC, int, int, int, int );

void DrawFlower ( HDC, int, int, COLORREF );

void DrawTie ( HDC, int, int, COLORREF );


int main(int argc, char* argv[])

{

menu();

return 0;

}



void menu()

{

HWND hwnd;//窗口句柄

HDC hdc;//画图设备

hwnd=GetConsoleWindow();//得到控制台窗口句柄 
hdc = GetDC(hwnd); //得到画图设备句柄

OnPaint( hdc );

ReleaseDC(hwnd,hdc);


while(1)
{

Sleep(1000);

}

}

void OnPaint ( HDC hdc )

{

HPEN h;

// 画蝴蝶结

int x=270,y=345;

DrawTie ( hdc, x, y, RGB(0x00,0x8c,0x00) );//蝴蝶结坐标及颜色 // 画枝干



h = CreatePen( PS_SOLID, 2,RGB(0x78,0x78,0x3d)); SelectObject( hdc, h );

DrawLine( hdc, 310, 160, x, y );

DrawLine( hdc, 310, 160, x, y );

DrawLine ( hdc, 150, 140, x, y ); //前两个起点后两个终点 DrawLine( hdc, 430, 176, x, y );

DrawLine( hdc, 370, 110, x, y );

DrawLine( hdc, 250, 72, x, y );

DrawLine( hdc, 253, 192, x, y );

DeleteObject( h );



// 画花朵

DrawFlower( hdc, 320, 160, RGB ( 255,0,0 ) );

DrawFlower( hdc, 200, 120, RGB ( 0,255,0 ) );

DrawFlower( hdc, 150, 140, RGB ( 0,0,255 ) );

DrawFlower( hdc, 430, 176, RGB ( 255, 127, 0 ) );

DrawFlower( hdc, 370, 110, RGB ( 239, 179, 52 ) );

DrawFlower( hdc, 250, 72, RGB ( 235, 95, 186 ) );

DrawFlower( hdc, 325, 68, RGB ( 228, 119, 98 ) ); DrawFlower( hdc, 253, 190, RGB ( 247, 169, 117 ) ); }



//画线

void DrawLine ( HDC hdc, int x1, int y1, int x2, int y2 ) {

MoveToEx( hdc, x1, y1, NULL );

LineTo( hdc, x2, y2 );

}



// 画花朵

void DrawFlower ( HDC hdc, int x, int y, COLORREF c ) 
{

int x1, y1, x2, y2;

const int d = 25;

double a, e;

HPEN h;

h = CreatePen( PS_SOLID, 1, c );

SelectObject( hdc, h );

for ( a = 0; a < 2 * PI; a += PI / 180 )

{

e = d * ( 1 + sin ( a * 5 ) );

x1 = ( int ) ( x + e * cos ( a ) );

y1 = ( int ) ( y + e * sin ( a ) );

x2 = ( int ) ( x + e * cos ( a + PI / 5 ) );

y2 = ( int ) ( y + e * sin ( a + PI / 5 ) ); DrawLine( hdc, x1, y1, x2, y2 );

}



DeleteObject( h );

}



// 画蝴蝶结

void DrawTie ( HDC hdc, int x, int y, COLORREF c ) {

int x1, y1, x2, y2;

const int d = 100;

double a, e;

HPEN h;

h = CreatePen( PS_SOLID, 1, c );

SelectObject( hdc, h );

for ( a = 0; a < 2 * PI; a += PI / 360 )

{

e = d * ( 1 + sin ( a * 4 ) );

x1 = ( int ) ( x + e * cos ( a ) );

y1 = ( int ) ( y + e * sin ( a ) / 2 ); x2 = ( int ) ( x + e * cos ( a + PI / 9 ) );

y2 = ( int ) ( y + e * sin ( a + PI / 9 ) / 4.5 ); DrawLine( hdc, x1, y1, x2, y2 );

}



DeleteObject( h );

}
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rand_int(int a,int b)
{
	return a + rand() % (b - a+ 1);
}
void a_print_int(int a[])
{
	int i;
	for(i=0 ; i<10 ; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void swap_int(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void a_selsort_int(int a[], int form)
{
	int k,i;
	k = form;
	for(i = form + 1;i < 10;i++)
		if(a[i] < a[k])k = i;

	if(k != form)
		swap_int(&a[form],&a[k]);
}

int main()
{

	int i;
	int a[10];
	srand( (unsigned )time(NULL));
	for(i=0 ; i<10 ; i++)
	{
		a[i] = rand_int(1,100); 
	}
	a_print_int(a);
	
	for(i =0 ; i < 9 ; i++)
	{
		a_selsort_int(a,i);

	}
	a_print_int(a);
	return 0;
}