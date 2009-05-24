#include <stdio.h>
#include <math.h>
int main()
{
	int p,q,r,s;
	int count=1;
	for(p=2;p<=4;p++)
		for(q=3;q<=6;q++)
			for(r=4;r<=12;r++)
				for(s=4;s<=42;s++)
					if(fabs(1-(1.0/p+1.0/q+1.0/r+1.0/s))<0.000000001&&p<=q&&q<=r&&r<=s)
						printf("[%2d]1/%d + 1/%d + 1/%2d + 1/%2d =1\n",count++,p,q,r,s);
}