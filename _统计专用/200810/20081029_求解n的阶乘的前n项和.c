#include <stdio.h>
void main()
{
	int i,n,t=1;
	double s=0;
	printf("===求解前n项的阶乘的和===\n");
	printf("请您输入项数n：\n");
	scanf("%d",&n);
	printf("您输入的项数n为：%d\n",n);
	for(i=1;i<=n;i++)/*这个for循环实现了每个n的阶乘的输出，使输出更便于读懂与分析*/
	{
		t=t*i;
		s=s+t;
		printf("%d!=%-d\n",i,t,s);

	}
		s=0;i=1;t=1;/*此处的清零和赋值为1很重要！*/
	printf("\n结果为：\n");
	for(i=1;i<=n;i++)
	{
		t=t*i;
		s=s+t;
		printf("%d!",i);
		if(i<n)/*加号的连续输出时判断。*/
			printf("+");
	}
	printf("=%1.0f\n",s);
	printf("谢谢您的使用！\n");
}

/*程序分别用了两个for循环，来增强程序输出效果的可读性，使结果更加直观！*/