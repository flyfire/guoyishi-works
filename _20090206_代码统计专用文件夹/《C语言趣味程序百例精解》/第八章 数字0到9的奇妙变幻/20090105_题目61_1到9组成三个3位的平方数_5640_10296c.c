#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	int fun(int,int,int);
	int square(int);
	int count=0;
	int m,n,t;
	int t1,t2;
	int max1=0,min1=10000,min2=10000,max2=0;

	t1=clock();

	for(m=123;m<987;m++)
		for(n=123;n<987;n++)
			for(t=123;t<987;t++)
				if(m<n&&n<t&&square(m)&&square(n)&&square(t)&&fun(m,n,t))
				{
					t2=clock();
					printf("\nt1=%d,t2=%d,t2-t1=%d\n\nm=%d,n=%d,t=%d",t1,t2,t2-t1,m,n,t);
				}
	t2=clock();
	printf("\nt1=%d,t2=%d,t2-t1=%d\n\nm=%d",t1,t2,t2-t1,m);
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

int square(int n)
{
	int i=sqrt(n);
	if(i*i==n)
		return 1;
	return 0;
}