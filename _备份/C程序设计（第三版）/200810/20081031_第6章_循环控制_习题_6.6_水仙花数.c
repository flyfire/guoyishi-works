#include <stdio.h>
#include <math.h>
void main()
{
	int i,a,b,c,t,k=1;
	printf("===输出“水仙花数”===\n");
	printf("程序输出的三位数的水仙花数为：\n");
	for(i=100;i<1000;i++)
	{
		a=i/100;
		b=i/10-10*a;       //一错都错，尽量细心！
		c=i%10;
		t=pow(a,3)+pow(b,3)+pow(c,3);
		if(i==t)
		{
			printf("%5d",i);
			k++;
		}
	}
	if(k/5==0)
		printf("\n");
	printf("\n\n\n谢谢您的使用!\n\n");
}


