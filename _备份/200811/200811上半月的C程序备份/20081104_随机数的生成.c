#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	void note();
	int a,i=0,n,k=19881211;
	int t1,t2;
	int q,choice;
	printf("\n===随机数的输出===\n\n");
	note();		//输出公告!
start:
	srand((unsigned)time(NULL)); 
	a=rand();
	printf("\n\n程序正在为您计算随机数,请您耐心等待!\n\n");
	do
	{
		if(a%2==0)
			a++;
		else
			a++;
		a+=1234;
		a*=123456789;
		a%=10000;
		k-=1211;
		t1=1;
		t2=1;
		if(a<10000&&a>1000)
			t1=0;
		if(k<0)
			t2=0;
		if(k>200811)
			printf("%d\t",a);
	}while(t1||t2);

	note();
	q=2000;	
	
	printf("\n\n计算机已经根据您输入的数生成出来一个随机数%d\n\n",a);
	printf("现在,请您输入您猜想的数字:\n");
	do
	{
		scanf("%d",&n);
		if(n==a)
			printf("\n恭喜您输入正确!");
		else if(n>a)
			printf("\n您输入的数字有点大!再试试吧,加油!\n\n");
		else if(n<a)
			printf("\n您输入的数字有点小!再试试吧,加油!\n\n");
		i++;
		q/=2;
	}while(n!=a);
	printf("正确答案就是:%d",a);
	printf("\n您共输入了%d回",i);
	if(i<=10)
		printf("您将获得%d元钱\n请您联系:郭一实!\n\n",q);
	else
		printf("\n唉,您没有获奖,");
be:
	printf("是否继续进行游戏?\n(继续:输入1/离开:输入0)");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:goto start;break;
	case 0:goto end;break;
	default:printf("您的输入有误,请重新输入!\n");
		goto be;
	}
end:
	printf("\n\n\n谢谢您的使用!\n\n\n");
}

void note()		//输出公告用
{
	int p=3,q=1000,l=1;	
	printf("\n游戏规则:\n\n");
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
}
