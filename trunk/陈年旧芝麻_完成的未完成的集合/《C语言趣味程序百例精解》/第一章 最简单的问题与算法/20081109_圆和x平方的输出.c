#include <stdio.h>
#include <math.h>
void main(void)
{
	int x,y,m,n,n2,i;
	double p;
	printf("===圆的输出===\n");
	for(y=10;y>=-10;y--)
	{
		p=2*sqrt(100-y*y);
		x=p+10;
		m=20-x;

		n=6*sqrt(y)+10;
		n2=20-n;

		for(i=-20;i<=40;i++)
		{
			if((i==n||i==n2)&&y>=0)
				printf("#");
			else if(i==x||i==m)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");

	}
	printf("\n\n\n谢谢您的使用!\n");

}