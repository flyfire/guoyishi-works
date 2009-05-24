#include <stdio.h>
#include <string.h>
int main()
{
	char *name1,*name2;
	printf("Input 1:\n");
	scanf("%s",&name1);
	printf("Input 2:\n");
	scanf("%s",&name2);
	printf("%s,%s\n",&name1,&name2);
	if(strcmp(name1,name2)>0)
		printf("OK!\n");
}
