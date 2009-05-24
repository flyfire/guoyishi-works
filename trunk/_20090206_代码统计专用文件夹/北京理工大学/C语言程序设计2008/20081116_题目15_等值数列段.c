#include <stdio.h>
void main(void)
{	int i,j,n,flag=1,k1,k2=0,str[50];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	scanf("%d",&str[i]);
		if(str[i]==str[i-1])
		{
			if(flag)
			{
				k1=i-1;
				flag=0;
			}
			k2=i;
		}
	}
	if(k2==0)
		printf("No equal number list.\n");
	else
		printf("The longest equal number list is from %d to %d.\n",k1,k2);
}

	