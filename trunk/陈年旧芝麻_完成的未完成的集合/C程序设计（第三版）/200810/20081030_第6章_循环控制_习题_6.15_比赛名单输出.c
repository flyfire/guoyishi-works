#include <stdio.h>
void main()
{
	char i,j,m,n;
	printf("===�������������===\n");
	printf("���������ı�������Ϊ��\n");
start:
	for(i='A';i<='C';i++)
	{
		for(j='X';j<='Z';j++)
		{
			if(i=='A'&&j=='X')
				continue;
			else if(i=='C'&&(j=='X'||j=='Z'))
				continue;
			printf("%c��%c����\n",i,j);
			break;
			n++;
		}
		m++;

	}
	goto start;

}

