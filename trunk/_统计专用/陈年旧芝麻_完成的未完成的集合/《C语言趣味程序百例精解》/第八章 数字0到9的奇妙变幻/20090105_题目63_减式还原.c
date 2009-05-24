#include <stdio.h>

int main()
{
	int p,e,a,r;
	int m,n,t;
	for(p=1;p<=9;p++)
		for(e=0;e<=9;e++)
			if(p!=e)
				for(a=1;a<=9;a++)
					if(p!=a&&e!=a)
						for(r=0;r<=9;r++)
							if(p!=r&&e!=r&&a!=r)
							{
								m=1000*p+100*e+10*a+r;
								n=100*a+10*r+a;
								t=100*p+10*e+a;
								if(m-n==t)
									printf("%d-%d=%d\n",m,n,t);
							}
}
