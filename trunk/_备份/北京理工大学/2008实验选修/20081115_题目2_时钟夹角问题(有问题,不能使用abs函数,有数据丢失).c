#include <stdio.h>
#include <math.h>
void main(void)
{
	int n,m,flag=1;
	double hour_hand,minute_hand,angle;
	printf("===2008-2-ʱ�Ӽн�����===\n");
	while(flag)
	{
		printf("��������ʱ��:");
		scanf("%d%d",&n,&m);
		hour_hand=30*n+m/2.0;
		minute_hand=m*6;
		angle=abs((double)hour_hand-(double)minute_hand);
		printf("\n\n����!ʱ��:%.2f,����:%.2f,�н�:%.2f\n\n",hour_hand,minute_hand,angle);
		if(angle>180)
			angle=360-angle;
		if(n==0&&m==0)
			flag=0;
		else
			printf("��%d:%d,�Ƕ���%.1f��\n",n,m,angle);
	}
	printf("\n\nлл����ʹ��!\n\n");
}