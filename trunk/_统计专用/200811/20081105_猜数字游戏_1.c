#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{	
	void note();		//产生一个游戏规则
	int get(int k);		//得到奖金的函数
	int change(int x);	//对随机数进行转换
	int end();			//判断是否离开
	int begin();		//判断是都重新开始
	int i,n,k=0,p,q,g;
	int a,b,c,d;		//随机数的分解
	int x,y,z,w;		//用户猜测数的分解
	int flag;			//判断开关
begin:
	printf("===猜数游戏升级版![四位数]===\n");
	note();						//输出公告
	do							//判断随机数中是否存在重复的数字
	{
		srand(time(NULL));		//得到随机数
		i=change(rand());		//得到转换过的随机四位数
		a=i/1000;				//a代表千位
		b=i/100-10*a;			//b代表百位
		d=i%10;					//d代表个位
		c=(i%100-d)/10;			//c代表十位
	}while(a==b||a==c||a==d||b==c||b==d||c==d);
	printf("系统已经得到一个随机数\n");
	do
	{
		p=0;q=0;			//对统计数进行清零
		switch(k)				//根据次数提示用户不同信息
		{
		case 0:printf("请输入您猜测的数字:\n");break;
		case 3:printf("再仔细分析分析\n");break;
		case 6:printf("加油啊,有奖金的!\n");break;
		case 9:printf("快得出结果了,加油啊!\n");break;
		case 12:printf("一定能的,快了!\n");break;
		case 15:printf("还没有的出来?不会吧,有那么难吗?\n");
			printf("输入19881211看看有什么吧!\n");break;
		default:printf("\n\n");
		}
start:
		scanf("%d",&n);			//得到用户输入的数字
		if(n==10101)			//退出命令
		{
			printf("\n您输入了一个隐藏命令,退出命令.\n\n");
			goto end;
		}
		if(n==19881211)			//偷看命令
		{
			printf("\n您输入了一个偷看命令,看看答案吧:%d\n",i);
			printf("呵呵,再输入吧!\n\n");
			goto start;
		}
		if(n>10000||n<0)		//判断用户输入是否有误
		{
			printf("\n您的输入有误,请确保是个四位数,请您重新输入!\n\n");
			goto start;
		}
		x=n/1000;				//x代表千位
		y=n/100-10*x;			//y代表百位
		w=n%10;					//w代表个位
		z=(n%100-w)/10;			//z代表十位
		if(x==y||x==z||x==w||y==z||y==w||z==w)
		{
			printf("难道您不知道不可以有重复的数字吗?\n");
			printf("请您重新输入:\n");
			goto start;

		}

		k++;					//k表示次数
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
		//输出数字判断结果!
		printf("\n其中完全匹配的有%d个,不完全匹配的有%d个\n\n",p,q);
	}while(a!=x||b!=y||c!=z||d!=w);
	printf("\n您经过%d次答出正确答案:%d\n\n\n",k,i);
	printf("按照:\n");
	note();					//再次宣读游戏规则
	g=get(k);				//判断是否还有奖金
	if(k<8)
		printf("\n您将得到%d元,请联系:!\nhttp://c-subjects.blogspot.com/\n\n",g);
	else
		printf("\n您的输入超过8次,谢谢参与!\n\n\n");
end:
	flag=end();				//判断是否结束程序
	if(flag==1)
		printf("谢谢您的使用!\n\n");
	if(flag==0)
	{
		flag=begin();		//判断是否重新开始
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
	printf("[游戏规则]\n");
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


int end()		//是否结束程序
{
	int i;
	do
	{
		printf("您是否要退出?<退出:1/继续:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

int begin()		//是否重新开始
{
	int i;
	do
	{
		printf("您要重新游戏吗?<重新:1/返回:0>\n\n");
		scanf("%d",&i);
	}while(i!=1&&i!=0);
	return i;
}

