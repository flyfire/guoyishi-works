#include <stdio.h>
#include <math.h>
void main()
{
	int i,m,n,k,t;
	printf("===1~99之间同构数的输出===\n");
	printf("程序为您输出的1~999之间的同构数为:\n");
	for(i=1;i<1000;i++)
	{
		if(i-1>=0)
			t=10;
		if(i-10>=0)
			t=100;
		if(i-100>=0)
			t=1000;
		m=pow(i,2);
		n=m%t;
		if(i==n)
		{
			printf("%d  ",i);
			k++;
		}
		else if(k/5==0)
			printf("\n");
	}
	printf("谢谢您的使用!\n");
}

