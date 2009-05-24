#include <stdio.h>
void main()
{
	int m,n,i,p,q,x,y;
	printf("===求最大公约数和最小公倍数===\n");
	printf("请您输入俩个数:\n");
	scanf("%d%d",&m,&n);
	if(m>n)					//把m和n中最大的赋给y,小的赋给x
	{
		x=n;
		y=m;
	}
	else
	{
		x=m;
		y=n;
	}
	for(i=2;i<=x;i++)		//求解最大公约数
	{
		if(n%i==0&&m%i==0)
			p=i;
	}
	for(i=y;;i++)			//求解最小公倍数
	{
		if(i%m==0&&i%n==0)
		{
			q=i;
			break;
		}
	}
	printf("\n\n你输入的%d和%d的最大公约数为:%d 最小公倍数:%d\n\n",m,n,p,q);
	printf("\n\n\n谢谢您的使用!\n\n\n");
}

