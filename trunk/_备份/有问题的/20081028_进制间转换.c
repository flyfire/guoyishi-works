#include <stdio.h>
void main()
{
	int i,m,n;
	printf("�˳��򽫽��н��Ƽ��ת��������������ʾ���룡\n");
	printf("1>	10����ת��Ϊ16����\n");
	printf("2>	10����ת��Ϊ 8����\n");
	printf("3>	 8����ת��Ϊ10����\n");
	printf("4>	�˳�ѡ�����\n"); 
	switch(getchar())
	{
	case 1: m=10;n=16; break;/*???????????????????????????????�ѵ�WSWITCH�ڲ����ܽ��и�ֵ�����룿*/
	case 2: m=10;n=8; break;
	case 3: m=8;n=10; break;
	case 4: goto end; break;
	}
	printf("��������һ��%d���Ƶ����֣�����Ϊ��ת��Ϊ%d����\n",m,n);
	scanf("%d",&i);
	printf("�������Ϊ��%d������Ϊ��ת����%d����Ϊ��%o",i,n,i);
end:
	printf("ллʹ�ã�\n");
}

