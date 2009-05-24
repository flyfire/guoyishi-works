#include <stdio.h>
void main()
{
	int up,down,high;
	float sq;
	printf("Please Type <up down high> !\n");
	scanf("%d %d %d",&up,&down,&high);
	sq=(up+down)*high/2;
	printf("The SQ=%10.0f\n",sq);
}