#include <stdio.h>
int main(void)
{
	int i,n,m,sum=0;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		sum+=i;
	}
	printf("The sum from %d to %d is %d.\n",n,m,sum);
}