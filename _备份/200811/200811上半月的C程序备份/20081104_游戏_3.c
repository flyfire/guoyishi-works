#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	void note();
	int get(int k);
	int change(int x);
	int end();
	int begin();
	int i,n,k=0,p,q,o,g;
	int a,b,c,d;
	int x,y,z,w;
	int flag;
begin:
	printf("===������Ϸ������!===\n");
	note();
	do
	{
		srand(time(NULL));
		i=change(rand());		//�õ������λ��
		a=i/1000;
		b=i/100-10*a;
		d=i%10;
		c=(i%100-d)/10;
	}while(a==b||a==c||a==d||b==c||b==d||c==d);
	printf("ϵͳ�Ѿ��õ�һ�������\n");
	//          printf("\n\n%d\n\n",i);
	do
	{
		p=0;q=0;o=0;
		switch(k)
		{
		case 0:printf("\n���������²������:\n");break;
		default:printf("\n\n");
		}
start:
		scanf("%d",&n);
		if(n==10101)
		{
			printf("\n��������һ����������,�˳�����.\n\n");
			goto end;
		}
		if(n==19881211)	//͵�����
		{
			printf("���㿴���𰸰�:%d\n",i);
			printf("�Ǻ�,�������!\n\n");
			goto start;
		}
		if(n>10000||n<1000)
		{
			printf("\n������������,��ȷ���Ǹ���λ��,������������!\n\n");
			goto start;
		}
		x=n/1000;
		y=n/100-10*x;
		w=n%10;
		z=(n%100-w)/10;
		k++;		//k��ʾ����
		//p��ʾ�м�������
		if(x>a)
			p++;
		if(y>b)
			p++;
		if(z>c)
			p++;
		if(w>d)
			p++;
		//q��ʾ�м���С��
		if(x<a)
			q++;
		if(y<b)
			q++;
		if(z<c)
			q++;
		if(w<d)
			q++;
		//o��ʾ�м������
		if(x==a)
			o++;
		if(y==b)
			o++;
		if(z==c)
			o++;
		if(w==d)
			o++;
		printf("\n���д��ڵ���%d��,С�ڵ���%d��,��ȵ���%d��\n\n",p,q,o);
	}while(a!=x||b!=y||c!=z||d!=w);
	printf("\n\n\n������%d�δ����ȷ��:%d\n\n\n",k,i);
	printf("����:\n");
	note();
	g=get(k);
	if(k<8)
		printf("�����õ�%dԪ,����ϵ��һʵ!\n\n\n",g);
	else
		printf("�������볬��8��,лл����!\n\n\n");
end:
	flag=end();
	if(flag==1)
		printf("лл����ʹ��!\n\n");
	if(flag==0)
	{
		flag=begin();
		if(flag==1)
		{
			printf("\n�����Ѿ����¿�ʼ!\n\n");
			goto begin;
		}
		else
		{
			printf("\n�����ٴ�����!\n\n");
			goto start;
		}
	}
}



int change(int x)	//�õ���λ��
{
	do
	{
		if(x<0)
			x=0-x;
		x+=20081104;
		x*=19881211;
		x%=10000;
	}while(x<1000||x>=10000);
	return(x);
}


void note()		//��Ϸ����
{
	int i,m;
	printf("��Ϸ����:\n");
	for(i=1,m=100;m>0;i++,m/=2)
	{
		printf("����%d�δ��,���%dԪ\n",i,m);		//��˳������
	}
	printf("����%d���Ժ�,û�н�Ʒ\n",i);			//û��˳������
}

int get(int k)	//����
{
	int i,m;
	for(i=1,m=100;i<k;i++,m/=2);
	return(m);			//û��˳������
}


int end()
{
	int i;
	do
	{
		printf("���Ƿ�Ҫ�˳�?<�˳�:1/����:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

int begin()
{
	int i;
	do
	{
		printf("��Ҫ������Ϸ��?<����:1/����:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}