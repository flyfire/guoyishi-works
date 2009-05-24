#include <stdio.h>

int main()
{
	int fun(int,int,int,int);
	int count=0;
	int m,n,t,sum;
	int max1=0,min1=10000,min2=10000,max2=0;
	for(m=1;m<10;m++)
		for(n=100;n<1000;n++)
			for(t=10;t<100;t++)
			{
				sum=(m*n)/t;
				if(sum<1000&&fun(m,n,t,sum)&&t*sum==m*n)
				{
					printf("%d*%d=%d,%d*%d=%d\n",m,n,m*n,t,sum,t*sum,count++);
					if(max1<m)
						max1=m;
					if(min1>m)
						min1=m;
					if(max2<n)
						max2=n;
					if(min2>n)
						min2=n;
				}
			}
	printf("The count is %d,min(m)=%d,max(m)=%d,min(n)=%d,max(n)=%d\n",count,min1,max1,min2,max2);
}

int fun(int i,int j,int k,int t)
{
	int str[9],a[]={i,j,k,t};
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