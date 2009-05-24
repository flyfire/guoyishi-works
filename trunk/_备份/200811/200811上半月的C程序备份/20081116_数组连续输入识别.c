#include "stdio.h" 
#define N 10
void InsSort(int a[N]) 
{ 
	int i,j,x; 
	for(i=1;i<N;i++) 
	{ 
		x=a[i];
		j=i-1; 
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--; 
		} 
		a[j+1]=x; 
	} 
} 
void main() 
{ 
	int a[N],i; 
	for(i=0;i<N;i++)
		scanf("%d",a+i); 
	InsSort(a); 
	for(i=0;i<N;i++)
		printf("%4d",a[i]); 
	printf("\n"); 
} 