#include <stdio.h>
void main(void)
{
	int i,j,n;
	int fun(int x,int y);
	printf("===杨辉三角的输出===\n");
	printf("N :");						//得到要输出的行数
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)				//输出空格,使之成为"三角形"
			printf("   ");
		for(j=1;j<=i;j++)
			printf("%6d",fun(i,j));		//在这里调用一个函数!
		printf("\n");
	}

}

int fun(int x,int y)					//被调用的函数,用来输出i行j列的值
{
	int z;
	if(y==1||x==y)						//输出"三角形"的"1"
		return 1;
	z=fun(x-1,y-1)+fun(x-1,y);
	return z;
}