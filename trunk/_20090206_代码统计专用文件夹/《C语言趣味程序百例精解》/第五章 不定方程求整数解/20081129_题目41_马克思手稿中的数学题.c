#include <stdio.h>
int main(void)
{
	int x,y,z;
	int count=0;
	printf("\tMEN\tWOMEN\tCHILDREN\n");
	printf("----------------------------------\n");
	for(x=0;x<=16;x++)
		for(y=0;y<=25;y++)
			if((z=30-x-y)+2*y+3*x==50)
				printf("%2d\t%2d\t  %2d\t   %2d\n",++count,x,y,z);
}