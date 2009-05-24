#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

void main()
{
	char *p, buffer[1024];
	int number[256], i, j, n;

	printf("Input: ");
	fgets(buffer, 1024, stdin);

	n = 0;
	p = buffer;
	do
	{
		p += sscanf(p, "%d", number + n) + 1;
	}
	while (number[n++] != 0);
	n--;

	for (i = 1; i < 64; i++)
		{
		for (j = 0; j < n; j++)
			{
			int base = (int)pow(2, number[j]);
			if (i % base < base / 2)
			{
			break;
			}
			}
		if (j == n)
		{
		printf("Res: %d\n", i);
		break;
		}
		}

	getch();
}