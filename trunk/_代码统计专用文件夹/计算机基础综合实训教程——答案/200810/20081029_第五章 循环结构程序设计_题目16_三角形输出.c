#include <stdio.h>
void main()
{
	int i,j,n;
	printf("===输出n(n<9)行三角形数字===\n");
	printf("请输入您要输出的行数n\n");
again:
	scanf("%d",&n);
	if(n>9||n<1)
	{
		printf("您的输出有误，请重新输入！注意：其中 1<n<9 \n");
		goto again;
	}
	printf("\n输出的结果：\n");
	for(j=1;j<=n;j++)
	{
		for(i=j;i<n;i++)
			printf(" ");
		for(i=1;i<j;i++)
			printf("%d",i);
		for(i=j;i>0;i--)
			printf("%d",i);
		printf("\n");
	}
	printf("\n\n\n谢谢您的使用！\n");
}

