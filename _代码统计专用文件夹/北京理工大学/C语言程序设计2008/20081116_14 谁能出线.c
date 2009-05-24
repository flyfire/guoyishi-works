#include <stdio.h>
void main(void)
{	int i,k=0,max=0,str[10],str2[10];
	for(i=0;i<10;i++)
	{	scanf("%d",&str[i]);
		if(str[i]>max)
			max=str[i];
	}
	for(i=0;i<10;i++)
		if(str[i]==max)
		{	str2[k]=i;k++;}
	for(i=0;i<=k-1;i++)
		printf("%d\n",str2[i]);
}
