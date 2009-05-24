#include <stdio.h>
#include <math.h>
void main(void)
{
	int n,m,flag=1;
	double hour_hand,minute_hand,angle;
	printf("===2008-2-时钟夹角问题===\n");
	while(flag)
	{
		printf("请您输入时间:");
		scanf("%d%d",&n,&m);
		hour_hand=30*n+m/2.0;
		minute_hand=m*6;
		angle=abs((double)hour_hand-(double)minute_hand);
		printf("\n\n测试!时针:%.2f,分针:%.2f,夹角:%.2f\n\n",hour_hand,minute_hand,angle);
		if(angle>180)
			angle=360-angle;
		if(n==0&&m==0)
			flag=0;
		else
			printf("在%d:%d,角度是%.1f度\n",n,m,angle);
	}
	printf("\n\n谢谢您的使用!\n\n");
}