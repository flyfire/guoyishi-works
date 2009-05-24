#include <iostream>
#include <vector>
using namespace std;

struct Exmpl {
	Exmpl() { cout << "Exmpl()" << endl; }

	Exmpl(const Exmpl&)
	{
		cout << "Exmpl(const Exmpl&)" << endl;
	}

	Exmpl& operator = (const Exmpl &rhe)
	{
		cout << "Exmpl& operator = (const Exmpl &rhe)" << endl;
		return *this;
	}
	~Exmpl()
	{
		cout << "~Exmpl()" << endl;
	}
};

void fun1(Exmpl obj)
{
}

void fun2(Exmpl obj)
{
}

Exmpl fun3()
{
	Exmpl obj;

	return obj;
}

int main()
{
	cout << "#1:\tExmpl eobj;" << endl;
	Exmpl eobj;

	cout << "#2:\tfun1(eobj);" << endl;
	fun1(eobj);

	cout << "#3:\tfun2(eobj);" << endl;
	fun2(eobj);

	cout << "#4:\teobj = fun3();" << endl;
	eobj = fun3();

	cout << "#5:\tExmpl *p = new Exmpl;" << endl;
	Exmpl *p = new Exmpl;

	cout << "#6:\tvector<Exmpl> evec(3);" << endl;
	vector<Exmpl> evec(3);

	cout << "#7:\tdelete p;" << endl;
	delete p;

	return 0;
}