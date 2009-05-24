#include <stdio.h>
#include <math.h>
void main(void)
{
	int i,j,flag;
	for(i=3;i<1000;i+=2)
	{
		for(j=2,flag=1;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			printf("%d is a prime.\n",i);
	}
}