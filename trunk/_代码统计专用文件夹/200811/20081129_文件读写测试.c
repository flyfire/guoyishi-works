#include <stdio.h>
#include <cstdlib>
int main()
{
	FILE *fp;
	char str[100],filename[10];
	int i;
	if((fp=fopen("test123.txt","w"))==NULL)
	{
		printf("can not open file.\n");
		exit(0);
	}
	printf("Input a string:");
	gets(str);
	for(i=0;str[i];i++)
	{
		if(str[i]>='a'&&str[i]<='z')
			str[i]-='a'-'A';
		fputc(str[i],fp);
	}
	fclose(fp);
	fp=fopen("test123.txt","r");
	fgets(str,100,fp);
	printf("%s\n",str);
	fclose(fp);
}