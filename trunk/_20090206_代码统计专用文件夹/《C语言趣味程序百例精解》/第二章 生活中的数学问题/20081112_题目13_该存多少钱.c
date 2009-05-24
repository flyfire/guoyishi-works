#include <stdio.h>
void main(void)
{
	float year(int);
	printf("===存钱问题探讨===\n");
	printf("第一年应该存%2.2f元钱\n",year(1));
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