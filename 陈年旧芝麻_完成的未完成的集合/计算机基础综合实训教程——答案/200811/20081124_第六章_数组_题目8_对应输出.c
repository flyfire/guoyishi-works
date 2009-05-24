#include <stdio.h>
void main(void)
{
	int i,j,k;
	char str[200],str2[200];
	printf("input the first array:\n");
	for(i=0;;i++)
	{
		str[i]=getchar();
		if(str[i]=='\n')
			break;
	}
	printf("input the second array:\n");
	for(j=0;;j++)
	{
		str2[j]=getchar();
		if(str2[j]=='\n')
			break;
	}
	printf("the same character:\n");
	for(k=0;k<(i>j?j:i);k++)
	{
		if(str[k]==str2[k])
			printf("%c",str[k]);
		else
			printf("_");
	}
	printf("\n");
}