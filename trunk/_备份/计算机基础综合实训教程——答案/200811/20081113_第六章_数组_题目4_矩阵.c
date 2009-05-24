#include <stdio.h>
void main(void)
{
	int i,j;
	int str[5][5]={0};	//对矩阵进行"清零"
	printf("===图形输出的效果===\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i+j==4)	//"对角线"赋值为"1"
				str[i][j]=1;
			if(i+j>4)	//右下角赋值为"2"
				str[i][j]=2;	
		}
	}	//对矩阵中的相关位置进行赋值
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",str[i][j]);
		printf("\n");
	}	//输出矩阵
	printf("\n\n谢谢您的使用!\n\n");
}