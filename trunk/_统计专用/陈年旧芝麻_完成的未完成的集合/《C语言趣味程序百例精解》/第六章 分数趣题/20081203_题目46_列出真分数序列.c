#include <stdio.h>
int main()
{
	int fun(int);
	int i;
	for(i=1;i<=40;i+=2)
	{
		if(fun(i))
			printf("%d/40\n",i);
	}
}
int fun(int x)
{
	int j,flag=1;
	for(j=3;j<=x;j++)
	{
		if(x%j==0&&40%j==0)
			flag=0;
	}
	return (flag);
}