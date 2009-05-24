#include <stdio.h>
void main(void)
{
	int a,b,i,j,m;
	for(a=2;a<=3000;a++)
	{
		for(i=1,b=0;i<=a/2;i++)
			if(a%i==0)
				b+=i;
		for(j=1,m=0;j<=b/2;j++)
			if(b%j==0)
				m+=j;
		if(a==m&&a<b)
			printf("The Number is %d & %d\n",a,b);
	}
}