#include <iostream>
using namespace std;

class Sales_item {
	friend std::istream& operator>>
		(std::istream&, Sales_item&);
	friend std::ostream& operator<<
		(std::ostream&, const Sales_item&);
public:
	Sales_item& operator+=(const Sales_item&);
};
Sales_item operator+(const Sales_item&, const Sales_item&);

int main()
{
	return 0;
}