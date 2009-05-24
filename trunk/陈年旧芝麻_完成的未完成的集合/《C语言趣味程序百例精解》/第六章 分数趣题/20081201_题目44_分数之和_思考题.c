#include <stdio.h>
#include <math.h>
int main()
{
	int fun(int,int,int);
	int fun2(int,int,int);
	int a,b,c;
	for(a=1;a<=98;a++)
		for(b=1234;b<=98765;b++)
			for(c=123;c<=9876;c++)
				if(fun(a,b,c)&&fun2(a,b,c))
					printf("%d=%d*%d/%d\n",a+b/c,a,b,c);
}
int fun(int a,int b,int c)
{
	int notqu(int);
	if(notqu(a)&&notqu(b)&&notqu(c))
		return 1;
}
int fun2(int a,int b,int c)
{
	float z;
	z=(float)b/c;
	if(abs(z)==z)
		return 1;
}
int notqu(int x)
{
	int str[5];
	int i,j,flag=1;
	for(i=0;x>0;i++)
	{
		str[i]=x%10;
		x/=10;
	}
	for(j=0;j<=i-1-j;j++)
	{
		if(str[j]==str[i-1-j])
			flag=0;
	}
	return (flag);
}
