#include <stdio.h>
void main()
{
	int i,n,t=1;
	double s=0;
	printf("===���ǰn��Ľ׳˵ĺ�===\n");
	printf("������������n��\n");
	scanf("%d",&n);
	printf("�����������nΪ��%d\n",n);
	for(i=1;i<=n;i++)/*���forѭ��ʵ����ÿ��n�Ľ׳˵������ʹ��������ڶ��������*/
	{
		t=t*i;
		s=s+t;
		printf("%d!=%-d\n",i,t,s);

	}
		s=0;i=1;t=1;/*�˴�������͸�ֵΪ1����Ҫ��*/
	printf("\n���Ϊ��\n");
	for(i=1;i<=n;i++)
	{
		t=t*i;
		s=s+t;
		printf("%d!",i);
		if(i<n)/*�Ӻŵ��������ʱ�жϡ�*/
			printf("+");
	}
	printf("=%1.0f\n",s);
	printf("лл����ʹ�ã�\n");
}

/*����ֱ���������forѭ��������ǿ�������Ч���Ŀɶ��ԣ�ʹ�������ֱ�ۣ�*/