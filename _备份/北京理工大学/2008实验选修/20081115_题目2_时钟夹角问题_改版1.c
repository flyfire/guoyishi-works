#include <stdio.h>
void main(void)
{
	int n,m,flag=1;
	double hour_hand,minute_hand,angle;
	printf("===2008-2-ʱ�Ӽн�����===\n");
	while(flag)
	{
		printf("��������ʱ��:");
		scanf("%d%d",&n,&m);		//�õ�Сʱ���ͷ�����
		if(n>12||n<1||m>59||m<0)
			continue;				//��ʹ�û�������ȷ��ʱ��
		hour_hand=30*n+m/2.0;		//�����ʱ��Ƕ�
		minute_hand=m*6;			//���������Ƕ�
		angle=hour_hand-minute_hand;//�����ʱ��ͷ���ļн�
		if(angle<0)
			angle=0-angle;			//ʹ�нǱ�Ϊ����
		//����!!!!!!	printf("\n\n����!ʱ��:%.2f,����:%.2f,�н�:%.2f\n\n",hour_hand,minute_hand,angle);
		if(angle>180)
			angle=360-angle;		//ʹ�нǱ�Ϊ��С����һ��
		if(n==0&&m==0)
			flag=0;
		else
		{
			if(m>=10)				//�������ʱ�Ӹ�"0"
				printf("��%2d:%d,�Ƕ���%.1f��\n",n,m,angle);
			else
				printf("��%2d:0%d,�Ƕ���%.1f��\n",n,m,angle);
		}
	}
	printf("\n\nлл����ʹ��!\n\n");
}