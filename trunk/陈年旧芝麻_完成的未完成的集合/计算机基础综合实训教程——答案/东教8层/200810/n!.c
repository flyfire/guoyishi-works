#include <stdio.h>
void main()
{
	int n,i;  /*n代表多少项，i代表第i项*/
	float d=1;  /*结果d*/
	printf("求n的阶乘，请输入:\n项数n：");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		d=d*i;
	}
	printf("%d的阶乘结果是：%-9.2f\n",n,d);
}