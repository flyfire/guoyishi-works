#include <stdio.h>
void main()
{
	int m,n,i,p,q,x,y;
	printf("===�����Լ������С������===\n");
	printf("��������������:\n");
	scanf("%d%d",&m,&n);
	if(m>n)					//��m��n�����ĸ���y,С�ĸ���x
	{
		x=n;
		y=m;
	}
	else
	{
		x=m;
		y=n;
	}
	for(i=2;i<=x;i++)		//������Լ��
	{
		if(n%i==0&&m%i==0)
			p=i;
	}
	for(i=y;;i++)			//�����С������
	{
		if(i%m==0&&i%n==0)
		{
			q=i;
			break;
		}
	}
	printf("\n\n�������%d��%d�����Լ��Ϊ:%d ��С������:%d\n\n",m,n,p,q);
	printf("\n\n\nлл����ʹ��!\n\n\n");
}

