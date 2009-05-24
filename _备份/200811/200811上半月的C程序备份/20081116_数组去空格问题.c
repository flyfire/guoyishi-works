#include <stdio.h>
void main(void)
{
	int i;
	char str[100];
	int flag=1,k=0;
	printf("===数组去空格问题探讨===\n");
	gets(str);
	for(i=0;flag;i++)
	{
		if(str[i]!=' ')
		{
			str[k]=str[i];
			k++;
		}
		if(str[i]=='0')
			flag=0;

	}
	for(i=0;i<k;i++)
		printf("str[%d]=%c\n",i,str[i]);
}