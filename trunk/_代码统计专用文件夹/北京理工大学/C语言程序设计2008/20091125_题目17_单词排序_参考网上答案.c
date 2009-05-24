#include <stdio.h>
#include <string.h>
#define N 20
int main()
{
	char str[5][N];
	int i,j;
	for(i=0;i<5;i++)
		scanf("%s",&str[i]);
	for(i=0;i<4;i++)
		for(j=i;j<5;j++)
			if(strcmp(str[i],str[j])<0)
			{
				char change[N];
				strcpy(change,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],change);
			}
	for(i=0;i<5;i++)
		printf("%s\n",str[i]);
	return 0;
}