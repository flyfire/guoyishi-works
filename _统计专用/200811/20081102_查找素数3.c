#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int i,n,temp;
	int t1,t2;
	t1=clock();
	printf("%d ", 2); 
	for(n=3; n<=100000; n+=2) 
	{ 
		temp=sqrt(n);	
		for(i=3;i<=temp;i+=2)//改成+2 
			if(n%i==0) 
				break; 
		printf("%d ", n);//之前的判断去掉 
	} 
	printf("\n"); 
	t2=clock();
	printf("系统运行时间为:%dms\n\n\n",t2-t1);

}