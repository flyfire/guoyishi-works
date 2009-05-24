#include <stdio.h>
void main()
{
	int i,k,m,n,r;
	long p;
	printf("===输出两个数之间的同构数===\n");
	printf("请您输入两个数:\n");
	scanf("%d%d",&m,&n);
	printf("程序为您计算出的%d~%d之间的同构数为:\n\n",m,n);
	k=1;
	r=m;
	while(r)
	{
		k*=10;
		r/=10;

	}
	for(i=m;i<=n;i++)
	{
		p=i*i;
		if(p%k==i)
			printf("%d ",i);
		else if(i==k)		//这个地方很重要!!!,一定要判断好!
			k*=10;
	}
	printf("\n\n\n谢谢您的使用!\n\n");

}

