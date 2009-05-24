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
	printf("===猜数游戏升级版!===\n");
	note();
	do
	{
		srand(time(NULL));
		i=change(rand());		//得到随机四位数
		a=i/1000;
		b=i/100-10*a;
		d=i%10;
		c=(i%100-d)/10;
	}while(a==b||a==c||a==d||b==c||b==d||c==d);
	printf("系统已经得到一个随机数\n");
	//          printf("\n\n%d\n\n",i);
	do
	{
		p=0;q=0;o=0;
		switch(k)
		{
		case 0:printf("\n请输入您猜测的数字:\n");break;
		default:printf("\n\n");
		}
start:
		scanf("%d",&n);
		if(n==10101)
		{
			printf("\n您输入了一个隐藏命令,退出命令.\n\n");
			goto end;
		}
		if(n==19881211)	//偷看语句
		{
			printf("给你看看答案吧:%d\n",i);
			printf("呵呵,再输入吧!\n\n");
			goto start;
		}
		if(n>10000||n<1000)
		{
			printf("\n您的输入有误,请确保是个四位数,请您重新输入!\n\n");
			goto start;
		}
		x=n/1000;
		y=n/100-10*x;
		w=n%10;
		z=(n%100-w)/10;
		k++;		//k表示次数
		//p表示有几个大于
		if(x>a)
			p++;
		if(y>b)
			p++;
		if(z>c)
			p++;
		if(w>d)
			p++;
		//q表示有几个小于
		if(x<a)
			q++;
		if(y<b)
			q++;
		if(z<c)
			q++;
		if(w<d)
			q++;
		//o表示有几个相等
		if(x==a)
			o++;
		if(y==b)
			o++;
		if(z==c)
			o++;
		if(w==d)
			o++;
		printf("\n其中大于的有%d个,小于的有%d个,相等的有%d个\n\n",p,q,o);
	}while(a!=x||b!=y||c!=z||d!=w);
	printf("\n\n\n您经过%d次答出正确答案:%d\n\n\n",k,i);
	printf("按照:\n");
	note();
	g=get(k);
	if(k<8)
		printf("您将得到%d元,请联系郭一实!\n\n\n",g);
	else
		printf("您的输入超过8次,谢谢参与!\n\n\n");
end:
	flag=end();
	if(flag==1)
		printf("谢谢您的使用!\n\n");
	if(flag==0)
	{
		flag=begin();
		if(flag==1)
		{
			printf("\n程序已经重新开始!\n\n");
			goto begin;
		}
		else
		{
			printf("\n请您再次输入!\n\n");
			goto start;
		}
	}
}



int change(int x)	//得到四位数
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


void note()		//游戏规则
{
	int i,m;
	printf("游戏规则:\n");
	for(i=1,m=100;m>0;i++,m/=2)
	{
		printf("输入%d次答对,获得%d元\n",i,m);		//有顺序的输出
	}
	printf("输入%d次以后,没有奖品\n",i);			//没有顺序的输出
}

int get(int k)	//奖金
{
	int i,m;
	for(i=1,m=100;i<k;i++,m/=2);
	return(m);			//没有顺序的输出
}


int end()
{
	int i;
	do
	{
		printf("您是否要退出?<退出:1/继续:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

int begin()
{
	int i;
	do
	{
		printf("您要重新游戏吗?<重新:1/返回:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}