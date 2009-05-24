#include <stdio.h>
char *m[7]={" ","U.S.","U.K.","FRANCE","GER","ITALY","RUSSIAN"};
int main()
{
	int a[7][7],i,j,t,e,x,y;
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			a[i][j]=j;
		for(i=1;i<7;i++)
			a[0][i]=1;
		a[1][1]=a[2][1]=a[3][1]=a[5][1]=0;
		a[1][3]=a[2][3]=a[3][3]=0;
		a[1][4]=a[2][4]=a[3][4]=a[5][4]=a[6][4]=0;
		a[3][5]=0;
		a[1][6]=a[3][6]=a[5][6]=0;
		while(a[0][1]+a[0][2]+a[0][3]+a[0][4]+a[0][5]+a[0][6]>0)
		{
			for(i=1;i<7;i++)
				if(a[0][i])
				{
					for(e=0,j=1;j<7;j++)
						if(a[j][i])
						{
							x=j;y=i;e++;
						}
					if(e==1)
					{
						for(t=1;t<7;t++)
							if(t!=i)
								a[x][t]=0;
							a[0][y]=0;
					}
				}
		}
		for(i=1;i<7;i++)
		{
			printf("%c is coming from ",'A'-1+i);
			for(j=1;j<7;j++)
				if(a[i][j]!=0)
				{
					printf("%s.\n",m[a[i][j]]);
					break;
				}
		}
}