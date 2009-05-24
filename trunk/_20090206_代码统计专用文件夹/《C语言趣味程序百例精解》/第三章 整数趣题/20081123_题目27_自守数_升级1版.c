#include <stdio.h>
void main(void)
{
	int n,k,m,t,sum,b;
	for(n=1,b=10;n<=200000000000;n++)
	{
		for(k=10,m=b,t=0,sum=0;m>=10;k*=10,m/=10)
		{
			t=(n%m)*((n%k)/(k/10))*(k/10);
			sum+=t;
		}
		sum=sum%b;
		if(sum==n)
			printf("n=%d\n",n);
		if(n%b==0)
			b*=10;
	}
}