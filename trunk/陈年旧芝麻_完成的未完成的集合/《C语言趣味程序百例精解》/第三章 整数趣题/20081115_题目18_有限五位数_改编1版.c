#include <stdio.h>
void main(void)
{
	int i,k=0;
	printf("===有限五位数的求解===\n");
	for(i=10006;i<100000;i+=10)
	{
		if(i%3==0)
		{
			printf("%d满足条件\n",i);
			k++;
		}
	}
	printf("共有%d个满足条件的数\n",k);
	printf("谢谢您的使用!\n");
}