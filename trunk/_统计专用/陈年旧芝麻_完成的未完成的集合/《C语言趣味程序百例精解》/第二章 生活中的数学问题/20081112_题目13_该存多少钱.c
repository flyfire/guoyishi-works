#include <stdio.h>
void main(void)
{
	float year(int);
	printf("===��Ǯ����̽��===\n");
	printf("��һ��Ӧ�ô�%2.2fԪǮ\n",year(1));
}

float year(int i)
{
	float x;
	if(i==6)
		return 0;
	else
	{
		x=(year(i+1)+1000)/(1+12*0.0063);
		return x;
	}
}