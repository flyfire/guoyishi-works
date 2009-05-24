#include <stdio.h>
void main(void)
{
	int be_year,be_month,be_day,year,month,day;
	int sum_year_day=0,be_sum_mon_day=0,be_mon_day,sum_mon_day=0;
	int i,j,k=0,sum,p;
	int mon_leap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};	//第一设为:0,这样在后面就能匹配月份
	int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	printf("===打渔和上网问题===\n");
	printf("请您输入开始打渔的年月日,格式:YYYY MM DD\n");
	scanf("%d%d%d",&be_year,&be_month,&be_day);
	printf("请输入您想求的那一天,格式: YYYY MM DD\n");
	scanf("%d%d%d",&year,&month,&day);
	for(i=be_year+1;i<year;i++){
		if(i%400==0||(i%4==0&&i%100!=0))
			k++;	//计算这两个日期中有几个闰年
	}
	if(year>be_year){
		sum_year_day=(year-be_year-1)*365+k;	//计算be_year到year之间的整年的天数
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
		} //当起始日期为闰年时,计算的当年还剩下多少天
		else{
			be_mon_day=mon[be_month]-be_day+1;
			if(be_year!=year)
				j=12;
			else
				j=month;
			for(i=be_month+1;i<j;i++){
				be_sum_mon_day+=mon[i];
			}
		} //当起始日期不为闰年时,计算的当年还剩下多少天


		if(year%400==0||(year%4==0&&year%100!=0)){
			day--;
			if(be_year!=year)
				i=1;
			else
				i=be_month;
			for(;i<month;i++){
				sum_mon_day+=mon_leap[i];
			}
		} //当结束日期为闰年时,计算的当年还剩下多少天
		else{
			day--;
			if(be_year!=year)
				i=1;
			else
				i=be_month;
				for(;i<month;i++){
					sum_mon_day+=mon[i];
				}
		} //当结束日期不为闰年时,计算的当年还剩下多少天

		if(be_year==year)
			sum_mon_day=0;


	sum=sum_year_day+be_mon_day+be_sum_mon_day+day+sum_mon_day;
	printf("\n期间经过%d天,记过%d个'三天打鱼两天晒网'\n",sum,sum/5);
	p=sum%5;
	switch(p){
	case 0:printf("开始第一天打渔了\n");break;
	case 1:printf("开始第二天打渔了\n");break;
	case 2:printf("开始第三天打渔了\n");break;
	case 3:printf("开始第一天晒网了\n");break;
	case 4:printf("开始第二天晒网了\n");break;
	default:printf("出错了!p=%d\n",p);
	}
	printf("\n\n\n谢谢您的使用!\n\n\n");

}