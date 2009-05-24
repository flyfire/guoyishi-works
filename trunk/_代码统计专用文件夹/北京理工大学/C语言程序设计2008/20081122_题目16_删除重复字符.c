#include <stdio.h>
void main(void)
{
	char str[100],str2[100];
	int i,k=0,j,t,flag=1;
	for(i=0;i<100;i++,k++)
	{str[i]=getchar();
		if(str[i]=='\n')
			break;
	}
	for(i=0,j=0;i<=k;i++,flag=1)
	{for(t=0;t<j;t++)
		{if(str[i]==str2[t])
				flag=0;
		}
		if(flag)
		{str2[j]=str[i];
			j++;
		}
	}
	for(i=0;i<j;i++)
		printf("%c",str2[i]);
}
