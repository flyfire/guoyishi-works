#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	Employee(): name("NoName")
	{
		setId();
	}

	Employee(string nm): name(nm)
	{
		setId();
	}

	Employee(const Employee& other):name(other.name)
	{
		setId();
	}

	Employee& operator = (const Employee& rhe)
	{
		name = rhe.name;
		return *this;
	}
private:
	std::string name;
	std::string id;
	static int counter;

	void setId()
	{
		id = "Empl-";
		if (counter < 10)
			id += "000";
		else if (counter < 100)
			id += "00";
		else if (counter <1000)
			id += "0";
		else {
			std::cerr << "no valid employee id!" << std::endl;
		}

		char buffer[5];
		_itoa(counter, buffer, 10);
		id += buffer;
		++counter;
	}
};

	int Employee::counter = 1;

int main()
{
	return 0;
}