#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int t1,t2;
	int i,k,m;
	t1=clock();
	printf("===���һ�����===\n");
	printf("����Ϊ�����ҳ��Ļ�����Ϊ:\n");
	for(i=1;i<1000;i++)
	{
		if(i%10==0)
			continue;
		printf("%d  ",i);

	}
	printf("\n\n\nлл����ʹ��\n\n\n");
	t2=clock();
	printf("ϵͳ����ʱ��Ϊ:%dms\n\n\n",t2-t1);

}