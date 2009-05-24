#include <stdio.h>
void main(void)
{
	int i,j,k;
	for(i=1;i<7;i++)
		for(j=0;j<7;j++)
			for(k=1;k<7;k++)
				if(k+j*7+i*7*7==i+j*9+k*9*9)
				{
					printf("The required Number is %d(10)=%d%d%d(7)=%d%d%d(9)\n",k+j*7+i*7*7,i,j,k,k,j,i);
				}
	printf("\n\nThanks!\n\n");
}