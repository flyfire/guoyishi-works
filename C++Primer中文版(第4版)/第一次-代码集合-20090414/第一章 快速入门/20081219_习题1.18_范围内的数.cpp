#include <iostream>

int main()
{
	int i,t,v1,v2;
	std::cout << "Enter two numbers:" << std::endl;
	std::cin >> v1 >> v2;
	if(v1>v2)
	{
		t=v1;
		v1=v2;
		v2=t;
	}
	std::cout << "The number from " << v1 << " to " << v2 << " is " << std::endl;
	for(i=v1;i<=v2;i++)
		std::cout << i << std::endl;
	return 0;
}