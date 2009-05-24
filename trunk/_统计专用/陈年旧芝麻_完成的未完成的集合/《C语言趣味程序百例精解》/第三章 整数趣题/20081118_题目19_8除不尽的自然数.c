#include <stdio.h>
void main(void)
{
	int i,a,b,flag;
	for(i=1;flag;i++)
	{
		a=((i*8+7)*8+1)*8+1;
		b=(2*i*17+15)*17+4;
		if(a==b)
		{
			printf("This is %d\n",a);	//Carefully! You must know what you want output!
			flag=0;
		}
	}
	printf("Thanks!\n\n");
}