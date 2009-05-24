#include <stdio.h>
void main()
{
	int i,j,n;
	printf("===输出n(n<9)行三角形数字===\n");
	printf("请输入您要输出的行数n\n");
again:
	scanf("%d",&n);
	if(n>9)
	{
		printf("您的输出有误，请重新输入！\n");
		goto again;
	}
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
}

