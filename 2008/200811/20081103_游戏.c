#include <stdio.h>
void main()
{
	int a,b,c,d;
	int x,y,z,w;
	int i=0,j=0;
	int t=0,m=0;		//t来表示是否是第一次玩
	printf("请您随机输入四个数字:\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a+=23132;
	b+=43415;
	c+=23213;
	d+=31474;
	a%=10;
	b%=10;
	c%=10;
	d%=10;
start:
	if(t==0)
		printf("经过程序运算,已经随机得到一个四位数,请您猜!\n\n");
	else
		printf("您已经尝试了%d次,请不要放弃,再接再厉,重新输入,加油!\n\n",m);
	scanf("%d%d%d%d",&x,&y,&z,&w);
	if(a==x&&b==y&&c==z&&d==w)
	{
		printf("\n\n恭喜您猜对了!!你太牛B了!!\n\n");
		printf("正确结果是:%d%d%d%d",a,b,c,d);
		goto end;
	}
	i=0;
	j=0;
	if(a==x)
		i++;
	if(b==y)
		i++;
	if(c==z)
		i++;
	if(d==w)
		i++;
	if(a==x||a==y||a==z||a==w)
		j++;
	if(b==x||b==y||b==z||b==w)
		j++;	
	if(c==x||c==y||c==z||c==w)
		j++;
	if(d==x||d==y||d==z||d==w)
		j++;
	t++;
	m++;
	printf("您输入的数字中一样的有%d个,数字顺序完全正确的有%d个\n\n",j,i);
	goto start;
end:
	printf("再见!");

	
}