#include <stdio.h>
void main(void)
{
	int i,j,n;
	int fun(int x,int y);
	printf("===������ǵ����===\n");
	printf("N :");						//�õ�Ҫ���������
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)				//����ո�,ʹ֮��Ϊ"������"
			printf("   ");
		for(j=1;j<=i;j++)
			printf("%6d",fun(i,j));		//���������һ������!
		printf("\n");
	}

}

int fun(int x,int y)					//�����õĺ���,�������i��j�е�ֵ
{
	int z;
	if(y==1||x==y)						//���"������"��"1"
		return 1;
	z=fun(x-1,y-1)+fun(x-1,y);
	return z;
}