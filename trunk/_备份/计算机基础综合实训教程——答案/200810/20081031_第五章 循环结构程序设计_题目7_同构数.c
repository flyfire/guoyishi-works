#include <stdio.h>
#include <math.h>
void main()
{
	int i,m,n,k,t;
	printf("===1~99֮��ͬ���������===\n");
	printf("����Ϊ�������1~999֮���ͬ����Ϊ:\n");
	for(i=1;i<1000;i++)
	{
		if(i-1>=0)
			t=10;
		if(i-10>=0)
			t=100;
		if(i-100>=0)
			t=1000;
		m=pow(i,2);
		n=m%t;
		if(i==n)
		{
			printf("%d  ",i);
			k++;
		}
		else if(k/5==0)
			printf("\n");
	}
	printf("лл����ʹ��!\n");
}

