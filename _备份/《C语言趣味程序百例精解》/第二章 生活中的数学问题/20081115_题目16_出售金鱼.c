#include <stdio.h>
void main(void)
{								//��Ŀ����,����!
	int i;
	float d=11;
	for(i=5;i>1;i--)
	{
		d=d/((1-1.0/i)*(1-1.0/i));
	}
	printf("�����:%.2f",d);
}