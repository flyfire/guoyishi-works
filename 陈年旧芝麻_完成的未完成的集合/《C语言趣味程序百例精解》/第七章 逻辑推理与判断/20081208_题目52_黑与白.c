#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					for(e=0;e<=1;e++)
						if(((a&&b+c+d+e==3)||(!a&&b+c+d+e!=3))&&
							((b&&a+c+d+e==0)||(!b&&a+c+d+e!=0))&&
							((c&&a+b+d+e==1)||(!c&&a+b+d+e!=1))&&
							((d&&a+b+c+e==4)||(!d&&a+b+c+e!=4)))
						{
							printf("A is pasted a piece of %s paper on his forhead.\n",a?"white":"black");
							printf("%d--%d--%d--%d--%d\n",a,b,c,d,e);
						}

}