#include <stdio.h>
void main(void)
{
	int i,k=0;
	printf("===������λ�������===\n");
	for(i=10006;i<100000;i+=10)
	{
		if(i%3==0)
		{
			printf("%d��������\n",i);
			k++;
		}
	}
	printf("����%d��������������\n",k);
	printf("лл����ʹ��!\n");
}