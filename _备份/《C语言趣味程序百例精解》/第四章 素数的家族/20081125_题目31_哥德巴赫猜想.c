#include <stdio.h>
void main(void)
{
	int i,j,k,flag1,flag2;
	for(i=1900;i<=2000;i+=2)
	{
		for(j=2;j<i;j++)
		{
			for(flag1=1,k=3;k<j;k++)
				if(j%k==0)
					flag1=0;
			for(flag2=1,k=3;k<i-j;k++)
				if((i-j)%k==0)
					flag2=0;
			if(flag1&&flag2)
			{
				printf("%8d=%d+%d\n",i,j,i-j);
				break;
			}
			
		}
	}
}