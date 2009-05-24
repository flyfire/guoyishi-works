#include <stdio.h>
void main(void)
{
	int i,speed;
	int a,b,c,d,e;
	for(i=95859+1;i<100000;i++)
	{
		a=i/10000;
		b=i/1000-a*10;
		c=i/100-a*100-b*10;
		d=i/10-a*1000-b*100-c*10;
		e=i%10;
		speed=(i-95859)/2;
		if(a==e&&b==d)
		{
			printf("The Number is %d\n",i);
			printf("The Speed is %dkm/h\n",speed);
			break;
		}
	}
}