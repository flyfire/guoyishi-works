#include <stdio.h>
void main()
{
	int i,n;
	float s=0,h=0;
	printf("请输入出是高度h,以及弹跳次数n:\n");
	scanf("%f,%d",&h,&n);
	for(i=0;i<=n;i++)
	{
		h=h/2;
		s=s+h;
	}
	printf("它在第%d次落地时，共经过%4.0f米\n",n,s);
	printf("在第%d次反弹%6.0f米高\n",n,h);
}