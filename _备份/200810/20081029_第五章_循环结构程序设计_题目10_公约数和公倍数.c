#include <stdio.h>
void main()
{
	int m,n,x,p,q;
	printf("===��Լ���͹��������ж�===\n");
	printf("������������������  m n x �����ж�x��m��n�Ĺ�ϵ��\n");
	printf("���룺 0 0 0 ��������\n"); 
start: /*����ѭ����ʵ������������*/
	printf("�������룺");
	scanf("%d%d%d",&m,&n,&x);
	p=0;q=0; /*����p��q�ĸ�ֵ�����ж��Ƿ������ж�����*/
	if(m==0&&m==0&&n==0) /*�˳�������ж�*/
		goto end;

	if((m%x==0)&&(n%x==0))/*��Լ��*/
		p=1;
	if((x%m==0)&&(x%n==0))/*������*/
		q=1;
	switch(p)/*���������pֵ���жϹ�Լ��*/
	{
		case 1:printf("�������%d��%d��%d�Ĺ�Լ����",x,m,n);break;
		case 0:printf("�������%d����%d��%d�Ĺ�Լ����",x,m,n);break;
	}
	switch(q)/*���������qֵ���жϹ�����*/
	{
		case 1:printf("��%d��%d�Ĺ�������\n\n\n",m,n);break;
		case 0:printf("����%d��%d�Ĺ�������\n\n\n",m,n);break;
	}
	goto start;/*ʵ��ѭ��*/
end: /*�˳�����*/
	printf("\n\n\nлл����ʹ�ã�\n\n");

}