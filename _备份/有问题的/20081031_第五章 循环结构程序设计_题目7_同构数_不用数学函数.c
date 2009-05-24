#include <stdio.h>
void main()
{
	int i,n,t,p,q;
	printf("===同构数的输出===\n");
	printf("请您输入两个正整数,程序将为您输出它们之间的同构数:\n");
start:
	scanf("%d%d",&p,&q);
	if(q>10000)
	{
		printf("您所输入的%d大于10000\n",q);
		printf("请您重新输入,谢谢:\n");
		goto start;
	}
	printf("程序为您输出的%d~%d之间的同构数为:\n",p,q);
	for(i=p;i<=q;i++)
	{
		if(i-1>=0)
			t=10;
		if(i-10>=0)
			t=100;
		if(i-100>=0)
			t=1000;
		if(i-1000>=0)
			t=10000;

		n=i*i%t;
		if(i==n)
		{
			printf("%4d*%d--->%d\n",i,i,i*i);
		}
	}
		
	printf("\n\n谢谢您的使用!\n\n");
}

/*
#include<stdio,h>
　　main()
	{
　　long i,j,k;
　　k=10;
　　for (i=1;i<=10000;i++)
	{
　　if (i==k) k*=10;
　　j=i*i;
　　if(j%k==i) printf("%ld\t%ld\n",i,j);
　　}
　　}

*/