#include <stdio.h>
#include <math.h>
void main()
{
	double sum,a1,a2; 
	int x,y;
	printf("Please Type x!\n");
	scanf("%d",&x);
	printf("Please Type y!\n");
	scanf("%d",&y);
	sum=sqrt(y)+pow(x,5)/2;
	printf("Sum=%6f",sum);
}