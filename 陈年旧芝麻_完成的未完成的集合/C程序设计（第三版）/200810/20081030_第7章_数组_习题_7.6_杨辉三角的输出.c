#include <stdio.h>
#define N 10 /*修改这里改变输出的行数*/
#define I N
#define J N
void main()
{
	int m,n,str[I][J],end;
	printf("===输出%d行杨辉三角===\n\n",N);    /*???????????????????????怎样使n可以通过用户输入来确定？？？？？？？？？？？*/
	for(n=1;n<=I;n++)
	{
		for(m=1;m<=n;m++)
		{
			if(m==1)
				str[n][m]=1;
			else if(n==m)
				str[n][m]=1;
			else
				str[n][m]=str[n-1][m-1]+str[n-1][m];
			printf("%3d",str[n][m]);
		}
		printf("\n");
	}
end:
	printf("\n请输入：123 退出！\n");
	scanf("%d",&end);
	if(end==123)
		printf("谢谢您的使用！\n");
	else
	{
		printf("您的输入有误，请您重新输入！\n");
			goto end;
	}
}

/*？？？？？？？？？？？？？？？？为什么最后出来那个错误对话框！！！！！！！！！！！*/