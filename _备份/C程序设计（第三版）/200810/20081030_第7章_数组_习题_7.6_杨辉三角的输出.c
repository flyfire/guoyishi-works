#include <stdio.h>
#define N 10 /*�޸�����ı����������*/
#define I N
#define J N
void main()
{
	int m,n,str[I][J],end;
	printf("===���%d���������===\n\n",N);    /*???????????????????????����ʹn����ͨ���û�������ȷ������������������������*/
	for(n=1;n<=I;n++)
	{
		for(m=1;m<=n;m++)
		{
			if(m==1)
				str[n][m]=1;
			else if(n==m)
				str[n][m]=1;
			else
				str[n][m]=str[n-1][m-1]+str[n-1][m];
			printf("%3d",str[n][m]);
		}
		printf("\n");
	}
end:
	printf("\n�����룺123 �˳���\n");
	scanf("%d",&end);
	if(end==123)
		printf("лл����ʹ�ã�\n");
	else
	{
		printf("�����������������������룡\n");
			goto end;
	}
}

/*��������������������������������Ϊʲô�������Ǹ�����Ի��򣡣�������������������*/