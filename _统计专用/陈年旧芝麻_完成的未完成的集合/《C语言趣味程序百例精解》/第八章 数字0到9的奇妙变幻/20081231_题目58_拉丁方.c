#include <stdio.h>

int main()
{
	int n,i,j,k,m;
	do{
		scanf("%d",&n);
	}while(n<=0);
	for(i=1;i<=n;i++)
	{
		for(j=1,k=i;j<=n;j++,k++)
		{
			if(k!=n)
				printf("%2d",k%n);
			else
				printf("%2d",k);
		}
		printf("\n");
	}
}