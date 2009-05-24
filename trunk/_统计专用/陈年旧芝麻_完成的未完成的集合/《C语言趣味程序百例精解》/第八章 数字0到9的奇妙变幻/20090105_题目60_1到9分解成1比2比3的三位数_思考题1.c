#include <stdio.h>

int main()
{
	int fun(int,int,int);
	int count=0;
	int m,n,sum;
	int max=0,min=999;
	for(m=100;m<1000;m++)
		for(n=100;n<1000;n++)
		{
			sum=m+n;
			if(fun(m,n,sum)&&sum<1000&&m<=n)
			{
				printf("%d+%d=%d\n",m,n,sum,count++);
				if(min>m)
					min=m;
				else if(max<n)
					max=n;
			}
		}
		printf("The count is %d,min=%d,max=%d\n",count,min,max);
}

int fun(int i,int j,int k)
{
	int str[9],a[]={i,j,k};
	int *p,*p2,t;
	for(p=str,p2=a;p<str+9;p2++)
	{
		for(t=0;t<=2;t++,p++)
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