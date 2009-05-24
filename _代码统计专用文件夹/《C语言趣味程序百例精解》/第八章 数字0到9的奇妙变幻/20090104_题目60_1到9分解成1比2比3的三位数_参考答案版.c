#include <stdio.h>

int a[9];

int main()
{
	void print(int *p);
	int fun(int,int *p);
	int m;

	for(m=123;m<=333;m++)
		if(fun(m,a)&&fun(m*2,a+3)&&fun(m*3,a+6))
		{
			printf("%d %d %d\n",m,m*2,m*3);
			print(a);
		}

}

int fun(int n,int z[])
{
	int *p1,*p2;
	for(p1=z;p1<z+3;p1++)
	{
		*p1=n%10;
		n/=10;
		for(p2=a;p2<p1;p2++)
			if(*p1==0||*p1==*p2)
				return 0;
	}
	
	return 1;
}

void print(int a[])
{
	int *p1,*p2;
	for(p1=a;p1<a+9;p1+=3)
	{
		for(p2=p1+2;p2>=p1;p2--)
			printf("%d",*p2);
		printf(" ");
	}
	printf("++\n");
}