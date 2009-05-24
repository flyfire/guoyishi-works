#include <stdio.h>
int main()
{
	unsigned long int x,y,m,n,L;
	unsigned long int sum1,sum2;
	unsigned int flag=0,i;
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&L);
	for(sum1=x,sum2=y,i=1;i<L;i++)
	{
		sum1+=m;
		sum2+=n;
		sum1%=L;
		sum2%=L;
		if(sum1==sum2)
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("%d\n",i);
	else
		printf("Impossible\n");
}