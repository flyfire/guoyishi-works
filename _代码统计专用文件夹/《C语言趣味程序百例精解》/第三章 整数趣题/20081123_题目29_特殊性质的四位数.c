#include <stdio.h>
void main(void)
{
	int ab,cd;
	for(ab=10;ab<=99;ab++)
		for(cd=0;cd<=99;cd++)
			if((ab+cd)*(ab+cd)==(ab*100+cd))
				printf("abcd=%d\n",ab*100+cd);
}