#include <stdio.h>
int main(void)
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=(m<n?m:n);i>=1;i--)
		if(m%i==0&&n%i==0)
			break;
	for(j=(m>n?m:n);;j++)
		if(j%m==0&&j%n==0)
			break;
	printf("GCD=%d,LCM=%d\n",i,j);

}