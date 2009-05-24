#include <iostream>
#include <typeinfo>
using namespace std;

class A { };
class B: public A { };
class C: public B { };

int main()
{
	cout << typeid(123).name() << endl;
	cout << typeid(1.23).name() << endl;
	cout << typeid("string as it is.").name() << endl;
	cout << typeid(1.32f).name() << endl;
	cout << typeid('c').name() << endl;

	A *pa = new C;
	cout << typeid(pa).name() << endl;

	C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;

	B *px = new B;
	ra = *px;
	cout << typeid(ra).name() << endl;

	return 0;
}