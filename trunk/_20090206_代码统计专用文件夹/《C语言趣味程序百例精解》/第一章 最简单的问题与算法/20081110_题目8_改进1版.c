#include <stdio.h>
void main(void)
{
	int k=1,a,b,c;
	printf("===��������̽��!(������)===\n");
	for(a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b&&c<=5;c++)
			{
				if(a!=c&&b!=c)
					printf(k%5?"  %2d:%d,%d,%d":"  %2d:%d,%d,%d\n",k,a,b,c,k++);		//���k++��Ȼ������������,̫ţ��~
																						//����ʵ���˼���K++,�ֿ�����ȷ�Ļ���
			}
	printf("\n��˹���%d�ַ���\n",k);
	printf("\nлл����ʹ��!\n\n\n");
}