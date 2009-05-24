#include <stdio.h>
#include <string.h>

void main()
{
	struct student
	{
		long num;
		char name[20];
		char sex;
		float score;
	};
	struct student stu_1;
	struct student *p;
	p=&stu_1;	//Give the stu_1's address to  *p  
	stu_1.num=89101;
	strcpy(stu_1.name,"Li Lin");  //NOTICE!
	stu_1.sex='M';
	stu_1.score=89.5;
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%f\n",stu_1.num,stu_1.name,stu_1.sex,stu_1.score);
	printf("No.:%ld\nname:%s\nsex:%c\nscore:%f\n",(*p).num,(*p).name,(*p).sex,(*p).score);
}