#include <stdio.h>
void main()
{
	char a,b;
	printf("Please Type X,X!\n");
	scanf("%c,%c",&a,&b);
	printf("What You type is %c,%c\n",a,b);
	a+=32;
	b+=32;
	printf("Changed: %c,%c\n",a,b);
	printf("Changed: %d,%d\n",a,b);
}