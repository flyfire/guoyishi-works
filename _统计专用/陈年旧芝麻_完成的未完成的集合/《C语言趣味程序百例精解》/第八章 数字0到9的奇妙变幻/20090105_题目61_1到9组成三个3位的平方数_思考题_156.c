#include <stdio.h>
#include <time.h>

int main()
{
	int fun(int,int);
	int count=0;
	int m,n,t;
	int t1,t2;
	int max=0,min=999;
	t1=clock();
	for(m=1234;m<9876;m++)
		for(n=2;n<80;n++)
		{
			t=m*n;
			if(t<100000&&fun(m,t)&&t==m*n)
			{
				printf("%d/%d=%d\n",t,m,n,count++);
				if(min>n)
					min=n;
				else if(max<t)
					max=t;
			}

		}
		t2=clock();
		printf("t1=%d,t2=%d,t2-t1=%d\n",t1,t2,t2-t1);
		printf("The count is %d,min=%d,max=%d\n",count,min,max);
}

int fun(int i,int j)
{
	int str[9],a[]={i,j};
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