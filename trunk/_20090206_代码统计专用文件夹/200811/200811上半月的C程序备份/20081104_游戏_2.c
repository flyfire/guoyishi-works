#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int change(int x);
	int i,n,k=0,p,q,o;
	int a,b,c,d;
	int x,y,z,w;
	printf("===������Ϸ������!===\n");
	do
	{
		srand(time(NULL));
		i=change(rand());		//�õ������λ��
		printf("i=%d\n",i);
		a=i/1000;
		b=i/100-10*a;
		d=i%10;
		c=(i%100-d)/10;
		printf("ǧλ��%d��λ��%dʮλ��%d��λ��%d\n",a,b,c,d);
	}while(a==b||a==c||a==d||b==c||b==d||c==d);
	
	do
	{
		p=0;q=0;o=0;
		switch(k)
		{
		case 0:printf("\n��ӭ����ʹ��,���������²������:\n");break;
		default:printf("\n\n");
		}
		scanf("%d",&n);
		x=n/1000;
		y=n/100-10*x;
		w=n%10;
		z=(n%100-w)/10;
		k++;		//k��ʾ����
		printf("ǧλ��%d��λ��%dʮλ��%d��λ��%d\n\n",x,y,z,w);
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

}



int change(int x)
{
	do
	{
		if(x<0)
			x=0-x;
		x+=20081104;
		x*=19881211;
		x%=10000;
	}while(x<1||x>100000);
	return(x);
}


