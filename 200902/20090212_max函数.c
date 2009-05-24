#include <stdio.h>

int main()
{
	int max(int, int);
	int i, j;
	scanf("%d %d", &i, &j);
	printf("%d", max(i,j));

	return 0;
}

int max (int x, int y)
{
	return x > y ? x : y;
}
