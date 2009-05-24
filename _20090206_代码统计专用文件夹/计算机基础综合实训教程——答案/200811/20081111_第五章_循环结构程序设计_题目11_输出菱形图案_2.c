#include <stdio.h>
void main(void)
{
	int i,j,r,m,n,p,q;
	printf("===菱形图案的输出===\n");
	printf("请输入要产生的'半径':");
	scanf("%d",&r);
	for(i=1;i<=2*r;i++)		//i控制行数
	{
		m=r-i;		//m和n代表上半部分的空白区域范围值
		n=r+i;
		p=i-r;		//p和q代表下半部分的空白区域范围值
		q=3*r-i;
		for(j=1;j<=2*r;j++)	//j控制列数
		{
			if(i<=r)
				if(j<=m||j>=n)
					printf("  ");
				else
					printf(" *");
			else
				if(j<=p||j>=q)
					printf("  ");
				else
					printf(" *");
		}
		printf("\n");		//实现回车换行

	}
	printf("谢谢您的使用!\n");
}