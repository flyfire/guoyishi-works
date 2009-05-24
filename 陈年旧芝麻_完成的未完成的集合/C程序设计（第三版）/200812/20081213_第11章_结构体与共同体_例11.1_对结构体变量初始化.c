#include <stdio.h>
void main()
{
	struct student
	{
		long int num;
		char name[20];
		char sex;
		char addr[20];
	}a={10101,"Li Lin",'M',"123 Beijing Road"};
	printf("No.%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);
}