#include <stdio.h>
void main(void)
{
	int n,i,x,flag=1;
	for(n=6;flag;n+=5)
	{
		for(x=n,i=1;i<=5;i++)
			if((x-1)%5==0)
				x=4*(x-1)/5;
			else
				flag=0;
		if(flag)
			break;
		else
			flag=1;
	}
	printf("最后结果为:%d",n);
}
