#include <stdio.h>

int main()
{
	int str[3][3];
	int sum=0,average=0,i,j,k;
	for(i=1;i<=9;i++)
		sum+=i;
	average=sum/3;
	printf("sum=%d,average=%d\n",sum,average);
	for(i=0,k=7;i<=2;i++,k++)
		str[i][0]=k;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			for(k=1;k<=3;k++)
			{
				if(i!=j&&j!=k&&i!=k
					&&average-i-str[0][0]!=average-j-str[1][0]
					&&average-k-str[2][0]!=average-j-str[1][0]
					&&average-i-str[0][0]!=average-k-str[2][0])
					{
						
						str[0][1]=i;str[0][2]=average-i-str[0][0];
						str[1][1]=j;str[1][2]=average-j-str[1][0];
						str[2][1]=k;str[2][2]=average-k-str[2][0];
					}
			}
	for(i=0;i<=2;i++)
		for(j=0;j<=2;j++)
		{
				printf("str[%d][%d]=%d\n",i,j,str[i][j]);
				if(str[i][j]==1)
					k=i;
		}
	switch(k)
	{
	case 0:printf("Zhang\n");break;
	case 1:printf("Wang\n");break;
	case 2:printf("Li\n");break;
	}
}