#include <stdio.h>
void main(void)
{
	int i;
	char str[10];
	for(i=0;i<10;i++)
	{
		scanf("%c",&str[i]);
		str[i]*=str[i];
		printf("char=%c,int=%d\n",str[i],str[i]);
	}
}