#include <stdio.h>
void main()
{
	int i,r=0;
	float k,sum=0;
	printf("===计算学生平均成绩===\n");
	printf("请您输入学生成绩：\n\n");
	for(i=1;;i++)
	{
		printf("请您输入第%d个人的分数:\n",i);
		scanf("%f",&k);
		sum+=k;
		if(k>=90)
			r++;
		else if(k<0)
			break;

	}
	printf("\n\n%d个人的总分为：%0.2f\n平均分为：%0.2f\n90分以上的人为：%d人\n",i,sum,sum/i,r);
	printf("\n\n\n谢谢您的使用！\n\n\n");


}
