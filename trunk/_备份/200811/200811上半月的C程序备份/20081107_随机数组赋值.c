#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int h,i=0,j,k=0,p,d;
	int str[10],str2[10],strc[10];
	printf("===数组的随机赋值===\n");
	printf("请您连续输入,程序将生成一个10位数组:\n");
	for(i=0;i<10;i++)
		strc[i]=21;
	i=0;
qq:
		printf("请您输入第%d个数字:",i+1);
		scanf("%d",&str[i]);

	//	printf("已经跳到qq\n");
	
	//	printf("str[%d]=%d\n",i,str[i]);//测试!
		srand(time(NULL));
		p=rand();
		p+=123;
		p*=str[i];
		p%=10;
	//	printf("p现在的值为:%d\n\n",p); //测试!
	//	scanf("%d",&d);			//测试!
			strc[i]=p;
			printf("判断p是否重复strc[%d]=%d  p=%d  k=%d\n",i,strc[j],p,k);
			for(h=0;h<10;h++)
			{
			//	printf("h现在的值是:%d\n",h);
				if(j==h)
					continue;
				else if(p==strc[h])
				{
					printf("将要跳到qq了!\n");
					goto qq;
				}
			}
			i++;
			if(i>=10)
				goto end;
			goto qq;
		str2[p]=str[i];
		printf("\nstr[%d]=str[%d]:%d\n",p,i,str[i]);
end:
	printf("\n您输入的第一个数组为:\n");
	for(i=0;i<10;i++)
	{
		printf("  %d",str[i]);
	}
	printf("\n上面的数组已经被程序随机赋值,变成str2:\n");
	for(i=0;i<10;i++)
	{
		printf("  %d",str2[i]);
	}
	printf("\n\n谢谢您的使用!\n\n");
	scanf("%d",&d);

}
