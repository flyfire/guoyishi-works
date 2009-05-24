#include <stdio.h>
void main(void)
{
	int n,i,flag;
	scanf("%d",&n);
	while(n!=1)
	{
		flag=1;
		for(i=2;i<=n&&flag;i++)
			if(n%i==0)
			{
				n/=i;
				printf("%d\n",i);
				flag=0;
			}
	}
}