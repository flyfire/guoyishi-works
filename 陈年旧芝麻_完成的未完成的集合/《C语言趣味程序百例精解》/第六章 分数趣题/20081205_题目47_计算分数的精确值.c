#include <stdio.h>
#define N 100
int main()
{
	int m,n,i,j,k,flag=1;
	int m1,n1,t;
	int str[N],str2[N];
	scanf("%d%d",&m,&n);
	m1=m;
	n1=n;
	for(i=0,j=0;i<N&&m&&flag;i++,j++)
	{
		str[i]=m/n;
		str2[j]=(m%=n);
		for(k=0;k<j&&flag;k++)
		{
			if(str2[k]==str2[j])
				flag=0;
		}
		m*=10;
	}
	printf("%d/%d it's accuracy value is :",m1,n1);
	for(t=0;t<i;t++)
	{
		printf(t==0?"%d.":"%d",str[t]);
	}
	printf("\n");
	if(!flag)
		printf("from %d to %d\n",k,j-1);

}