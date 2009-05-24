#include <stdio.h>
void main(void)
{
	int i,n;
	printf("===你会输出一行星号吗？===\n");
	printf("请输入您要输出的星数:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("*");
	}
	printf("\n\n谢谢您的使用!\n\n\n");
}