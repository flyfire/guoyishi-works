#include <stdio.h>
void main(void)
{
	int i,k=0;
	int a,b,c,d;
	for(i=10000;i<100000;i++)
	{
		a=i/10000;
		b=i/1000-a*10;
		c=i/100-a*100-b*10;
		d=i/10-a*1000-b*100-c*10;
		if((a+b+c+d+6)%3==0&&i%10==6)
		{
			printf("%d满足条件\n",i);
			k++;
		}
	}
	printf("共有%d个满足条件的数\n",k);
}