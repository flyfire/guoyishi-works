#include <stdio.h>
void main()
{
	int i,n=1;					//i表示天数,n表示第一天的瓜数
	printf("===进瓜问题===\n\n");
	for(i=10;i>1;i--)
	{
		n=(n+1)*2;				//逆向计算第一天的瓜数
	}
	printf("第一天共进了%d个瓜!\n\n",n);
	printf("详细卖瓜清单为:\n\n");
	for(i=1;i<=10;i++)			//产生纤细的卖瓜个数
	{
		if(i==10)				//对第十天进行独立输出
			printf("第%d天有%d个瓜,还剩%d个瓜\n",i,n,n);
		else					//输出1~9天的瓜数
			printf("第%d天有%d个瓜,卖掉了%d个瓜\n",i,n,n/2+1);
		n=n/2-1;

	}
	printf("\n\n谢谢您的使用!\n\n\n");

}

