#include <stdio.h>
void main(void)
{
	char a[100];
	int i,j,k;
	for(i=0;;i++)
	{
		a[i]=getchar();
		if(a[i]=='\n')
			break;
	}
	for(j=0;j<=i;j++)
		printf("%c",a[j]);
	for(j=0,k=0;j<=i;j++)
	{
		if(a[j]!=' ')
		{
			a[k]=a[j];
			k++;
		}
	}
	for(j=0;j<k;j++)
		printf("%c",a[j]);
}