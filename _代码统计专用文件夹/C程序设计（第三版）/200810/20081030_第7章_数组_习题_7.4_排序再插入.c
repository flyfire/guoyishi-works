#include <stdio.h>
#define SIZE 10
void main()
{
	int i,n,str[SIZE],temp;
	printf("===����������������ֵ������===\n");
	printf("����������һ��%dλ�����飡\n",SIZE); /*��������й��ɵ����飬�пն�����иı�*/
	for(i=0;i<SIZE;i++)
	{
		printf("\n���������%d������:",i+1);
	scanf("%d",&str[i]);
	}
	printf("��������Ҫ��������֣�\n");
	scanf("%d",&n);
	for(i=0;i<SIZE;i++)
	{
		if(n>=str[i]&&n<=str[i+1])
			temp=i;
	}

	for(i=0;i<SIZE;i++)//���������⣡
	{
		if(i==temp)
		{
			printf("%d ",n);
		}

		printf("%d ",str[i]);
	}

}
