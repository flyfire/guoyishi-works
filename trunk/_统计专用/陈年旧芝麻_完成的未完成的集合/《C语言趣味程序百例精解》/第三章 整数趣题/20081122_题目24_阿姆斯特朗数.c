#include <stdio.h>
void main(void)
{
	int cube(int x);
	int i,j,k,m;
	int a[4]={0};
	for(i=2;i<10000;i++)
	{
		for(j=0,k=10000,m=0;k>=10;j++)
		{
			a[j]=(i%k)/(k/10);
			k/=10;
			m+=cube(a[j]);
		}
		if(i==m)
			printf("%d\n",i);
	}
}
int cube(int x)
{
	int z;
	z=x*x*x;
	return z;
}