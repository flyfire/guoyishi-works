#include <iostream>
#include <string>
using namespace std;

class Base {
public:
	Base(): mem(0) {}
	int get_none() { return mem; }
	
protected:
	int mem;
};

class Derived : public Base {
public:
	Derived(int i = 0): mem(i) {}
	int get_mem() { return Base::mem; }
protected:
	int mem;
};

int main()
{
	Derived d(12);
	cout << d.get_mem() << endl;
	cout << d.get_none << endl;
	return 0;
}