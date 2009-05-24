#include <stdio.h>

int main()
{
	int fun(int,int,int);
	int count=0;
	int m,n,sum;
	int max=0,min=10000;
	for(m=1;m<10;m++)
		for(n=1000;n<10000;n++)
		{
			sum=m*n;
			if(sum<10000&&fun(m,n,sum))
			{
				printf("%d*%d=%d\n",m,n,sum,count++);
				if(min>n)
					min=n;
				else if(max<n)
					max=n;
			}

		}
		printf("The count is %d,min=%d,max=%d\n",count,min,max);
}

int fun(int i,int j,int k)
{
	int str[9],a[]={i,j,k};
	int *p,*p2;
	for(p=str,p2=a;p<str+9;p2++)
	{
		for(;*p2>0;p++)
		{
			*p=*p2%10;
			*p2/=10;
		}
	}
	for(i=0;i<=8;i++)
		for(j=0;j<=8;j++)
			if((i!=j&&str[i]==str[j])||str[i]==0)
				return 0;
	return 1;
}