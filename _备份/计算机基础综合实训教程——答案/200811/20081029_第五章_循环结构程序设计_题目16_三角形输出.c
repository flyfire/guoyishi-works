#include <stdio.h>
void main()
{
	int i,j,n,k=0;
	printf("===���n(n<9)������������===\n");
	printf("��������Ҫ���������n\n");
	do
	{
		if(k!=0)
			printf("��������������������룡ע�⣺���� 1<n<9 \n");
		scanf("%d",&n);
		k++;
	}while(n>9||n<1);
	printf("\n����Ľ����\n");
	for(j=1;j<=n;j++)
	{
		for(i=j;i<n;i++)
			printf("  ");
		for(i=1;i<j;i++)
			printf(" %d",i);
		for(i=j;i>0;i--)
			printf(" %d",i);
		printf("\n");
	}
	printf("\n\n\nлл����ʹ�ã�\n");
}

