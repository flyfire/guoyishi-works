#include <stdio.h>
void main()
{
	int i,n;
	printf("===�����Լ��===\n");
	printf("��������Ҫ������:");
	scanf("%d",&n);
	for(i=999;i>99;i--)
	{
		if(n%i==0)
			break;
	}
	printf("�������%d�������λԼ����%d\n",n,i);
	printf("лл����ʹ��!\n");

}