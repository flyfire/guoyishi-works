#include <stdio.h>
#define M 10

int main()
{
	void fun(int,int);
	int m,i,j;
	int a[M][M];
	printf("Input m:");
	scanf("%d",&m);
	fun(a,m);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}

void fun(int a[][M],int m)
{
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<m;j++)
			a[i][j]=(i+1)*(j+1);
}