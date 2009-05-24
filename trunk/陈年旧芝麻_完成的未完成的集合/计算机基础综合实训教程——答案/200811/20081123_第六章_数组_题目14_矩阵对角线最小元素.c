#include <stdio.h>
void main(void)
{
	int str[5][5];
	int i,j,temp,m,n;
	printf("put 5*5:\n");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			scanf("%d",&str[i][j]);
		}
	//TEST!	for(i=0;i<5;i++)
	//TEST!	{
	//TEST!		for(j=0;j<5;j++)
	//TEST!		{
	//TEST!			printf("%d ",str[i][j]);
	//TEST!		}
	//TEST!		printf("\n");
	//TEST!	}
	temp=str[0][0];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(i==j||i+j==4)
			{
				//TEST!	printf("str[%d][%d]=%d\n",i,j,str[i][j]);
				if(str[i][j]<temp)
				{
					temp=str[i][j];
					m=i;
					n=j;
				}
			}
	printf("the diagonal smallest number is %d:str[%d][%d]\n",str[m][n],m,n);
}