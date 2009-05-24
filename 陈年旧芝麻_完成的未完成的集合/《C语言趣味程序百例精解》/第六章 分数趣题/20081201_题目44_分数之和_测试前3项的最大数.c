#include <stdio.h>
int main()
{
	int p,q,r,flag=1,i;
	float s,max=0;
	int count=1;
	for(p=2;p<=4;p++)
		for(q=3;q<=6;q++)
			for(r=4;r<=12;r++)
				if((s=1.0/p+1.0/q+1.0/r)>max&&s<1)
				{
						printf("[%2d]1/%d + 1/%d + 1/%2d =%.4f---max=%.4f\n",count++,p,q,r,s,max=s);
				}
	for(i=1;flag;i++)
	{
		if(1.0/i<=(1-max))
		{
			flag=0;
			printf("max=%lf  1-max=%lf  1/%d=%lf\n",max,1-max,i,1.0/i);
		}
	}
}
//i=42