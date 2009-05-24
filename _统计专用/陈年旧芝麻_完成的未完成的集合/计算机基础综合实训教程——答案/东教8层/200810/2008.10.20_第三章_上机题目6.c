#include <stdio.h>
void main()
{
	int h,f,x,y;
	printf("请输入 头 脚：\n");
	scanf("%d %d",&h,&f);
	x=(4*h-f)/2;
	y=(f-2*h)/2;
	printf("那么\n鸡有:%d 只\n兔子有%d只\n",x,y);

}
