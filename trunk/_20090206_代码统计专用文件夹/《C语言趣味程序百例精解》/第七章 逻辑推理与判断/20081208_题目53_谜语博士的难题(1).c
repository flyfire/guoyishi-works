#include <stdio.h>
int main()
{
	int a,b,c;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				if(((a&&a+b+c==2)||(!a&&a+b+c!=2))
					&&((b&&a+b+c==1)||(!b&&a+b+c!=1))
					&&((c&&a+b+c==1)||(!c&&a+b+c!=1)))
				{
					printf("%d--%d--%d\n",a,b,c);
				}
} //lie:0 turth:1