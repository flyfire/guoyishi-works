#include <stdio.h>
void main(void)
{
	int i,flag=1;
	long m,n,sum;
	printf("===2008-1-�ۼӺ�����===\n");
	while(flag)
	{
		sum=0;		//���ۼӽ��ÿ�ν�������
		printf("��������m��n:");
		scanf("%d%d",&m,&n);
		for(i=m;i<=n;i++)
		{
			sum+=i;
		}			//ʵ���ۼ�
		if(m==0&&n==0)
			flag=0;	//�ж��Ƿ��˳�ѭ��
		else
			printf("�ۼӺ�Ϊ:%d\n",sum);
	}
	printf("\n\nлл����ʹ��!\n\n");

}