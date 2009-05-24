#include <stdio.h>
void main(void)
{
	int x,y,z,count=0;
	for(x=0;x<=20;x++)
		for(y=0;y<=33;y++)
		{
			z=100-x-y;
			if(z%3==0&&x+y+z==100&&5*x+3*y+z/3==100)
			{
				printf("(%d)cock=%2d hen=%2d chicken=%2d\n",++count,x,y,3*z);
				break;
			}
		}
}