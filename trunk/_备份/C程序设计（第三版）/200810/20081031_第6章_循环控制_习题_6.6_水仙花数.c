#include <stdio.h>
#include <math.h>
void main()
{
	int i,a,b,c,t,k=1;
	printf("===�����ˮ�ɻ�����===\n");
	printf("�����������λ����ˮ�ɻ���Ϊ��\n");
	for(i=100;i<1000;i++)
	{
		a=i/100;
		b=i/10-10*a;       //һ��������ϸ�ģ�
		c=i%10;
		t=pow(a,3)+pow(b,3)+pow(c,3);
		if(i==t)
		{
			printf("%5d",i);
			k++;
		}
	}
	if(k/5==0)
		printf("\n");
	printf("\n\n\nлл����ʹ��!\n\n");
}


