#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int a,i=0,n,k=1211;
	int t1,t2;
	int p=3,q=1000,l=1;		//输出公告用
	printf("===随机数的输出===\n\n");
	printf("游戏规则:\n\n");
	printf("---------------------------------\n");
	printf("1>	每次游戏1元钱.\n");
	printf("2>	程序将产生一个4位随机数.\n");
	while(q>0)
	{
		printf("%d>	%d次答对奖励%d元钱.\n",p,l,q);
		l++;
		p++;
		q/=2;
	}
	printf("%d>	10次以上才答对就没有任何奖励!\n",l);
start:
	srand((unsigned)time(NULL)); 
	a=rand();
	printf("程序正在为您计算随机数,请您耐心等待!\n\n");

	do
	{
		a*=19881211;
		a%=10000;
		k-=2;
		t1=1;
		t2=1;
		if(a<10000&&a>1000)
			t1=0;
		if(k<0)
			t2=0;
		if(k>14)
			printf("%d  ",a);
	}while(t1||t2);

	p=3;		//再次赋值!
	l=1;		//再次赋值!
	q=1000;		//再次赋予q初值!

	printf("\n\n游戏规则:\n\n");
	printf("---------------------------------\n");
	printf("1>	每次游戏1元钱.\n");
	printf("2>	程序将产生一个4位随机数.\n");
	while(q>0)
	{
		printf("%d>	%d次答对奖励%d元钱.\n",p,l,q);
		l++;
		p++;
		q/=2;
	}
	printf("%d>	10次以上才答对就没有任何奖励!\n",l);

	q=2000;		//

	printf("\n\n计算机已经根据您输入的数生成出来一个随机数%d\n\n",a);
	printf("现在,请您输入您猜想的数字:\n");
	do
	{
		scanf("%d",&n);
		if(n==a)
			printf("\n恭喜您输入正确!\n\n");
		else if(n>a)
			printf("\n您输入的数字有点大!再试试吧,加油!\n\n");
		else if(n<a)
			printf("\n您输入的数字有点小!再试试吧,加油!\n\n");
		i++;
		q/=2;
	}while(n!=a);
	printf("\n正确答案就是:%d",a);
	printf("\n您共输入了%d回\n\n",i);
	if(i<=12)
		printf("您将获得%d元钱\n请您联系:郭一实!\n\n",q);
	else
	{

		printf("唉,您没有获奖,再玩一把!\n\n");
		goto start;
	}
	printf("谢谢您的使用!\n\n\n");
}