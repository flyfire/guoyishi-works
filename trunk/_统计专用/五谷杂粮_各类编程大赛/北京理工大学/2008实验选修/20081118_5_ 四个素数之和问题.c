#include <stdio.h>
#include <math.h>
void main(void)
{
	int n,a,k1,k2,k3,k4;
	int flag=1,i;
	while(flag)
	{
		scanf("%d",&n);
		if(n==0)	//When user input 0,Program exit
			flag=0;
		a=sqrt(n);
		for(k1=3;k1<a;k1+=2)
			for(k2=3;k2<a;k2+=2)
				for(k3=3;k3<a;k3+=2)
				{
					k4=n-k1-k2-k3;
					for(i=3;i<a;i+=2)
					{
						if(k1%i==0||k2%i==0||k3%i==0||k4%i==0)
							break;
						else
							printf("%d=%d+%d+%d+%d\n",n,k1,k2,k3,k4);
					}
				}
	}
	printf("\n\nThanks!\n\n");
}