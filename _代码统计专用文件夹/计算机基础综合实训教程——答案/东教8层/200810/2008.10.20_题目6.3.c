#include <stdio.h>
#include <math.h>
void main()
{
	double sum=0,t=0,q=0,rr=0;
	int a,n,i;
	printf("����a��n�����:\n");
	scanf("%d %d",&a,&n);
	for(i=0;i<=n;i++)
	{
		t=pow(10,i);
		q=a*t;
		sum=sum+q;
		rr=rr+sum;

	}
	printf("�����%f,%f",sum,rr);
}