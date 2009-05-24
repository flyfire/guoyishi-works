#include <stdio.h>
void main()
{
	int i,n,m;
	printf("===求解一个数字是几位数===\n");
	printf("请您输入要求解的数:\n");
	scanf("%d",&n);
	m=n;		//把n的值赋给m
	for(i=0;n;i++,n/=10);		//注意后面的 “;” 非同小可!
	//如果不使用for函数,而利用while函数求解,过程就是:
	//		while(n)
	//		{
	//			i++;
	//			n/=10;
	//		}
	//其实道理都是一样的
	printf("\n您输入的%d为%d位数\n\n",m,i);			//输出的m就是原来的n值,但现在n值已经改变
	printf("谢谢您的使用!\n\n\n");

}

