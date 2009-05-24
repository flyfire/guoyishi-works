#include<stdio.h>
main()
{	int i,p,n,k,a[50];
	scanf("%d%d",&n,&k);
	for(i=0;i<n-1;i++)
		a[i]=i+1;
	a[n-1]=0;
	p=n-1;
	while(a[p]!=p)
		{	for(i=1;i<=k-1;i++)
				p=a[p];
			a[p]=a[a[p]];
		}
	printf("The left child is NO %d.\n",p+1);
}
