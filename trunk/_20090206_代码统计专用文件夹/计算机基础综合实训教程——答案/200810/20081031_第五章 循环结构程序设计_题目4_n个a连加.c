#include <stdio.h>
#include <math.h>
void main()
{
	int i,a,n,k=0,t=0;//k表示第n项的值。t表示第n项没有乘上a之前的值，例如：1111111
	long sn=0;  //定义最后结果为长整形
	printf("===n个a的连加运算===\n");
	printf("程序将进行Sn=a+aa+aaa+...+aa...aa的运算，请您输入a和n\n");
	scanf("%d%d",&a,&n); 
	printf("计算后的结果是：\n");
	for(i=0;i<n;i++)
	{
		t=t+pow(10,i);  
		k=t*a;
		sn=sn+k;
		printf("%ld",k);
		if(i<n-1)   //判断是不是最后一项的输出,如果不是输出"+"如果是的话输出"="
			printf("+");
		else
			printf("=");
	}
	printf("%ld\n\n",sn);        //输出最后的结果
	printf("谢谢您的使用！\n");
}

