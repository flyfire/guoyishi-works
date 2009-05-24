#include <stdio.h>
void main(void)
{
	int str[4];
	int i,j,k,n,m,flag;
	for(i=1000;i<10000;i++)
	{
		n=i;
		for(j=0;n>0;j++)
		{
			str[j]=n%10;
			n/=10;
		}
		for(k=2;k<i/2;k++)
			if(i%k==0)
				flag=0;
		if(flag)
		{
			m=str[0]*1000+str[1]*100+str[2]*10+str[3];
			for(k=2;k<m/2;k++)
				if(m%k==0)
					flag=0;
			if(flag)
					printf("%d  %d\n",i,m);
			else
				flag=1;
		}
		else
			flag=1;
	}

}