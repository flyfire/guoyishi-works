#include <stdio.h>
void main()
{
	char n;
	printf("������A,B,C,D�е�һ��������Ч��\n");
	scanf("%c",&n);
	printf("���������%c:\n",n);
	switch(n)
	{
	case'A':printf("����һ��\n");break;
	case'B':printf("���˰�\n");break;
	case'C':printf("����ػ�\n");break;
	case'D':printf("��~~��\n");break;
	default:printf("û����Ʒ�����㣡Ϊʲô�����涨�����أ�");break;
	}
}
/*2008.10.13 15:40 �ܸ�Ц���Ǻ�*/