#include <stdio.h>
void main()
{
	int i,j,k,sum;
	printf("===完数的输出===\n");
	printf("程序为您找到的1~10000完数为:\n");
	for(i=1;i<=10000;i++)			//对i进行判断
	{
		for(j=1,sum=0;j<i;j++)		//求解出i的因子
		{
			if(i%j==0)				//判断是不是因子
				sum+=j;
		}
		if(i==sum)					//判断是不是完数
		{
			printf("%d ",i);
			k++;
		}
	}
	printf("\n\n\n谢谢您的使用!\n\n\n");
}

