#include <stdio.h>
void main(void)
{
	int factorial(int x);
	int n,i,a[3],m,k;
	for(n=100;n<1000;n++)
	{
		for(i=0,k=1000,m=0;i<3;i++)
		{
			a[i]=(n%k)/(k/10);
			k/=10;
			m+=factorial(a[i]);
		}
		if(n==m)
			printf("%d=%d!+%d!+%d!\n",n,a[0],a[1],a[2]);
	}
}

int factorial(int x)
{
	int i,z=1;
	for(i=1;i<=x;i++)
		z*=i;
	return z;
}

