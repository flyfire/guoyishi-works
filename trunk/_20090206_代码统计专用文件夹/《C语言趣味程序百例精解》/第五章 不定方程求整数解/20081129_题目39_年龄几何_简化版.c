#include <stdio.h>
int main(void)
{
	int a,d,i;
	int flag=1;
	for(a=0;flag;a++)
		for(d=0;flag&&d<9;d++)
			if(a+a+d+a+2*d+a+3*d==26)
				if((a)*(a+d)*(a+2*d)*(a+3*d)==880)
					flag=0;
	a-=1;d-=1;
	for(i=0;i<20;i++)
	{
		printf(i-19==0?"%d  \n":"%d  ",a+i*d);
	}
}