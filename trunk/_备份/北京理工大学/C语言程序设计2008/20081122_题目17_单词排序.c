#include <stdio.h>
#include <string.h>
void main(void)
{
	char str[5][10],t[20],*max;
	int i,j,flag;
	for(i=0;i<5;i++)
		scanf("%s",str+i);
	for(j=0;j<4;j++)
	{	max=str+j;
		for(i=j+1;i<5;i++)
		{	flag=strcmp(str+i,max);
			if(flag>0)
				max=str+i;
		}
		strcpy(t,max);
		strcpy(max,str+j);
		strcpy(str+j,t);
	}
	for(i=0;i<5;i++)
		printf("%s\n",str+i);
}

