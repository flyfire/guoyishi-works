#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{	
	void note();		//����һ����Ϸ����
	int get(int k);		//�õ�����ĺ���
	int change(int x);	//�����������ת��
	int end();			//�ж��Ƿ��뿪
	int begin();		//�ж��Ƕ����¿�ʼ
	int i,n,k=0,p,q,g;
	int a,b,c,d;		//������ķֽ�
	int x,y,z,w;		//�û��²����ķֽ�
	int flag;			//�жϿ���
begin:
	printf("===������Ϸ������![��λ��]===\n");
	note();						//�������
	do							//�ж���������Ƿ�����ظ�������
	{
		srand(time(NULL));		//�õ������
		i=change(rand());		//�õ�ת�����������λ��
		a=i/1000;				//a����ǧλ
		b=i/100-10*a;			//b�����λ
		d=i%10;					//d�����λ
		c=(i%100-d)/10;			//c����ʮλ
	}while(a==b||a==c||a==d||b==c||b==d||c==d);
	printf("ϵͳ�Ѿ��õ�һ�������\n");
	do
	{
		p=0;q=0;			//��ͳ������������
		switch(k)				//���ݴ�����ʾ�û���ͬ��Ϣ
		{
		case 0:printf("���������²������:\n");break;
		case 3:printf("����ϸ��������\n");break;
		case 6:printf("���Ͱ�,�н����!\n");break;
		case 9:printf("��ó������,���Ͱ�!\n");break;
		case 12:printf("һ���ܵ�,����!\n");break;
		case 15:printf("��û�еĳ���?�����,����ô����?\n");
			printf("����19881211������ʲô��!\n");break;
		default:printf("\n\n");
		}
start:
		scanf("%d",&n);			//�õ��û����������
		if(n==10101)			//�˳�����
		{
			printf("\n��������һ����������,�˳�����.\n\n");
			goto end;
		}
		if(n==19881211)			//͵������
		{
			printf("\n��������һ��͵������,�����𰸰�:%d\n",i);
			printf("�Ǻ�,�������!\n\n");
			goto start;
		}
		if(n>10000||n<0)		//�ж��û������Ƿ�����
		{
			printf("\n������������,��ȷ���Ǹ���λ��,������������!\n\n");
			goto start;
		}
		x=n/1000;				//x����ǧλ
		y=n/100-10*x;			//y�����λ
		w=n%10;					//w�����λ
		z=(n%100-w)/10;			//z����ʮλ
		if(x==y||x==z||x==w||y==z||y==w||z==w)
		{
			printf("�ѵ�����֪�����������ظ���������?\n");
			printf("������������:\n");
			goto start;

		}

		k++;					//k��ʾ����
		if(a==x)
			p++;
		if(b==y)
			p++;
		if(c==z)
			p++;
		if(d==w)
			p++;
		if(a==y||a==z||a==w)
			q++;
		if(b==x||b==z||b==w)
			q++;
		if(c==x||c==y||c==w)
			q++;
		if(d==x||d==y||d==z)
			q++;
		//��������жϽ��!
		printf("\n������ȫƥ�����%d��,����ȫƥ�����%d��\n\n",p,q);
	}while(a!=x||b!=y||c!=z||d!=w);
	printf("\n������%d�δ����ȷ��:%d\n\n\n",k,i);
	printf("����:\n");
	note();					//�ٴ�������Ϸ����
	g=get(k);				//�ж��Ƿ��н���
	if(k<8)
		printf("\n�����õ�%dԪ,����ϵ:!\nhttp://c-subjects.blogspot.com/\n\n",g);
	else
		printf("\n�������볬��8��,лл����!\n\n\n");
end:
	flag=end();				//�ж��Ƿ��������
	if(flag==1)
		printf("лл����ʹ��!\n\n");
	if(flag==0)
	{
		flag=begin();		//�ж��Ƿ����¿�ʼ
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
	printf("[��Ϸ����]\n");
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


int end()		//�Ƿ��������
{
	int i;
	do
	{
		printf("���Ƿ�Ҫ�˳�?<�˳�:1/����:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

int begin()		//�Ƿ����¿�ʼ
{
	int i;
	do
	{
		printf("��Ҫ������Ϸ��?<����:1/����:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

