#include <stdio.h>
#include <math.h>
#define NUM 320
int number[NUM];
void main(void)
{
	int fflag(int);
	int i,j,count=0;
	printf("There are following primes sequences in first row:\n");
	for(j=0,i=3;i<=1993;i+=2)
		if(fflag(i))
			number[j++]=i;
		for(j--;number[j]>1898;j--)
		{
			for(i=0;number[j]-number[i]>1898;i++);
			if(number[j]-number[i]==1898)
				printf("(%d).%3d,... ...,%d\n",++count,number[i],number[j]);
		}
}
int fflag(int i)
{
		int j;
		if(i<=1)
			return(0);
		if(i==2)
			return(1);
		if(!(i%2))
			return(0);
		for(j=3;j<=(int)(sqrt((double)i)+1);j+=2)
			if(!(i%j))
				return(0);
		return(1);
}