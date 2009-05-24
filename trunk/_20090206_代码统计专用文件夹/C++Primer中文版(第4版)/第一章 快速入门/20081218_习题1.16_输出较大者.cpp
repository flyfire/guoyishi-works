#include <iostream>

int main()
{
	std::cout << "Enter two numbers:";
	int v1,v2;
	std::cin >> v1 >> v2 ;
	int bigger;
	if(v1>=v2)
		bigger=v1;
	else
		bigger=v2;
	std::cout << "The bigger number of " << v1
		      <<" and " << v2 << " is "
			  << bigger <<std::endl;

	return 0;
}