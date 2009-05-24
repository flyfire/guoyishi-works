#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int i,n,temp;
	int t1,t2;
	t1=clock();
	printf("%d ", 2); //素数2单独输出 
	for(n=3; n<=100000; n+=2) 
	{ 
		temp=sqrt(n); 
		for(i=2; i<=temp; i++) 
			if(n %i == 0) break; //执行break时为非正常结束循环 
		if(i>temp) printf("%d ", n); //输出一个素数 
	} 

	printf("\n\n\n");
	t2=clock();
	printf("系统运行时间为:%dms\n\n\n",t2-t1);

}