#include <stdio.h>
#define XX 0
void main()
{
	int x;
	printf("this /*mom*/ ok?\n");
#if XX
	printf("#if = xxxxxxxxxxx\n");
#else
	printf("buwei1已经结束了\n");
#endif

}
