#include <stdio.h>
void main()
{
	int i,n;
	printf("===求最大约数===\n");
	printf("请输入您要求解的数:");
	scanf("%d",&n);
	for(i=999;i>99;i--)
	{
		if(n%i==0)
			break;
	}
	printf("您输入的%d的最大三位约数是%d\n",n,i);
	printf("谢谢您的使用!\n");

}