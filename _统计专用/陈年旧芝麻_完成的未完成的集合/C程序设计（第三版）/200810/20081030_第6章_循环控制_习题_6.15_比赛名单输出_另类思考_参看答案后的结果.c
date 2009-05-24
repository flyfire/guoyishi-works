#include <stdio.h>
void main()
{
	char i,j,k;
	printf("===比赛名单的输出===\n");
	printf("程序计算出的比赛名单为：\n");
	for(i='X';i<='Z';i++)
		for(j='X';j<='Z';j++)
			if(i!=j)
				for(k='X';k<='Z';k++)
					if(i!=j&&j!=k&&i!=k)
						if(i!='X'&&k!='X'&&k!='Z')
							printf("A--%c\tB--%c\tC--%c\n",i,j,k);
	printf("\n\n\n谢谢您的使用！\n\n\n");

}

