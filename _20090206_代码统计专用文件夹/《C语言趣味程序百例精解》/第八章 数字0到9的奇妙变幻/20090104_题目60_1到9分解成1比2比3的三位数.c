#include <stdio.h>

int main()
{
	int a[9]={1};
	int i,j,k1,k2,k3;
	int flag=1,t;
	for(a[0]=1;a[0]<=3;a[0]++)
		for(a[1]=1;a[1]<=9;a[1]++)
			for(a[2]=1;a[2]<=9;a[2]++)
			{
				if(a[0]!=a[1]&&a[0]!=a[2]&&a[1]!=a[2])
				{
					k1=100*a[0]+a[1]*10+a[2];
					k2=k1*2;
					k3=k1*3;
					if(k3<1000)
					{
						for(t=5;t>=3;t--)
						{
							a[t]=k2%10;
							k2/=10;
						}
						for(t=8;t>=6;t--)
						{
							a[t]=k3%10;
							k3/=10;
						}


						for(i=0;i<=8&&flag;i++)
						{
							for(j=0;j<=8&&flag;j++)
								if((i!=j&&a[i]==a[j])||a[i]==0)
									flag=0;
						}
						if(flag)
						{
							for(t=0;t<=8;t++)
								printf((t+1)%3!=0?"%d":"%d  ",a[t]);
							printf("\n\n");
						}
						else
							flag=1;
					}
				}

			}
}
