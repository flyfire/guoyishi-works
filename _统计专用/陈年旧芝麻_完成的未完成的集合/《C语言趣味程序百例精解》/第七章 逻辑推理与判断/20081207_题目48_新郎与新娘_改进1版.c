#include <stdio.h>
int main()
{
	char i,j,k;
	for(i='x';i<='z';i++)
		for(j='x';j<='z';j++)
			for(k='x';k<='z';k++)
			{
				if(i!='x'&&k!='x'&&k!='z'&&i!=j&&j!=k&&i!=k)
					printf("a--%c\nb--%c\nc--%c\n",i,j,k);
			}
}