#include <stdio.h>
void main(void)
{
	int i,j,k,k1,k2,flag=1;
	char str[50],str2[50],str3[100];
	for(i=0;;i++)
	{
		str[i]=getchar();
		if(str[i]=='\n'||i>=50)
			break;
	}
	for(j=0;;j++)
	{
		str2[j]=getchar();
		if(str2[j]=='\n'||j>=50)
			break;
	}
	for(k=0,k1=k2=0;k<=i+j;k++)
	{
		if(k1>i)
		{
			str3[k]=str2[k2];
			k2++;
			flag=0;
		}
		if(k2>j)
		{
			str3[k]=str[k1];
			k1++;
			flag=0;
		}
		if(str[k1]<str2[k2]&&flag)
		{
			str3[k]=str[k1];
			k1++;
		}
		else if(str[k1]>=str[2]&&flag)
		{
			str3[k]=str2[k2];
			k2++;
		}
	}
	for(i=0;i<k;i++)
		printf("%c",str3[i]);
}