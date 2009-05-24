#include <stdio.h>

int main()
{
	int i,j,k,t,n;
	printf("Please input the number:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			t=(i+j)%n;
			for(k=0;k<n;k++)
				printf("%d ",(k+t)%n+1);
			printf("\n");
		}
		printf("\n");
	}
	return (0);
}