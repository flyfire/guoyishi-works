#include <stdio.h>
void main()
{
	char i,j,k;
	printf("===�������������===\n");
	printf("���������ı�������Ϊ��\n");
	for(i='X';i<='Z';i++)
		for(j='X';j<='Z';j++)
			if(i!=j)
				for(k='X';k<='Z';k++)
					if(i!=j&&j!=k&&i!=k)
						if(i!='X'&&k!='X'&&k!='Z')
							printf("A--%c\tB--%c\tC--%c\n",i,j,k);
	printf("\n\n\nлл����ʹ�ã�\n\n\n");

}

