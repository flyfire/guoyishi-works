#include <stdio.h>
void main()
{
	int i,k,m,n,r;
	long p;
	printf("===���������֮���ͬ����===\n");
	printf("��������������:\n");
	scanf("%d%d",&m,&n);
	printf("����Ϊ���������%d~%d֮���ͬ����Ϊ:\n\n",m,n);
	k=1;
	r=m;
	while(r)
	{
		k*=10;
		r/=10;

	}
	for(i=m;i<=n;i++)
	{
		p=i*i;
		if(p%k==i)
			printf("%d ",i);
		else if(i==k)		//����ط�����Ҫ!!!,һ��Ҫ�жϺ�!
			k*=10;
	}
	printf("\n\n\nлл����ʹ��!\n\n");

}

