#include <stdio.h>
#include <math.h>
void main(void)
{
	int small(int);
	int i,j,k,flag,count=0;
	for(i=1993;i>1898;i--)
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
			{
				k=small(i);
				if(k)
				{
					printf("(%d)%d-%2d=%d\n",++count,i,k,i-k);
				}
			}
	}
}
int small(int i)
{
	int j,k,flag;
	for(k=3;k<100;k+=2)
	{
		for(j=2,flag=1;j<=sqrt(k);j++)
		{
			if(k%j==0)
			{
				flag=0;
				break;
			}
		}
		if(i-k==1898&&flag)
			return (k);

	}
	return (0);
}