#include <stdio.h>
void main()
{
	int i,j,k,sum;
	printf("===���������===\n");
	printf("����Ϊ���ҵ���1~10000����Ϊ:\n");
	for(i=1;i<=10000;i++)			//��i�����ж�
	{
		for(j=1,sum=0;j<i;j++)		//����i������
		{
			if(i%j==0)				//�ж��ǲ�������
				sum+=j;
		}
		if(i==sum)					//�ж��ǲ�������
		{
			printf("%d ",i);
			k++;
		}
	}
	printf("\n\n\nлл����ʹ��!\n\n\n");
}

