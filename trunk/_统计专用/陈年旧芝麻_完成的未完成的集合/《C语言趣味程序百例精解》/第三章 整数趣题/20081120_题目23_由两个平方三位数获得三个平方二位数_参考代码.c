#include <stdio.h>
#include <math.h>
void main(void)
{
	void f(int n,int *s);
	int i,t;
	int a[3],b[3];
	printf("The possible perfect squares combinations are:\n");
	for(i=11;i<=31;i++)
		for(t=11;t<=31;t++)
		{
			f(i*i,a);
			f(t*t,b);
			if(sqrt(a[0]*10+b[0])==(int)sqrt(a[0]*10+b[0])
				&&sqrt(a[1]*10+b[1])==(int)sqrt(a[1]*10+b[1])
				&&sqrt(a[2]*10+b[2])==(int)sqrt(a[2]*10+b[2]))
			{
				printf("%d and %d\n",i*i,t*t);
			}
		}
}
void f(int n,int *s)
{
	int k;
	for(k=1000;k>=10;s++)
	{
		*s=(n%k)/(k/10);
		k/=10;
	} 
}

