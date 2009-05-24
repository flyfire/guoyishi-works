#include <stdio.h>
void main(void)
{
	int i,j,k,l;
	int n,m;
	for(i=1;i<=9;i++)
		for(j=0;j<=9;j++)
			for(k=0;k<=9;k++)
				for(l=1;l<=9;l++)
				{
					n=i*1000+j*100+k*10+l;
					m=l*1000+k*100+j*10+i;
					if(n*9==m)
						printf("The required Number is %d\n",n);
				}
	printf("Thanks!\n\n");
}
