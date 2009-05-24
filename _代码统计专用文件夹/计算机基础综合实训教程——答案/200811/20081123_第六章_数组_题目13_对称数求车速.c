#include <stdio.h>
void main(void)
{
	int i,j,n,m,flag=0;
	int str[5];
	for(n=95859+1;!flag;n++)
	{
		m=n;
		for(i=0;m>0;i++)
		{
			str[i]=m%10;
			m/=10;
		}
		for(j=0,flag=1;j<i-j-1;j++)
			if(str[j]!=str[i-j-1])
				flag=0;


	}
	printf("the number is %d\n",n-1);
	printf("the speed is %.2f km/h\n",(n-1-95859)/2.0);

}