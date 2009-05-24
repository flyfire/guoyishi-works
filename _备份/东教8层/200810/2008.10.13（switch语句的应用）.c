#include <stdio.h>
void main()
{
	char n;
	printf("请输入A,B,C,D中的一个，测试效果\n");
	scanf("%c",&n);
	printf("您输入的是%c:\n",n);
	switch(n)
	{
	case'A':printf("好人一个\n");break;
	case'B':printf("好人啊\n");break;
	case'C':printf("差不多呢还\n");break;
	case'D':printf("哎~~！\n");break;
	default:printf("没有人品啊，你！为什么不按规定的来呢？");break;
	}
}
/*2008.10.13 15:40 很搞笑！呵呵*/