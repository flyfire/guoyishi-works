#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	void note();
	int a,i=0,n,k=19881211;
	int t1,t2;
	int q,choice;
	printf("\n===����������===\n\n");
	note();		//�������!
start:
	srand((unsigned)time(NULL)); 
	a=rand();
	printf("\n\n��������Ϊ�����������,�������ĵȴ�!\n\n");
	do
	{
		if(a%2==0)
			a++;
		else
			a++;
		a+=1234;
		a*=123456789;
		a%=10000;
		k-=1211;
		t1=1;
		t2=1;
		if(a<10000&&a>1000)
			t1=0;
		if(k<0)
			t2=0;
		if(k>200811)
			printf("%d\t",a);
	}while(t1||t2);

	note();
	q=2000;	
	
	printf("\n\n������Ѿ�����������������ɳ���һ�������%d\n\n",a);
	printf("����,�������������������:\n");
	do
	{
		scanf("%d",&n);
		if(n==a)
			printf("\n��ϲ��������ȷ!");
		else if(n>a)
			printf("\n������������е��!�����԰�,����!\n\n");
		else if(n<a)
			printf("\n������������е�С!�����԰�,����!\n\n");
		i++;
		q/=2;
	}while(n!=a);
	printf("��ȷ�𰸾���:%d",a);
	printf("\n����������%d��",i);
	if(i<=10)
		printf("�������%dԪǮ\n������ϵ:��һʵ!\n\n",q);
	else
		printf("\n��,��û�л�,");
be:
	printf("�Ƿ����������Ϸ?\n(����:����1/�뿪:����0)");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:goto start;break;
	case 0:goto end;break;
	default:printf("������������,����������!\n");
		goto be;
	}
end:
	printf("\n\n\nлл����ʹ��!\n\n\n");
}

void note()		//���������
{
	int p=3,q=1000,l=1;	
	printf("\n��Ϸ����:\n\n");
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
}
