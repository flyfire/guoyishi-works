#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int i,n,temp;
	int t1,t2;
	t1=clock();
	printf("%d ", 2); //����2������� 
	for(n=3; n<=100000; n+=2) 
	{ 
		temp=sqrt(n); 
		for(i=2; i<=temp; i++) 
			if(n %i == 0) break; //ִ��breakʱΪ����������ѭ�� 
		if(i>temp) printf("%d ", n); //���һ������ 
	} 

	printf("\n\n\n");
	t2=clock();
	printf("ϵͳ����ʱ��Ϊ:%dms\n\n\n",t2-t1);

}