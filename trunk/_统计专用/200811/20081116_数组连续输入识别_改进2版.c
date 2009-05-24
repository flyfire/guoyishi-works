#include <stdio.h>
void main(void)
{
	int str[10];
	int i;
	printf("请您输入!\n");
	for(i=0;i<10;i++)
		scanf("%d",str+i);
	for(i=0;i<10;i++)
		printf("%d\n",str[i]);
	printf("谢谢您的使用!\n");
}