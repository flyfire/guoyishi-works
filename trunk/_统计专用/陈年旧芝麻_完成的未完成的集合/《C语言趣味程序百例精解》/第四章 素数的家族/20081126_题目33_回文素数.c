#include <stdio.h>
#include <math.h>
#define N 10
void main(void)
{
	int num(int);
	int palindrome(int);
	int i;
	for(i=3;i<=pow(2,N);i++)
	{
		if(num(i)&&palindrome(i)&&i>10)
			printf("The %d is a palindrome prime\n",i);
	}
}
int num(int i)
{
	int j;
	for(j=2;j<=sqrt(i);j++)
		if(i%j==0)
			return (0);
	return (1);
}
int palindrome(int i)
{
	int j,k,str[N];
	for(j=0;i>0;j++,i/=10)
		str[j]=i%10;
	for(k=0;k<=j-k-1;k++)
		if(str[k]!=str[j-k-1])
			return (0);
	return (1);
}