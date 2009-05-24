#include <stdio.h>
void main(void)
{
	int a,b,c,d;
	int str[4][20];
	int string[20];
	int k,i,j;
	for(k=0,a=0,b=0,c=0,d=0;k<20;k++)
	{
		scanf("%d",&string[k]);
		if(string[k]>=0&&string[k]<=59)
		{
			str[0][a]=string[k];
			a++;
		}
		if(string[k]>=60&&string[k]<=69)
		{
			str[1][b]=string[k];
			b++;
		}
		if(string[k]>=70&&string[k]<=79)
		{
			str[2][c]=string[k];
			c++;
		}
		if(string[k]>=80&&string[k]<=100)
		{
			str[3][d]=string[k];
			d++;
		}
	}
	for(i=0;i<4;i++)
	{
		printf("the %d line():\n",i+1);
		for(j=0;;j++)
		{
			if(i==0&&j==a)
				break;
			if(i==1&&j==b)
				break;
			if(i==2&&j==c)
				break;
			if(i==3&&j==d)
				break;

			printf("  %d",str[i][j]);
		}
		printf("\n");
	}
}