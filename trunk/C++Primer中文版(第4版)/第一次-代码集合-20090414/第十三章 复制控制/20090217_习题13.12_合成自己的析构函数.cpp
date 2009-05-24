#include <iostream>
#include <string>
using namespace std;

struct NoName {
	NoName(): pstring(new std::string), i(0), d(0) { }
	~NoName()
	{
		delete pstring;
	}
private:
	std::string *pstring;
	int i;
	double d;
};

int main()
{
	return 0;
}