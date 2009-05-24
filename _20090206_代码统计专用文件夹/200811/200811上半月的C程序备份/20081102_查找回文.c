#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int t1,t2;
	int i,k,m;
	t1=clock();
	printf("===查找回文数===\n");
	printf("程序为您查找出的回文数为:\n");
	for(i=1;i<1000;i++)
	{
		if(i%10==0)
			continue;
		printf("%d  ",i);

	}
	printf("\n\n\n谢谢您的使用\n\n\n");
	t2=clock();
	printf("系统运行时间为:%dms\n\n\n",t2-t1);

}