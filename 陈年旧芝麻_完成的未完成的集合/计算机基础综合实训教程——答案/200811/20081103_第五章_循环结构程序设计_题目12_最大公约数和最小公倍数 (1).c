#include <stdio.h>
void main()
{
	int m,n,i,j,x,y;
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
	for(i=x;i>=1;i--)		//������Լ��
	{
		if(n%i==0&&m%i==0)
			break;
	}
	for(j=y;;j++)			//�����С������
	{
		if(j%m==0&&j%n==0)
			break;
	}
	printf("\n\n�������%d��%d�����Լ��Ϊ:%d ��С������:%d\n\n",m,n,i,j);
	printf("\n\n\nлл����ʹ��!\n\n\n");
}

