#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int i,k,p=0,j;
	int t1,t2;
	t1=clock();
	printf("===查找素数===\n");
	printf("程序为您找到的素数为:\n");
	for(i=1;p=0,i<100000;i++)
	{
		k=sqrt(i);
		for(j=2;j<=k;j++)
		{	
			if(i%j==0)
			{
				p=1;
				break;
			}
		}
		if(!p)
			printf("%d ",i);

	}
	printf("\n\n\n");
	t2=clock();
	printf("系统运行时间为:%dms\n\n\n",t2-t1);

}