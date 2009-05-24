#include <stdio.h>
void main(void)
{
	int k=1,a,b,c;
	printf("===借书问题探究!(不会做)===\n");
	for(a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b&&c<=5;c++)
			{
				if(a!=c&&b!=c)
					printf(k%5?"  %2d:%d,%d,%d":"  %2d:%d,%d,%d\n",k,a,b,c,k++);		//这个k++居然还可以这样用,太牛了~
																						//终于实现了既能K++,又可以正确的换行
			}
	printf("\n因此共有%d种方法\n",k);
	printf("\n谢谢您的使用!\n\n\n");
}