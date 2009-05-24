#include <stdio.h>
int main(void)
{
	int red,white,black;
	int count=0;
	for(red=0;red<=3;red++)
		for(white=0;white<=3;white++)
		{
			if((black=8-red-white)<=6) //that is important
			{
				printf("%2d:red=%d,white=%d,black=%d\n",++count,red,white,black);
			}
		}

}