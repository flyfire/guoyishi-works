#include <stdio.h>
#include <math.h>
void main(void)
{
	int num(int number);
	int i,count;
	printf("There are invertable primes with 4 digits:\n");
	for(count=1,i=1001;i<9999;i+=2)
		if(num(i))
			printf(count%9?"%3d:%d":"%3d:%d\n",count++,i);
	printf("\n");
}
int num(int number)
{
	int ok(int number);
	int i,j;
	if(!ok(number)) return (0);
	for(i=number,j=0;i>0;i/=10)
		j=j*10+i%10;
	if(number<j)
		if(!ok(j)) return(0);
		else return(1);
	else return(0);
}
 int ok(int number)
 {
	int i,j;
	if(number%2==0) return (0);
	j=sqrt(number)+1;
	for(i=3;i<=j;i++)
		if(number%i==0) return (0);
	return(1);
 }
