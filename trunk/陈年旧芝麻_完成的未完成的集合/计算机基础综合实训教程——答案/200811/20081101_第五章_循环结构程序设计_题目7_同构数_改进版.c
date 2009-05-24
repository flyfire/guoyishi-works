#include <stdio.h>
void main()
{
	int i,k;
	long p;
	printf("===输出1~9999之间的同构数===\n");
	printf("程序为您计算出的1~9999之间的同构数为:\n\n");
	k=10;
	for(i=1;i<=9999;i++)
	{

		p=i*i;
		if(p%k==i)
			printf("%d ",i);
		else if(i/k==1)		//这个地方很重要!!!,一定要判断好!
		k*=10;
	}
	printf("\n\n\n谢谢您的使用!\n\n");

}

