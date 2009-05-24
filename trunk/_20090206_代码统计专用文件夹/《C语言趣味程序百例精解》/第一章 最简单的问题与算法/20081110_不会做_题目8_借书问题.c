#include <stdio.h>
void main(void)
{
	int k=0,a,b,c;
	printf("===借书问题探究!===\n");		//看到答案以后才做出来的,还需要努力啊!
	for(a=1;a<5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b&&c<=5;c++)
			{
				if(a!=c&&b!=c)				//此处还可以改进,可以使用: 三目运算符!
				{
					k++;
					printf("第%d种方法:A拿第%d本书,B拿第%d本书,C拿第%d本书\n",k,a,b,c);
				}
			}
	printf("\n因此共有%d种方法\n",k);
	printf("\n谢谢您的使用!\n\n\n");
}