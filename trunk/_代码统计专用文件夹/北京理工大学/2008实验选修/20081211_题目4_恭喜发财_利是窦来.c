#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct sui
{
	char name[14];
	int moneyGive;
	int moneyLast;
}money[10];
int main()
{
	int n,i,j,k,flag;
	char name[14];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",money[i].name);
		money[i].moneyGive=0;		//clear "0"
		money[i].moneyLast=0;		//clear "0"
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",name);
		for(j=0,flag=1;j<n&&flag;j++)
		{
			if(strcmp(money[j].name,name)==0)
			{
				int number,giveMoney;
				scanf("%d %d",&money[j].moneyGive,&number);
				if(number)
				{
					money[j].moneyLast+=money[j].moneyGive%number;
					giveMoney=money[j].moneyGive/number;
					for(k=0;k<number;k++)
					{
						int t;
						scanf("%s",name);
						for(t=0;t<n;t++)
							if(strcmp(money[t].name,name)==0)
							{
								money[t].moneyLast+=giveMoney;
								break;
							}
					}
				}
				else
					money[j].moneyLast+=money[j].moneyGive;
				flag=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",money[i].name,money[i].moneyLast-money[i].moneyGive);
	}
}//20081212 20:34 Saved
