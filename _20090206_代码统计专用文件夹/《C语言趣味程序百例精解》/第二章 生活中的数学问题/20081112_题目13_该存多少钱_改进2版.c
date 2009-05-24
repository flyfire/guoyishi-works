#include <stdio.h>
void main(void)
{
	int i;
	float x=0;
	for(i=0;i<5;i++)
	{
		x=(x+1000)/(1+12*.0063);
	}
	printf("第一年应该存%.2f元钱\n",x);
}