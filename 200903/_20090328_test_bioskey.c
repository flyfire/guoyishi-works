#include <conio.h>
#include <stdio.h>
void main(void)
{
	int i;
	while(kbhit()!=0) {
		printf("input please\n");
		i=getch();
		if(!i){
			i=getch();
			printf("%d",i);
		}
		else
			printf("%c",i);
	}

}
