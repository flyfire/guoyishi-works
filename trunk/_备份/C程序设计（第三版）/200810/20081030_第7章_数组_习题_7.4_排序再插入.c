#include <stdio.h>
#define SIZE 10
void main()
{
	int i,n,str[SIZE],temp;
	printf("===对已排序的数组插入值再排序===\n");
	printf("请您先输入一个%d位的数组！\n",SIZE); /*先输入个有规律的数组，有空对其进行改变*/
	for(i=0;i<SIZE;i++)
	{
		printf("\n请您输入第%d个数字:",i+1);
	scanf("%d",&str[i]);
	}
	printf("请您输入要插入的数字：\n");
	scanf("%d",&n);
	for(i=0;i<SIZE;i++)
	{
		if(n>=str[i]&&n<=str[i+1])
			temp=i;
	}

	for(i=0;i<SIZE;i++)//程序有问题！
	{
		if(i==temp)
		{
			printf("%d ",n);
		}

		printf("%d ",str[i]);
	}

}
