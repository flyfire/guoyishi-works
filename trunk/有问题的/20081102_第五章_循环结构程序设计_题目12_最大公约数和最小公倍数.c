#include <stdio.h>
void main()
{
	int m,n,i,p,q,x,y;
	printf("===求最大公约数和最小公倍数===\n");
	printf("请您输入俩个数:\n");
	scanf("%d%d",&m,&n);
	if(m>n)
	{
		x=n;
		y=m;
	}
	else
	{
		x=m;
		y=n;
	}
	for(i=2;i<=x;i++)
	{
		if(n%i==0&&m%i==0)
			p=i;
	}
	for(i=y;;i++)		//?????????????????????????????用不用改成 for(i=y;i<m*n;i++)
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

