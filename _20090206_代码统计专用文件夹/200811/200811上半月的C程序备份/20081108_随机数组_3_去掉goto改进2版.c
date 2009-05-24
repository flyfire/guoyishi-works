#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{	
	int str[10],str2[10],strc[10];
	int i,q,j,k,flag;
	printf("===一数组随机赋给另一数组===\n");
	for(i=0;i<10;i++)		//首先给存储p值得数组赋值
		strc[i]=21;
	for(i=0;i<10;i++)
	{
		printf("请输入第%d个数字:",i+1);
		scanf("%d",&str[i]);
		printf("\n");
		srand(time(NULL));	//根据时间产生随机数
		q=rand();			//把这个值赋值给q
		flag=1; 
		while(flag)			/////////////////////////////////////////////这个就是设置一个"开关"
		{ 
			flag=0;
			q+=1;
			q%=10;
			strc[i]=q;			//把q值赋给strc数组
			for(j=0;j<10;j++)	//判断q值之前是否存在!
			{
				if(i==j)
					continue;
				if(q==strc[j])
				{
					flag=1;
					break; 
				}
			}
		}
		str2[q]=str[i];		//最后把str赋给str2
	}
	printf("\n输出第一个数组为:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str[i]);
	printf("\n根据随机产生的对应规则:\n");
	for(i=0,k=0;i<10;i++)
	{
		printf("%2d--%-4d",i+1,strc[i]+1);
		k++;
		if(k-5==0)			//一行显示5个数
			printf("\n");
	}
	printf("\n转换后:");
	printf("\n输出第二个数组为:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str2[i]);
	printf("\n\n谢谢您的使用!\n\n");
		

}