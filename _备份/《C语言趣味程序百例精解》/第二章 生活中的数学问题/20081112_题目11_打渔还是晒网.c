#include <stdio.h>
void main(void)
{
	int be_year,be_month,be_day,year,month,day;
	int sum_year_day=0,be_sum_mon_day=0,be_mon_day,sum_mon_day=0;
	int i,j,k=0,sum,p;
	int mon_leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};	//��һ��Ϊ:0,�����ں������ƥ���·�
	int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("===�������������===\n");
	printf("�������뿪ʼ�����������,��ʽ:YYYY MM DD\n");
	scanf("%d%d%d",&be_year,&be_month,&be_day);
	printf("���������������һ��,��ʽ: YYYY MM DD\n");
	scanf("%d%d%d",&year,&month,&day);
	for(i=be_year+1;i<year;i++){
		if(i%400==0||(i%4==0&&i%100!=0))
			k++;	//�����������������м�������
	}
	if(year>be_year){
		sum_year_day=(year-be_year-1)*365+k;	//����be_year��year֮������������
	}
		if(be_year%400==0||(be_year%4==0&&be_year%100!=0)){
			be_mon_day=mon_leap[be_month]-be_day+1;
			if(be_year!=year)
				j=12;
			else
				j=month;
			for(i=be_month+1;i<j;i++){
				be_sum_mon_day+=mon_leap[i];
			}
		} //����ʼ����Ϊ����ʱ,����ĵ��껹ʣ�¶�����
		else{
			be_mon_day=mon[be_month]-be_day+1;
			if(be_year!=year)
				j=12;
			else
				j=month;
			for(i=be_month+1;i<j;i++){
				be_sum_mon_day+=mon[i];
			}
		} //����ʼ���ڲ�Ϊ����ʱ,����ĵ��껹ʣ�¶�����


		if(year%400==0||(year%4==0&&year%100!=0)){
			day--;
			if(be_year!=year)
				i=1;
			else
				i=be_month;
			for(;i<month;i++){
				sum_mon_day+=mon_leap[i];
			}
		} //����������Ϊ����ʱ,����ĵ��껹ʣ�¶�����
		else{
			day--;
			if(be_year!=year)
				i=1;
			else
				i=be_month;
				for(;i<month;i++){
					sum_mon_day+=mon[i];
				}
		} //���������ڲ�Ϊ����ʱ,����ĵ��껹ʣ�¶�����

		if(be_year==year)
			sum_mon_day=0;


	sum=sum_year_day+be_mon_day+be_sum_mon_day+day+sum_mon_day;
	printf("\n�ڼ侭��%d��,�ǹ�%d��'�����������ɹ��'\n",sum,sum/5);
	p=sum%5;
	switch(p){
	case 0:printf("��ʼ��һ�������\n");break;
	case 1:printf("��ʼ�ڶ��������\n");break;
	case 2:printf("��ʼ�����������\n");break;
	case 3:printf("��ʼ��һ��ɹ����\n");break;
	case 4:printf("��ʼ�ڶ���ɹ����\n");break;
	default:printf("������!p=%d\n",p);
	}
	printf("\n\n\nлл����ʹ��!\n\n\n");

}