#include <stdio.h>
void main(void)
{
	int i,j,r,k,m,n,p,q;
	printf("===����ͼ�������===\n");
	printf("������Ҫ������'�뾶':");
	scanf("%d",&r);
	for(i=1;i<=2*r;i++)		//i��������
	{
		m=r-i;		//m��n�����ϰ벿�ֵĿհ�����Χֵ
		n=r+i;
		p=i-r;		//p��q�����°벿�ֵĿհ�����Χֵ
		q=3*r-i;
		for(j=1;j<=2*r;j++)	//j��������
		{
			if(i<=r)
			{
				if(j<=m||j>=n)
					printf("  ");
				else
					printf(" *");
			}
			else
			{
				if(j<=p||j>=q)
					printf("  ");
				else
					printf(" *");
			}
		}
		printf("\n");		//ʵ�ֻس�����

	}
}