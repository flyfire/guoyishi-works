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
		for(i=3;i<=temp;i+=2)//�ĳ�+2 
			if(n%i==0) 
				break; 
		printf("%d ", n);//֮ǰ���ж�ȥ�� 
	} 
	printf("\n"); 
	t2=clock();
	printf("ϵͳ����ʱ��Ϊ:%dms\n\n\n",t2-t1);

}