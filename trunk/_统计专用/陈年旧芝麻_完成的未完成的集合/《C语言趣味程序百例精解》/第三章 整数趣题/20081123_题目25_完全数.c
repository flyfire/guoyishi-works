#include <stdio.h>
#include <time.h>
void main(void)
{
	int i,m,n;
	int t1,t2;
	t1=clock();
	for(n=1;n<10000;n++)
	{
		for(i=1,m=0;i<=n/2;i++)
		{
			if(n%i==0)
			{
				m+=i;
			}
		}
		if(n==m)
			printf("%d\n",n);
	}
	t2=clock();
	printf("TIME=%dms\n",t2-t1);
}