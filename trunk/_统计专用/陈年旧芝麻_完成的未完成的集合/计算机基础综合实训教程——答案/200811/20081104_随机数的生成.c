#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int a,i=0,n,k=1211;
	int t1,t2;
	int p=3,q=1000,l=1;		//���������
	printf("===����������===\n\n");
	printf("��Ϸ����:\n\n");
	printf("---------------------------------\n");
	printf("1>	ÿ����Ϸ1ԪǮ.\n");
	printf("2>	���򽫲���һ��4λ�����.\n");
	while(q>0)
	{
		printf("%d>	%d�δ�Խ���%dԪǮ.\n",p,l,q);
		l++;
		p++;
		q/=2;
	}
	printf("%d>	10�����ϲŴ�Ծ�û���κν���!\n",l);
start:
	srand((unsigned)time(NULL)); 
	a=rand();
	printf("��������Ϊ�����������,�������ĵȴ�!\n\n");

	do
	{
		a*=19881211;
		a%=10000;
		k-=2;
		t1=1;
		t2=1;
		if(a<10000&&a>1000)
			t1=0;
		if(k<0)
			t2=0;
		if(k>14)
			printf("%d  ",a);
	}while(t1||t2);

	p=3;		//�ٴθ�ֵ!
	l=1;		//�ٴθ�ֵ!
	q=1000;		//�ٴθ���q��ֵ!

	printf("\n\n��Ϸ����:\n\n");
	printf("---------------------------------\n");
	printf("1>	ÿ����Ϸ1ԪǮ.\n");
	printf("2>	���򽫲���һ��4λ�����.\n");
	while(q>0)
	{
		printf("%d>	%d�δ�Խ���%dԪǮ.\n",p,l,q);
		l++;
		p++;
		q/=2;
	}
	printf("%d>	10�����ϲŴ�Ծ�û���κν���!\n",l);

	q=2000;		//

	printf("\n\n������Ѿ�����������������ɳ���һ�������%d\n\n",a);
	printf("����,�������������������:\n");
	do
	{
		scanf("%d",&n);
		if(n==a)
			printf("\n��ϲ��������ȷ!\n\n");
		else if(n>a)
			printf("\n������������е��!�����԰�,����!\n\n");
		else if(n<a)
			printf("\n������������е�С!�����԰�,����!\n\n");
		i++;
		q/=2;
	}while(n!=a);
	printf("\n��ȷ�𰸾���:%d",a);
	printf("\n����������%d��\n\n",i);
	if(i<=12)
		printf("�������%dԪǮ\n������ϵ:��һʵ!\n\n",q);
	else
	{

		printf("��,��û�л�,����һ��!\n\n");
		goto start;
	}
	printf("лл����ʹ��!\n\n\n");
}