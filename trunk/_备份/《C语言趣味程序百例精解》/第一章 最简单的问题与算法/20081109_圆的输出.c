#include <stdio.h>
#include <math.h>
void main(void)
{
	int x,y,m,i;
	double p;
	printf("===Բ�����===\n");
	for(y=10;y>=-10;y--)
	{
		p=2*sqrt(100-y*y);
		x=p+10;
		m=20-x;
		for(i=-20;i<=40;i++)
		{
			if(i==x||i==m)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");

	}
	printf("\n\n\nлл����ʹ��!\n");

}