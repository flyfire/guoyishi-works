#include <stdio.h>
void main()
{
	int i=0,n,a,b,c;
	printf("===猜测随机数的游戏===\n");
	printf("请您输入三个个数,程序将根据它,计算一个随机数:\n\n");
	scanf("%d%d%d",&a,&b,&c);		//????????????怎样生成真正的随机数????????????????
	do
	{
		if(a<0)
			a=0-a;
		a+=11;
		b+=2;
		c+=3;
		b*=c;
		a=a+b+c;
		a*=135;
		a%=1000000;
	}while(a<0&&a>=20);
	printf("计算机已经根据您输入的数生成出来一个随机数\n\n");
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
	}while(n!=a);
	printf("\n正确答案就是:%d",a);
	printf("\n您共输入了%d回\n\n",i);
	printf("谢谢您的使用!\n\n\n");
}

