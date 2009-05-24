#include <stdio.h>
#include <math.h>
void main()
{
	int i,x,m,p;							//x表示横坐标
	double y;							//y表示纵坐标
	printf("===0~360度内正弦图形的输出===\n");
	for(y=1;y>=-1;y=y-0.1)
	{
		p=-31*(y-1);
		if(y>=0)						//正弦的上面部分
		{
			x=asin(y)*10;
			m=31-x;	
		}
		else							//正弦的下面部分
		{
			x=(asin(y)+2*3.1415926)*10;	
			m=94-x;	
		}
		for(i=0;i<=62;i++)
		{
			if(i==p)
				printf("#");
			else if(i==x||i==m)
				printf("*");			//用"*"代表图形
			else
				printf(" ");
		}
		printf("\n");					//每行的回车
	}
}