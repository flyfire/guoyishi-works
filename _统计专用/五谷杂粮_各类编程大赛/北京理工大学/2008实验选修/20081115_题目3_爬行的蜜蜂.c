#include <stdio.h>
void main(void)
{
	int i,a,b,flag=1;
	double s1=1,s2=1,st;
	printf("===2008-3-爬行的蜜蜂===\n");
	while(flag)
	{
		while(flag)
		{
			printf("的的的道德搜索啊啊啊啊啊啊");
			scanf("%d%d",&a,&b);
			if(a<b&&a>0&&a<=50&&b>0&&b<=50)
				flag=0;
		}
		flag=1;
		for(i=a;i<b;i++)	//斐波那契
		{
			st=s2;
			s2+=s1;
			s1=st;
		}
		printf("共有%.0f种路线\n",s1);
		if(a==0&&b==0)
			flag=0;
	}
}