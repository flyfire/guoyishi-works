#include <stdio.h>
#include <math.h>
int main()
{
	int prime(int);
	int n;
	printf("Please input:");
	scanf("%d",&n);
	printf("%d %s a prime.\n",n,prime(n)?"is":"is not");
}
int prime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}