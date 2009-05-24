#include <stdio.h>
int main(void)
{
	int i,j,k,count=0;
	for(i=0;i<=20;i++)
		for(j=0;j<=(100-5*i)/2;j++)
		{
			k=100-i*5-j*2;
			if(5*i+2*j+k==100)
				printf("%d...5*%d+2*%d+1*%d\n",++count,i,j,k);
		}

}