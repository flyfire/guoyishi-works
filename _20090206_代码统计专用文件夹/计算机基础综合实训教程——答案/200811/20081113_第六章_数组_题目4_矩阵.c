#include <stdio.h>
void main(void)
{
	int i,j;
	int str[5][5]={0};	//�Ծ������"����"
	printf("===ͼ�������Ч��===\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(i+j==4)	//"�Խ���"��ֵΪ"1"
				str[i][j]=1;
			if(i+j>4)	//���½Ǹ�ֵΪ"2"
				str[i][j]=2;	
		}
	}	//�Ծ����е����λ�ý��и�ֵ
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%d ",str[i][j]);
		printf("\n");
	}	//�������
	printf("\n\nлл����ʹ��!\n\n");
}