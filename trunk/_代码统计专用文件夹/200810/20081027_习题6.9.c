#include <stdio.h>
void main()
{
	int i,n;
	float s=0,h=0;
	printf("��������Ǹ߶�h,�Լ���������n:\n");
	scanf("%f,%d",&h,&n);
	for(i=0;i<=n;i++)
	{
		h=h/2;
		s=s+h;
	}
	printf("���ڵ�%d�����ʱ��������%4.0f��\n",n,s);
	printf("�ڵ�%d�η���%6.0f�׸�\n",n,h);
}