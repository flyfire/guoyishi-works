#include <stdio.h>
void main()
{
	int a,b,c,n;
	printf("����3����\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("�������:\na=%d,b=%d,c=%d\n",a,b,c);
	if(a<b)
	{
		n=a;
		a=b;
		b=n;
	}
	if(a<c)
	{
		n=a;
		a=c;
		c=n;
	}
	if(b<c)
	{
		n=b;
		b=c;
		c=n;
	}
	printf("�����%d,%d,%d\n",a,b,c);
}
/*�����ɹ����Ժ�Ӧ��Ӧ��ָ�������⣡2008.10.13 14:11*/