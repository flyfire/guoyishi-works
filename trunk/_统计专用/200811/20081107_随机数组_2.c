#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{	
	int str[10],str2[10],strc[10];
	int i,q,j,k=1;
	printf("请输入!\n");
	for(i=0;i<10;i++)
		strc[i]=21;
	printf("strc赋值完毕!\n");
	i=0;
start:
	if(i>=10)
		goto end;
	printf("请输入第%d个数字:",i+1);
	scanf("%d",&str[i]);
	printf("\n");
	srand(time(NULL));
	q=rand();
be:
	q+=1;
	q%=10;
	strc[i]=q;
	for(j=0;j<10;j++)
	{
		if(i==j)
			continue;
		if(q==strc[j])
			goto be;
	}
	str2[q]=str[i];
	i++;
	goto start;
end:
	printf("\n输出第一个数组为:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str[i]);

	printf("\n根据对应规则:\n");
	for(i=0;i<10;i++)
	{
		printf("%d--%d  ",i+1,strc[i]+1);
		k++;
		if(k%3==0)
			printf("\n");
	}
	printf("\n输出第二个数组为:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str2[i]);
		

}