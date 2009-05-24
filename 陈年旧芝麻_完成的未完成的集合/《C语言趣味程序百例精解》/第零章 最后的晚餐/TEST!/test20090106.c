#include <stdio.h>

int main()
{
	long n,max=1000,k=0,t=0;
	long start;
	printf("input something:\n");
	scanf("%d",&n);
	start=n;
	while(k<max)
	{
		if(n==1&&!t)
			t=k;
		printf("%d ---) n=%d\n\n",++k,n);
		if(n%2==0)
			n/=2;
		else
			n=n*3+1;
	}
	printf("t=%d,Start:%d.\n",t,start);
}
