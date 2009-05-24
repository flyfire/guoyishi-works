#include <iostream>

int main()
{
	int base,exponent;
	int result = 1;

	std::cout << "Enter base and exponent:" << std::endl;
	std::cin >> base >> exponent;

	if(exponent<0)
	{
		std::cout << "Exponent can't be smaller than 0" << std::endl;
		return -1;
	}

	if(exponent > 0)
		for(int count = 0; count != exponent; ++count)
			result*= base;

	std::cout << base
		<< " raised to the power of "
		<< exponent << ":\t"
		<< result << std::endl;

	return 0;
}