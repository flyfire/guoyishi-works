#include <iostream>
#include <string>
using namespace std;

int main()
{
	string numerics("0123456789");
	string name("hao123");

	string::size_type pos1 = name.find(numerics);

	string::size_type pos2 = name.rfind(numerics);

	string::size_type pos3 = name.find_first_of(numerics);

	string::size_type pos4 = name.find_last_of(numerics);

	string::size_type pos5 = name.find_first_not_of(numerics);

	string::size_type pos6 = name.find_last_not_of(numerics);

	cout << pos1 << "\t" << pos2 << "\t" << pos3 << "\t"
		<< pos4 << "\t" << pos5 << "\t" << pos6 << "\t"
		<< endl;

	cout << name[pos1] << "\t" << name[pos2] << "\t" << name[pos3] << "\t"
		<< name[pos4] << "\t" << name[pos5] << "\t" << name[pos6] << "\t"
		<< endl;

	return 0;
}
