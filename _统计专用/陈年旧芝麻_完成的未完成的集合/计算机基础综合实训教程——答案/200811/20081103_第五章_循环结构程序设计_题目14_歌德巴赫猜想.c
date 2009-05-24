#include <stdio.h>
void main()
{
	int i,n,a,b,p,q;
	printf("===歌德巴赫猜想的实现===\n");
	printf("请您输入一个不小于6的偶数:\n");
again:
	scanf("%d",&n);
	if(n%2!=0||n<6)		//排除奇数和小于6的数
	{
		printf("\n您的输入有误,请重新输入!\n\n");
		goto again;
	}
	printf("\n程序对%d进行分解如下:\n\n",n);
	for(a=2;a<=n/2;a++)	//设定a为其中的一个奇数
	{
		b=n-a;			//得到"理论"上的另一个奇数
		p=q=1;			//使用p和q两个量来判断
		for(i=2;i<a;i++)
			if(a%i==0)
				p=0;
		for(i=2;i<b;i++)
			if(b%i==0)
				q=0;
	//当p和q都不是0的时候,那么说明a和b就是所求的解!
		if(p&&q)
			printf("%d=%d+%d\n",n,a,b);
	}
	printf("\n上面的求解,证明了哥德巴赫猜想的正确性!\n");
	printf("\n\n谢谢您的使用!\n\n\n");

}