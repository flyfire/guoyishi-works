#include <stdio.h>
void main()
{
	int m,n,i,j,x,y;
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
	for(i=x;i>=1;i--)		//求解最大公约数
	{
		if(n%i==0&&m%i==0)
			break;
	}
	for(j=y;;j++)			//求解最小公倍数
	{
		if(j%m==0&&j%n==0)
			break;
	}
	printf("\n\n你输入的%d和%d的最大公约数为:%d 最小公倍数:%d\n\n",m,n,i,j);
	printf("\n\n\n谢谢您的使用!\n\n\n");
}

