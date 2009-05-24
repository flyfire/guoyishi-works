#include <stdio.h>
void main(void)
{
	int i,p=1,n,m;
	printf("===高次方数的尾数===\n");
	printf("请输入底数和幂:");
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		p*=n;
		p%=1000;
		printf("%d的%d次方的后三位为:%d\n",n,i,p);
	}
	if(m<=0)
		printf("您所输入的幂有问题!\n");
	printf("\n\n谢谢您的使用!\n\n");

}