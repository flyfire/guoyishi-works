#include <stdio.h>
void main()
{
	int i,sign,n;
	float deno,sum; /*项、结果用浮点型*/
	printf("Please Type In The N !\n"); 
	scanf("%d",&n); /*得到n的值*/
	for(i=2,sum=1,sign=1;i<=n;i++)
	{
		sign=(-1)*sign;/*分子，即项的正负*/
		deno=(float)sign/i; /*项*/
		sum=deno+sum;/*结果*/
	}
	printf("The N Is %d\nThe Sum Is %f\n",n,sum); /*输出结果*/

}
/*2008.10.13 14:37测试成功*/