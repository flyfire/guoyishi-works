#include <stdio.h>
void main()
{
	int i,j,n;
	printf("===���n(n<9)������������===\n");
	printf("��������Ҫ���������n\n");
again:
	scanf("%d",&n);
	if(n>9||n<1)
	{
		printf("��������������������룡ע�⣺���� 1<n<9 \n");
		goto again;
	}
	printf("\n����Ľ����\n");
	for(j=1;j<=n;j++)
	{
		for(i=j;i<n;i++)
			printf(" ");
		for(i=1;i<j;i++)
			printf("%d",i);
		for(i=j;i>0;i--)
			printf("%d",i);
		printf("\n");
	}
	printf("\n\n\nлл����ʹ�ã�\n");
}

