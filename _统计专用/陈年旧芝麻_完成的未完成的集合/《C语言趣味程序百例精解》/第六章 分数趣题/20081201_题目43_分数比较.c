#include <stdio.h>
int main()
{
	char compare(int,int,int,int);
	int a1,a2,b1,b2;
	char sign;
	scanf("%d/%d,%d/%d",&a1,&a2,&b1,&b2);
	sign=compare(a1,a2,b1,b2);
	printf("%d/%d%c%d/%d\n",a1,a2,sign,b1,b2);
}
char compare(int a1,int a2,int b1,int b2)
{
	if((float)a1/a2>(float)b1/b2)
		return ('>');
	else if((float)a1/a2==(float)b1/b2)
		return ('=');
	else
		return ('<');
}