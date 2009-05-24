#include <stdio.h>
int main()
{
	char a,b,c;
	int i,j,k;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			for(k=1;k<=3;k++)
			{
				if(i!=1&&k!=1&&k!=3&&i!=j&&j!=k&&i!=k)
					printf("a--%d\nb--%d\nc--%d\n",i,j,k);
			}
}