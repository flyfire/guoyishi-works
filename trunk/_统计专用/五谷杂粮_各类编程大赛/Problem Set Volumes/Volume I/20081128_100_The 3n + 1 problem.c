#include <stdio.h>
int main()
{
	int length(int x,int y);
	int i,j;
	int str[4][3];
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			if(j==2)
			{
				str[i][j]=length(str[i][j-2],str[i][j-1]);
				break;
			}
			scanf("%d",&str[i][j]);
		}
	}
	for(i=0;i<4;i++)
			printf("%d %d %d\n",str[i][0],str[i][1],str[i][2]);

}
int length(int x,int y)
{
	int i,j,k,max=0;
	for(i=x;i<=y;i++)
	{
		for(j=i,k=1;j!=1;k++)
		{
			if(j%2==1)
				j=j*3+1;
			else
				j/=2;

		}
		if(k>max)
			max=k;
	}
	return (max);

}