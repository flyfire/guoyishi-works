#include <stdio.h>
void main()
{
	char *str1,*str2;
	printf("chinaJapanese\n");
	printf("%d\n\n",sizeof("abc"));
	str1="abcde";
	str2="abcde";
	if(str1==str2)
		printf("str1==str2\n\n\a""\x12 34\n","123\n","456\n");
	else
		printf("str1!=str2\n");
//	str1[0]='1';		//unwrite
//	if(*str1=='1')
//		printf("Strings writable\n");
//	else
//		printf("Strings are not writable\n");

	printf("ak%s\n""123\n",str1);

}