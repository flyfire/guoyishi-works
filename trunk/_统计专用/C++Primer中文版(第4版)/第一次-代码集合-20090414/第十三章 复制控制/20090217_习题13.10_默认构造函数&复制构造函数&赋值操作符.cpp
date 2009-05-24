#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	Employee():name("NoName"), id(counter)
	{
		++counter;
	}

	Employee(std::string nm): name(nm), id(counter)
	{
		++counter;
	}

	Employee(const Employee& other):name(other.name), id(counter)
	{
		++counter;
	}

	Employee& operator = (const Employee& rhe)
	{
		name = rhe.name;
		return *this;
	}
private:
	std::string name;
	int id;
	static int counter;
};	//THERE IS ';'

int main()
{
	return 0;
}