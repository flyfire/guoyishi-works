#include <stdio.h>
#include <math.h>
void main()
{
	int i,x,m,p;			//x��ʾ������
	double y;			//y��ʾ������
	printf("===0~360��������ͼ�ε����===\n");
	for(y=1;y>=-1;y=y-0.1)
	{
		p=31*(y+0.5);
		x=acos(y)*10;	//��x���������10������չ
		m=62-x;			//�������Һ����ĶԳ���[(int)62=3.14*2*10]
		for(i=0;i<=62;i++)
		{

			if((i==x||i==m)&&p!=x)
				printf("*"); //��"*"����ͼ��
			if(i==p)
				printf("+");
			else
				printf(" ");
		}
		printf("\n");	//ÿ�еĻس�
	}
}