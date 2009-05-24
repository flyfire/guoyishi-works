#include <stdio.h>
void main()
{
	int i,m,n;
	printf("此程序将进行进制间的转换，请您根据提示输入！\n");
	printf("1>	10进制转换为16进制\n");
	printf("2>	10进制转换为 8进制\n");
	printf("3>	 8进制转换为10进制\n");
	printf("4>	退出选择程序！\n"); 
	switch(getchar())
	{
	case 1: m=10;n=16; break;/*???????????????????????????????难道WSWITCH内部不能进行赋值操作码？*/
	case 2: m=10;n=8; break;
	case 3: m=8;n=10; break;
	case 4: goto end; break;
	}
	printf("请您输入一个%d进制的数字，程序将为您转换为%d进制\n",m,n);
	scanf("%d",&i);
	printf("您输入的为：%d，程序为您转换成%d进制为：%o",i,n,i);
end:
	printf("谢谢使用！\n");
}

