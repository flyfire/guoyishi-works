#include <stdio.h>
#include <math.h>
void main()
{
	int i,x,m;			//x表示横坐标
	double y;			//y表示纵坐标
	printf("===0~360度内余弦图形的输出===\n");
	for(y=1;y>=-1;y=y-0.1)
	{
		x=acos(y)*10;	//对x的坐标进行10倍的扩展
		m=62-x;			//由于余弦函数的对称性[(int)62=3.14*2*10]
		for(i=0;i<=62;i++)
		{

			if(i==x||i==m)
				printf("*"); //用"*"代表图形
			else
				printf(" ");
		}
		printf("\n");	//每行的回车
	}
}