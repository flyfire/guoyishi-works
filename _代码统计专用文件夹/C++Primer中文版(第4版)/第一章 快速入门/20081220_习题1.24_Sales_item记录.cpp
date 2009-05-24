
#include <iostream>
#include "Sales_item.h"

int main()
{
	Sales_item trans1,trans2;
	int amount;

	std::cout << "Enter transactions:" << std::endl;
	std::cin >> trans1;
	amount=1;

	while(std::cin >> trans2)
		if(trans1.same_isbn(trans2))
			++amount;
		else
		{
			std::cout << "Transaction amount of previous ISBN:"
				<<amount << std::endl;
			trans1=trans2;
			amount=1;
		}
		std::cout << "Transactiong amount of the last ISBN:"
			<< amount << std::endl;
		return 0;
}