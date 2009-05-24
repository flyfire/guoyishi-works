#include <stdio.h>
#include <math.h>
void main(void)
{
	int num(int);
	int i;
	for(i=3;i<=1000;i+=2)
		if(num(i)&&num(i+2))
			printf("(%d,%d)\n",i,i+2);
}
int num(int x)
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return (0);
	return (1);
}