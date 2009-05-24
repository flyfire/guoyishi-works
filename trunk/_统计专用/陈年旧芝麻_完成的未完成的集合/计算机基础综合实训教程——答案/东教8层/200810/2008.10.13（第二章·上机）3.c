#include <stdio.h>
void main()
{
	int a,b,c,n;
	printf("输入3个数\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("您输入的:\na=%d,b=%d,c=%d\n",a,b,c);
	if(a<b)
	{
		n=a;
		a=b;
		b=n;
	}
	if(a<c)
	{
		n=a;
		a=c;
		c=n;
	}
	if(b<c)
	{
		n=b;
		b=c;
		c=n;
	}
	printf("最后结果%d,%d,%d\n",a,b,c);
}
/*基本成功，以后应该应用指针进行求解！2008.10.13 14:11*/