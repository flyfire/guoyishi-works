#include <stdio.h>
void main(void)
{
	int i,k=0;
	printf("===有限五位数讨论===\n");
	printf("个位数是6并且可以被3整除的五位数:\n");
	for(i=1002;i<=9999;i+=3)
	{
		if(i%3==0)
			k++;
	}		//由于最后一位是6它是可以被三整除的,因此只考虑前4位就可以了!
	printf("共有%d个满足条件的数\n",k);
}