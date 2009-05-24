#include <stdio.h>
#include <math.h>

int main()
{
	int daffodil(int); 
	int n,flag;
	printf("Input:");
	scanf("%d",&n);
	flag=daffodil(n);
	if(flag)
		printf("It is!\n");
	else
		printf("It's not!\n");
}

int daffodil(int n)
{
	int i,sum=0,m=n;
	int str[10];
	for(i=0;n>0;n/=10,i++)
	{
		str[i]=n%10;
		sum+=pow(str[i],3);
	}
	if(sum==m)
		return (1);
	else
		return (0);
}