#include <stdio.h>
#include <math.h>
void main()
{
	int i,max,min,s[10],sum=0,m,n,n1,m1,k;
	double p;		//平均分
	printf("===歌手大赛评分===\n");
	printf("请评委打分,其分值(大于1小于100):\n");
	for(i=0;i<10;i++)			//得到10个数,赋予数组
	{
		k=1;
		while(k)
		{
			printf("请%d号评委打分:",i+1);
			scanf("%d",&s[i]);
			if(s[i]<100&&s[i]>1)
				k=0;
		}
	}
	printf("\n评委依次打分为:\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",s[i]);
	}
	max=min=s[0];				//赋予初值
	for(i=0;i<10;i++)			//通过循环比较得到最大值和最小值
	{
		if(s[i]<min)
			min=s[i];
		if(s[i]>max)
			max=s[i];
		sum+=s[i];				//能省就省!简单才是美!
	}
	p=(sum-max-min)/8.0;		//计算出排除最高和最低的分数,然后再除以8个人
	m=max>min?max:min;			//最合理打分者
	n=p;						//最不合理打分者
	for(i=0;i<10;i++)
	{
		if(fabs(s[i]-p)<fabs(m-p))
		{
			m=s[i];
			m1=i;
		}
		if(fabs(s[i]-p)>fabs(n-p))
		{
			n=s[i];
			n1=i;
		}
	}
	printf("\n\n去掉一个最高分%d,去掉一个最低分%d,最后的结果为:%.2f",max,min,p);		//输出结果
	printf("\n最合理的是%d号评委 他(她)打了%d分,最不合理的是%d号评委 他(她)打了%d分\n",m1+1,m,n1+1,n);
	printf("\n\n谢谢您的使用!\n\n\n");
}

