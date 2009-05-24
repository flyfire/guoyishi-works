#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;

	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	for (size_t ix = 0; ix !=11; ++ix) {
		ivec.push_back(ix);
		cout << "ivec: size: " << ivec.size()
			<< " capacity: " << ivec.capacity() << endl;
	}

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.reserve(100);
	
	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< " capacity: " << ivec.capacity() << endl;

	ivec.push_back(0);

	cout << "ivec: size: " << ivec.size()
		<< " capcacity: " << ivec.capacity() << endl;

	return 0;
}