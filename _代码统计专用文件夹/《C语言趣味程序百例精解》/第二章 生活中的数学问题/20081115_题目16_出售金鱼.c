#include <stdio.h>
void main(void)
{								//题目不懂,放弃!
	int i;
	float d=11;
	for(i=5;i>1;i--)
	{
		d=d/((1-1.0/i)*(1-1.0/i));
	}
	printf("最后结果:%.2f",d);
}