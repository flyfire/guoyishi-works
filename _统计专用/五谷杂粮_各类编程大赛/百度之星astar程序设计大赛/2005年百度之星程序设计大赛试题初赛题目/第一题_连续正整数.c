#include <stdio.h>
int main()
{
	int i,j,n,sum,k,flag=1;
	scanf("%d",&n);
	for(i=1;i<=n/2;i++)
		for(j=i,sum=0;j<=n/2+1;j++)
		{
			sum+=j;
			if(n==sum)
			{
				for(k=i;k<=j;k++)
					printf(k==j?"%d\n":"%d ",k);
				flag=0;
			}
				
		}
	if(flag)
		printf("NONE\n");
}