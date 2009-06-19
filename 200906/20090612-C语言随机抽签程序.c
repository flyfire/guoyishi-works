//20090612
#include <stdio.h>
#include <math.h>

//Print line
void printLine(int n)
{
	int i = 0;
	while (i < n) {
		printf("==== ");
		i++;
	}
	printf("\n");
}

//Main function
int main()
{
	int selectNums[256] = {0};
	int totalNum;
	int count = 0;

	int flag = 1;

	printLine(3);

	printf("Enter your class total number of students:");
	scanf("%d", &totalNum);
	printLine(3);
	printf("Generator begin!!!\n");

	//Get the "carriage return"
	getchar();
	while (flag) {
		printf("Enter next:");
		getchar();
	}



	printf("Hello World!\n");
}