#include <stdio.h>
void main()
{
	int i,j;
	printf("===乘法口诀表的输出===\n");
	printf("程序为您输出您小时候的口诀表如下\n");
	printf("让您回想起您的童年!\n");
	for(i=1;i<=9;i++)							//输出9行
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-2d ",j,i,i*j);		//公式的输出
		}
		printf("\n");							//回车换行
	}
	printf("\n\n\n");
}

