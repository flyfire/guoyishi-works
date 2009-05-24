#include <iostream>
#include <string>
using namespace std;

template <typename T, std::size_t N>
std::size_t size(T (&arr)[N])
{
	return N;
}

int main()
{
	int a[] = {1, 3, 5, 6};

	cout << size(a) << endl;

	return 0;
}
