#include <iostream>

int main()
{
	std::cout << "Enter base and exponent:" << std::endl;
	int base,exponent;
	int result = 1;
	std::cin >> base >> exponent;
	for(int count = 0; count != exponent; ++count)
		result*= base;
	std::cout << base
		<< " raised to the power of "
		<< exponent << ":\t"
		<< result << std::endl;

	return 0;
}