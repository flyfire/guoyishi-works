#include <stdio.h>
#include <math.h>
int main()
{
	long bigmod(long b,long p,long m);
	long b,p,m,r;
	scanf("%ld%ld%ld",&b,&p,&m);
	r=bigmod(b,p,m);
	printf("%ld\n",r);

}
long bigmod(long b,long p,long m)
{
	if(p==0)
		return 1;
	else if(p%2==0)
		return ((bigmod(b,p/2,m)*bigmod(b,p/2,m))%m) ;
	else
		return (((b%m)*bigmod(b,p-1,m))%m) ;
}