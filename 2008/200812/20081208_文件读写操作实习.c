#include <stdio.h>
int main()
{
	FILE *fp,*file1,*file2,*file3,*img1;
	char ch;
	if((fp=fopen("20081208_test_1.txt","r+"))==NULL)
	{
		printf("Can not open file.\n");
		getch();
		exit(0);
	}
	if((file1=fopen("file1.txt","r+"))==NULL)
	{
		printf("Can not open file1.txt\n");
		getch();
		exit(0);
	}
	if((file2=fopen("file2.txt","r+"))==NULL)
	{
		printf("Can not open file2.txt\n");
		getch();
		exit(0);
	}
	if((file3=fopen("file3.txt","r+"))==NULL)
	{
		printf("Can not open file3.txt\n");
		getch();
		exit(0);
	}
	if((img1=fopen("img1.txt","r+"))==NULL)
	{
		printf("Can not open img1.txt.\n");
		getch();
		exit(0);
	}

	ch=fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		if(ch=='$')
		{
			fputs(file1,img1);
			fputs(file2,img1);
			fputs(file3,img1);
		}
			
		ch=fgetc(fp);
	}
	fclose(fp);
}