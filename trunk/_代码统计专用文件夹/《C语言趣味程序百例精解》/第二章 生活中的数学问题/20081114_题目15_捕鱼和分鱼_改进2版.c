#include <stdio.h>
void main(void)
{
	int i,j,d,flag=1;
	for(j=1;flag;j++)
	{
		d=5*j+1;
		printf("����!���ڵı���:%d\n",j);
		for(i=1;i<5;i++)
			if(d%4==0)
			{
				d=5*d/4+1;
				printf("%d\n",d);
			}
			else
				flag=0;
		if(flag)
			break;
		else
			flag=1;
	}
	printf("�����Ϊ:%d",d);
}