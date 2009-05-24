#include <stdio.h>
void main(void)
{
	int str[5]={1,3,6,2,9};
	int i,j,k,b;
	for(i=0;i<5;i++)		//puts the first line
		printf("\t%d",str[i]);
	for(i=0,b=0,k=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(b%5==0)
				printf("\n");
			if(j==k)
				continue;
			else
			{
				printf("\t%d",str[j]);
				b++;
			}
		}
		k++;

	}
}