#include <stdio.h>
int main()
{
	int a,b,c,d;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					if(((a&&a+b+c+d==0)||(!a&&a+b+c+d!=0))
						&&((b&&a+b+c+d==3)||(!b&&a+b+c+d!=3))
						&&((c&&a+b+c+d==2)||(!c&&a+b+c+d!=2))
						&&d)
						if(d)
							printf("No.4 told a truth. --%d-%d-%d-%d\n",a,b,c,d);
						else
							printf("No.4 told a lie.\n");
}