#include <stdio.h>
void main(void)
{
	int n,m,flag=1;
	double hour_hand,minute_hand,angle;
	printf("===2008-2-时钟夹角问题===\n");
	while(flag)
	{
		printf("请您输入时间:");
		scanf("%d%d",&n,&m);		//得到小时数和分钟数
		if(n>12||n<1||m>59||m<0)
			continue;				//促使用户输入正确的时间
		hour_hand=30*n+m/2.0;		//计算出时针角度
		minute_hand=m*6;			//计算出分针角度
		angle=hour_hand-minute_hand;//计算出时针和分针的夹角
		if(angle<0)
			angle=0-angle;			//使夹角变为整数
		//测试!!!!!!	printf("\n\n测试!时针:%.2f,分针:%.2f,夹角:%.2f\n\n",hour_hand,minute_hand,angle);
		if(angle>180)
			angle=360-angle;		//使夹角变为较小的那一个
		if(n==0&&m==0)
			flag=0;
		else
		{
			if(m>=10)				//分针输出时加个"0"
				printf("在%2d:%d,角度是%.1f度\n",n,m,angle);
			else
				printf("在%2d:0%d,角度是%.1f度\n",n,m,angle);
		}
	}
	printf("\n\n谢谢您的使用!\n\n");
}