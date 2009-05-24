#include <stdio.h>
void main(void)
{
	int i,flag=1;
	long m,n,sum;
	printf("===2008-1-累加和问题===\n");
	while(flag)
	{
		sum=0;		//对累加结果每次进行清零
		printf("请您输入m和n:");
		scanf("%d%d",&m,&n);
		for(i=m;i<=n;i++)
		{
			sum+=i;
		}			//实现累加
		if(m==0&&n==0)
			flag=0;	//判断是否退出循环
		else
			printf("累加和为:%d\n",sum);
	}
	printf("\n\n谢谢您的使用!\n\n");

}