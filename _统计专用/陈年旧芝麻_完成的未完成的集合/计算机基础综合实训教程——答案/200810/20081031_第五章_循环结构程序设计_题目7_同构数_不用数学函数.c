#include <stdio.h>
void main()
{
	int i,n,t,p,q;
	printf("===ͬ���������===\n");
	printf("������������������,����Ϊ���������֮���ͬ����:\n");
start:
	scanf("%d%d",&p,&q);
	if(q>10000)
	{
		printf("���������%d����10000\n",q);
		printf("������������,лл:\n");
		goto start;
	}
	printf("����Ϊ�������%d~%d֮���ͬ����Ϊ:\n",p,q);
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
		
	printf("\n\nлл����ʹ��!\n\n");
}

/*
#include<stdio,h>
����main()
	{
����long i,j,k;
����k=10;
����for (i=1;i<=10000;i++)
	{
����if (i==k) k*=10;
����j=i*i;
����if(j%k==i) printf("%ld\t%ld\n",i,j);
����}
����}

*/