#include <stdio.h>
#include <math.h>
void main()
{
	int i,x,m;							//x��ʾ������
	double y;							//y��ʾ������
	printf("===0~360��������ͼ�ε����===\n");
	for(y=1;y>=-1;y=y-0.1)
	{
		if(y>=0)						//���ҵ����沿��
		{
			x=asin(y)*10;
			m=31-x;	
		}
		else							//���ҵ����沿��
		{
			x=(asin(y)+2*3.1415926)*10;	
			m=94-x;	
		}
		for(i=0;i<=62;i++)
		{
			if(i==x||i==m)
				printf("*");			//��"*"����ͼ��
			else
				printf(" ");
		}
		printf("\n");					//ÿ�еĻس�
	}
}