#include <stdio.h>
void main(void)
{
	int i,flag=1,a,t,k;
	int str[10];
	for(t=1;t<300;t++)
	{
		k=t*t;
		for(i=0;k>0;i++)
		{
			str[i]=k%10;
			k/=10;
		}
		for(a=0,flag=1;a<i-a-1;a++)
		{
			if(str[a]!=str[i-a-1])
				flag=0;
		}
		if(flag)
			printf("%d(%d*%d) is The Number\n",t*t,t,t);
		else
			flag=1;
	}
}