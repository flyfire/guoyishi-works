#include <stdio.h>
int main()
{
	int i,j,str[4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(i==j)
				str[j]=1;
			else
				str[j]=0;
		if(str[1]+str[3]==1&&str[1]+str[2]==1&&str[0]+str[1]==1)
			for(j=0;j<4;j++)
				if(str[j])
					printf("The thief is %c.\n",j+'A');
	}
}