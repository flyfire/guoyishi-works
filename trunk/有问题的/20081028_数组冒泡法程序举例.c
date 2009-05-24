#include <stdio.h>
#define SIZE 10
void main()
{
	int i,j,temp,str[SIZE]={0};
	printf("===“冒泡法”测试===\n首先请您输入%d个数字\n\n",SIZE);
	for(i=0;i<SIZE;i++)
	{
		printf("请您输入第%d个数：\n",i+1);/*???????为何当输入的数据时非数字时，出现错误？？？？？？？？*/
		scanf("%d",&str[i]);/*???????怎样才能判断是否输入的是数字而不是其他？？？？？？*/
	}
	printf("\n您输入的数为：\n");
	for(i=0;i<SIZE;i++)
		printf("  %d",str[i]);
	printf("\n\n程序为您转换：\n");
	printf("1>以上数组按照由大到小的顺序排列为：\n");
	for(j=SIZE;j>0;j--)
	{
		for(i=0;i<j;i++)
		{
			if(str[i]<str[i+1])
			{
				temp=str[i];
				str[i]=str[i+1];
				str[i+1]=temp;
			}
		}
	}
	for(i=0;i<SIZE;i++)
		printf("  %d",str[i]);
	printf("\n2>以上数组按照由小到大的顺序排列为：\n");
	for(i=SIZE-1;i>=0;i--)
		printf("  %d",str[i]);
	printf("\n\n\n\nPower By iStone \n\n\n\n");
}

