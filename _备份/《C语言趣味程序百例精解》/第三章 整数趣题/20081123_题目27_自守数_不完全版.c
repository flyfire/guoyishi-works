#include <stdio.h>
void main(void)
{
	int n,k,m;
	for(n=1,k=10;n<200000;n++)
	{
		if(n%k==0)
			k*=10;
		m=n*n;
		if(m%k==n)
			printf("%d*%d=%d\n",n,n,m);
	}
}