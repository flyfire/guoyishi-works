#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main(void)
{
	int i,j,h,p,q,sum1=0,sum2=0,flag1,flag2;
	int str1[10],str2[10];
	int x;
	float n; 
	float probability(int x);
	printf("===21����Ϸ===\n");
	srand((unsigned)time(NULL));
	for(i=0;i<2;i++)
	{
		p=rand();
		p=p%10+1;
		q=rand();
		q=(q+p+1211)%10+1;
		str1[i]=p;
		str2[i]=q;
		if(i==0)
		{
			printf("����ҷ�һ�Ű���:%d\n",str1[0]);
			printf("����Է�һ�Ű���:����\n");
		}
		if(i==1)
		{
			printf("����ҷ���%d������:%d\n",i,str1[i]);
			printf("����Է���%d������:%d\n",i,str2[i]);
		}

	}


}









void note()
{
	printf("����Ϸ����");
}









float probability(int x)
{
	int q;
	float n;
	srand((unsigned)time(NULL));
	q=rand();
	if(x<10)
	{
		q%=2;
		q+=99;
		n=q/100.0;
		return n;
	}
	if(x>=10&&x<15)
	{
		q%=10;
		q+=90;
		n=q/100.0;
		return n;
	}
	if(x>=15&&x<17)
	{
		q%=20;
		q+=70;
		n=q/100.0;
		return n;
	}
	if(x>=17&&x<19)
	{
		q%=20;
		q+=20;
		n=q/100.0;
		return n;
	}
	if(x==19)
	{
		q%=10;
		q+=10;
		n=q/100.0;
		return n;
	}
	if(x==20)
	{
		q%=10;
		n=q/100.0;
		return n;
	}
	if(x==21)
		return 0;
}