#include <stdio.h>
void main(void)
{
	int a[5];
	long i,speed,t,k;
	for(i=95860;;i++)
	{
		for(t=0,k=100000;k>=10;t++)
		{
			a[t]=(i%k)/(k/10);
			k/=10;
		}
		if((a[0]==a[4])&&(a[1]==a[3]))
			break;
	}
	speed=(i-95859)/2;
	printf("The Number is %d\n",i);
	printf("The speed is %d km/h\n",speed);
	printf("\n\nThanks!\n\n");


}