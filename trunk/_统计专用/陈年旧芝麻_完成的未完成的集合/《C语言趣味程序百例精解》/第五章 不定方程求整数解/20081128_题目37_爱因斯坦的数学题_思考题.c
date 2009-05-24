#include <stdio.h>
int main(void)
{
	int t,n=20;
	for(t=n-1;;t+=n)
		if(t%7==0)
			break;
	printf("It's %d\n",t);
}