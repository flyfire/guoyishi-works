#include <stdio.h>
void main(void)
{
	int i,p=1,n,m;
	printf("===�ߴη�����β��===\n");
	printf("�������������:");
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		p*=n;
		p%=1000;
		printf("%d��%d�η��ĺ���λΪ:%d\n",n,i,p);
	}
	if(m<=0)
		printf("�����������������!\n");
	printf("\n\nлл����ʹ��!\n\n");

}