#include <stdio.h>
void main()
{
	int i,k;
	long p;
	printf("===���1~9999֮���ͬ����===\n");
	printf("����Ϊ���������1~9999֮���ͬ����Ϊ:\n\n");
	k=10;
	for(i=1;i<=9999;i++)
	{

		p=i*i;
		if(p%k==i)
			printf("%d ",i);
		else if(i/k==1)		//����ط�����Ҫ!!!,һ��Ҫ�жϺ�!
		k*=10;
	}
	printf("\n\n\nлл����ʹ��!\n\n");

}

