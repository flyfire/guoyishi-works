#include <stdio.h>
void main(void)
{
	int string[5][10]={
		{0,1,2,3,4,5,6,7,8,9},
		{2,4,6,8,9,10,12,14,16,20},
		{1,3,5,7,9,11,13,15,17,19},
		{0,1,2,3,4,14,15,16,17,18},
		{3,6,7,8,9,12,13,14,15,15}
	};
	int i,flag=1;
	int f1=0,f2=0,f3=0,f4=0,f5=0;
	char str[100]; 
	gets(str);
	for(i=0;flag;i++)
	{
		if(str[i]==49)
			f1=1;
		if(str[i]==50)
			f2=1;
		if(str[i]==51)
			f3=1;
		if(str[i]==52)
			f4=1;
		if(str[i]==53)
			f5=1;
		for(i=0;i<10&&f1;)




			//		printf("测试!!!!!当i=%d,str[%d]=%d\n",i,i,str[i]);
			if(str[i]==48)	//遇到"0"就退出
				flag=0;


	}
	//测试!!!    printf("有零出现\n");



}