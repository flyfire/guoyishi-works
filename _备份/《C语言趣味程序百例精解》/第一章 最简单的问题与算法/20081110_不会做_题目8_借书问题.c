#include <stdio.h>
void main(void)
{
	int k=0,a,b,c;
	printf("===��������̽��!===\n");		//�������Ժ����������,����ҪŬ����!
	for(a=1;a<5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b&&c<=5;c++)
			{
				if(a!=c&&b!=c)				//�˴������ԸĽ�,����ʹ��: ��Ŀ�����!
				{
					k++;
					printf("��%d�ַ���:A�õ�%d����,B�õ�%d����,C�õ�%d����\n",k,a,b,c);
				}
			}
	printf("\n��˹���%d�ַ���\n",k);
	printf("\nлл����ʹ��!\n\n\n");
}