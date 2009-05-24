#include <iostream>

int main()
{
	int value,i=0;
	std::cout << "Please enter:";
	while((std::cin >> value)!=EOF)
		if(value<0)
			i++;
	std::cout << "There are " << i
		      << "numbers" << std::endl;
	return 0;
}