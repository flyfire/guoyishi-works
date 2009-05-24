#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

template <typename T1, typename T2>
T1& print(T1 &s, T2 val)
{
	s << val;
	return s;
}

int main()
{
	double dval = 0.88;
	float fval = -12.2321f;
	string oristr = "this is a test", desstr;
	ostringstream oss(desstr);
	ofstream outFile("20090315_test_result.txt");	//if not exist then creat a same name file

	print(cout, -5) << endl;
	print(cout, dval) << endl;
	print(cout, fval) << endl;
	print(cout, oristr) << endl;

	print(outFile, - 423) << endl;
	print(outFile, dval) << endl;
	print(outFile, fval) << endl;
	print(outFile,oristr) << endl;
	outFile.close();

	print(oss, -42) << endl;
	print(oss, dval) << endl;
	print(oss, fval) << endl;
	print(oss, oristr) << endl;

	cout << oss.str() << endl;

	return 0;
}