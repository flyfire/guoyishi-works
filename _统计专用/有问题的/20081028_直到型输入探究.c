#include <stdio.h>
void main()
{
	int i,p;
	printf("这个程序的主要目的是探索直到型输入正确格式的数据\n");
	printf("请您输入一个三位数，并按回车结束\n");
again:
	scanf("%d",&i);
	if(i>99&&i<1000)
		printf("您输入的格式是正确的。谢谢您的合作！\n");
	else
	{
		printf("您的输入有误，请您重新输入！\n");
		goto again;
	}

}
/*????????????????为什么当输入非数字的数据时程序错误？？？？*/