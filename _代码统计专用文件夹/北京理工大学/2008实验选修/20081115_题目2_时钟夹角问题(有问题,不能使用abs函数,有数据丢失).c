#include <stdio.h>
#include <math.h>
void main(void)
{
	int n,m;
	double hour_hand,minute_hand,angle;
	printf("===2008-2-时钟夹角问题===\n");
	while(1)
	{
		printf("请您输入时间:");
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
			break;
		hour_hand=30*n+m/2.0;
		minute_hand=m*6;
		angle=fabs((double)hour_hand-(double)minute_hand);
		printf("\n\n测试!时针:%.2f,分针:%.2f,夹角:%.2f\n\n",hour_hand,minute_hand,angle);
		if(angle>180)
			angle=360-angle;
		printf("在%d:%d,角度是%.1f度\n",n,m,angle);
	}
	printf("\n\n谢谢您的使用!\n\n");
}