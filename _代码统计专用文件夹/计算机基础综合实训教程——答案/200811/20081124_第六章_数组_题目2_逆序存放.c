#include <stdio.h>
#define N 6
void main(void)
{
	int i,temp;
	int str[N];
	for(i=0;i<N;i++)
		scanf("%d",&str[i]);
	printf("WHAT YOU TYPED:\n");
	for(i=0;i<N;i++)
		printf("\t%d",str[i]);
	for(i=0;i<N-i-1;i++)
	{
		temp=str[i];
		str[i]=str[N-i-1];
		str[N-i-1]=temp;
	}
	printf("\nCHANGED:\n");
	for(i=0;i<N;i++)
		printf("\t%d",str[i]);
	printf("\n");
}