#include <stdio.h>
void main()
{
	int i,j;
	printf("===�˷��ھ�������===\n");
	printf("����Ϊ�������Сʱ��Ŀھ�������\n");
	printf("��������������ͯ��!\n");
	for(i=1;i<=9;i++)							//���9��
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-2d ",j,i,i*j);		//��ʽ�����
		}
		printf("\n");							//�س�����
	}
	printf("\n\n\n");
}

