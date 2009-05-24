#include <stdio.h>
void main(void)
{
	int i,j,n,str[50],str2[10],k=0;
	scanf("%d".&n);
	for(i=0;i<n;i++)
		scanf("%d",&str[i]);
	for(i=1;i<n;i++)
	{	if(str[i]==str[i-1])
		{	if(flag)
				{
					k1=i-1;
					flag=0;
				}
			k2=i;
			if(str[i]!=str[i+1])
			{
				flag=1;
				s1=k1;
				s2=k2;
				k++;
			}
		}
	}
}