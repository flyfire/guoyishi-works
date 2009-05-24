#include <iostream>

int main()
{
	int value,i=0;
	std::cout << "Please enter:";
	while(std::cin >> value)
		if(value<0)
			++i;
	std::cout << "Amount of all negative value read is "
		      << i << std::endl;
	return 0;
}