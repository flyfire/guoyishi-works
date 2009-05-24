#include <stdio.h>
int main (void)
{
	int i;
	for(i=0;;i++)
	{
		if(i%2==1)
			if(i%3==2)
				if(i%5==4)
					if(i%6==5)
						if(i%7==0)
							break;
	}
	printf("It's %d\n",i);
}