#include <stdio.h>
#include <math.h>
void main()
{
	int i,a,n,k=0,t=0;//k��ʾ��n���ֵ��t��ʾ��n��û�г���a֮ǰ��ֵ�����磺1111111
	long sn=0;  //���������Ϊ������
	printf("===n��a����������===\n");
	printf("���򽫽���Sn=a+aa+aaa+...+aa...aa�����㣬��������a��n\n");
	scanf("%d%d",&a,&n); 
	printf("�����Ľ���ǣ�\n");
	for(i=0;i<n;i++)
	{
		t=t+pow(10,i);  
		k=t*a;
		sn=sn+k;
		printf("%ld",k);
		if(i<n-1)   //�ж��ǲ������һ������,����������"+"����ǵĻ����"="
			printf("+");
		else
			printf("=");
	}
	printf("%ld\n\n",sn);        //������Ľ��
	printf("лл����ʹ�ã�\n");
}

