#include <stdio.h>
void main()
{
	int i,m,n,t=0; /*i用来输出运算后的结果，m、n用来判断转换的类型，t用来判断是否是第一次输入*/
	printf("===常见进制间的转换程序===\n");
	printf("请您选择 十进制、八进制、十六进制，程序将为您进行转换！\n");
	printf("[格式为：XX XX	例如：16 10 ]	[输入：123 321程序将退出！]\n");/*用“123 321”来结束程序*/
start:
	if(t==0) /*由于t的值初始状态被赋值为0，因此当第一次运行程序时，提示为“请您输入：”*/
	printf("请您输入：\n");
	else
		printf("\n请您重新输入：");
again:
	scanf("%d %d",&m,&n); /*m、n判断进制转换类型*/
	t++; /*使初始状态的t的值改变，从而当再次输入时，程序提示另一个“请您重新输入：”*/
	if(m==123&&n==321) /*用这个if语句来执行退出程序命令*/
		goto end;
	if((m==8||m==10||m==16)&&(n==8||n==10||n==16)&&n!=m) /*确保输入的正确性*/
	{	printf("您需要进行的是：%d进制对%d进制的转换\n请输入需要转换的%d进制数字：",m,n,m);
	switch(m)/*按照输入的类型选择录入数据类型*/
	{
	case 8:scanf("%o",&i);break;
	case 10:scanf("%d",&i);break;
	case 16:scanf("%x",&i);break;
	}
	switch(n)/*按照输入的类型选择输出数据类型*/
	{
	case 8: printf("\n从%d进制转换到%d进制，其结果为：%o\n",m,n,i);break;
	case 10: printf("\n从%d进制转换到%d进制，其结果为：%d\n",m,n,i);break;
	case 16: printf("\n从%d进制转换到%d进制，其结果为：%x\n",m,n,i);break;
	}
	goto start; /*执行重新输入命令，直到用户选择退出*/
	}
	else /*针对输入的类型错误提示用户*/
	{
		printf("您的输入有误，请重新输入：\n");
		goto again;
	}
end: /*退出*/
	printf("\n\n\n谢谢您的使用！\n\n\n");
}
