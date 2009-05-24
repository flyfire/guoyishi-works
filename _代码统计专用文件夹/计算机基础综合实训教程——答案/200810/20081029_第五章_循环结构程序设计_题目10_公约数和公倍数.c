#include <stdio.h>
void main()
{
	int m,n,x,p,q;
	printf("===公约数和公倍数的判断===\n");
	printf("请您输入三个正整数  m n x 程序将判断x与m、n的关系：\n");
	printf("输入： 0 0 0 结束程序！\n"); 
start: /*设置循环，实现连续的输入*/
	printf("请您输入：");
	scanf("%d%d%d",&m,&n,&x);
	p=0;q=0; /*利用p、q的赋值，来判断是否满足判断条件*/
	if(m==0&&m==0&&n==0) /*退出程序的判断*/
		goto end;

	if((m%x==0)&&(n%x==0))/*公约数*/
		p=1;
	if((x%m==0)&&(x%n==0))/*公倍数*/
		q=1;
	switch(p)/*利用上面的p值来判断公约数*/
	{
		case 1:printf("您输入的%d是%d和%d的公约数，",x,m,n);break;
		case 0:printf("您输入的%d不是%d和%d的公约数，",x,m,n);break;
	}
	switch(q)/*利用上面的q值来判断公倍数*/
	{
		case 1:printf("是%d和%d的公倍数。\n\n\n",m,n);break;
		case 0:printf("不是%d和%d的公倍数。\n\n\n",m,n);break;
	}
	goto start;/*实现循环*/
end: /*退出程序！*/
	printf("\n\n\n谢谢您的使用！\n\n");

}