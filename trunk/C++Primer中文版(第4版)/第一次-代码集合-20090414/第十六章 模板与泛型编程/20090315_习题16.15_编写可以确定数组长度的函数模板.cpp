#include <iostream>
#include <utility>
using namespace std;

template <typename T, size_t N>
size_t size(T (&arr)[N])
{
	return N;
}

int main()
{
	int a[] = {1, 3, 4, 1, 34, 32, 3};

	size(a);

	return 0;
}