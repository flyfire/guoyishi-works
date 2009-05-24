#include <stdio.h>
int main()
{
	int m,n,temp,i;
	long sum=0;
	while(1)
	{
		printf("Input two numbers:");
		scanf("%d%d",&m,&n);
		if(m==0&&n==0)
			break;
		if(m>n)
		{
			printf("Change the order:");
			temp=m;
			m=n;
			n=temp;
			printf("m=%d,n=%d\n",m,n);
		}
		for(i=m;i<=n;i++)
		{
			sum+=i;
		}
		printf("The sum of %d and %d is %d.\n",m,n,sum);
	}
}//DONE!