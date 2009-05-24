#include <stdio.h>
void main(void)
{
	int *p,i=3,**p2;
	p=&i;
	p2=&p;
	*p=5;
	**p2=14;
	printf("i=%d,*p=%d,p=%x\n",i,*p,p);
	printf("p2=%x(Hex),*p2=%X,**p2=%d\n",p2,*p2,**p2);
}