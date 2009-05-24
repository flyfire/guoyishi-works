#include <stdio.h>
#include <math.h>
void main(void)
{
	int i,j,h;
	char c;
	scanf("%c%d",&c,&h);
	for(i=h;abs(i)<=h;i--)
	{
		for(j=1;j<h+i;j++)
		{
			if(j==h-i+1||j==h+i-1)
				printf("%c",c);
			else
				printf(" ");
		}
		c++;
		printf("\n");
	}
}