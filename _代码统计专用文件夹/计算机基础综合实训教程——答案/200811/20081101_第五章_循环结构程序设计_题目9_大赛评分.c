#include <stdio.h>
#include <math.h>
void main()
{
	int i,max,min,s[10],sum=0,m,n,n1,m1,k;
	double p;		//ƽ����
	printf("===���ִ�������===\n");
	printf("����ί���,���ֵ(����1С��100):\n");
	for(i=0;i<10;i++)			//�õ�10����,��������
	{
		k=1;
		while(k)
		{
			printf("��%d����ί���:",i+1);
			scanf("%d",&s[i]);
			if(s[i]<100&&s[i]>1)
				k=0;
		}
	}
	printf("\n��ί���δ��Ϊ:\n");
	for(i=0;i<10;i++)
	{
		printf("%d  ",s[i]);
	}
	max=min=s[0];				//�����ֵ
	for(i=0;i<10;i++)			//ͨ��ѭ���Ƚϵõ����ֵ����Сֵ
	{
		if(s[i]<min)
			min=s[i];
		if(s[i]>max)
			max=s[i];
		sum+=s[i];				//��ʡ��ʡ!�򵥲�����!
	}
	p=(sum-max-min)/8.0;		//������ų���ߺ���͵ķ���,Ȼ���ٳ���8����
	m=max>min?max:min;			//���������
	n=p;						//���������
	for(i=0;i<10;i++)
	{
		if(fabs(s[i]-p)<fabs(m-p))
		{
			m=s[i];
			m1=i;
		}
		if(fabs(s[i]-p)>fabs(n-p))
		{
			n=s[i];
			n1=i;
		}
	}
	printf("\n\nȥ��һ����߷�%d,ȥ��һ����ͷ�%d,���Ľ��Ϊ:%.2f",max,min,p);		//������
	printf("\n��������%d����ί ��(��)����%d��,��������%d����ί ��(��)����%d��\n",m1+1,m,n1+1,n);
	printf("\n\nлл����ʹ��!\n\n\n");
}

