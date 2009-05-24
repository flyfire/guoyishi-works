#include <stdio.h>
void main()
{
	char i,j,m,n;
	printf("===比赛名单的输出===\n");
	printf("程序计算出的比赛名单为：\n");
start:
	for(i='A';i<='C';i++)
	{
		for(j='X';j<='Z';j++)
		{
			if(i=='A'&&j=='X')
				continue;
			else if(i=='C'&&(j=='X'||j=='Z'))
				continue;
			printf("%c和%c比赛\n",i,j);
			break;
			n++;
		}
		m++;

	}
	goto start;

}

