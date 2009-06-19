#include <iostream>
using namespace std;

bool testArray(int array[])
{
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (array[i] == array[j]) {
				return false;
			}
		}
	}
	return true;
}

bool testOK(int array[])
{
	long sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += array[i];
		if (sum % (i + 1)) {
			return false;
		}
		sum *= 10;
	}

	return true;
}

int main()
{
	for (int a = 1; a < 10; a += 2) {
		for (int b = 2; b < 10; b += 2) {
			for (int c = 1; c < 10; c += 2) {
				for (int d = 2; d < 10; d += 2) {
					int e = 5;
					for (int f = 2; f < 10; f += 2) {
						for (int g = 1; g < 10; g += 2) {
							for (int h = 2; h < 10; h += 2) {
								for (int i = 1; i < 10; i += 2) {
									int array[9] = {0};

									array[0] = a;
									array[1] = b;
									array[2] = c;
									array[3] = d;
									array[4] = e;
									array[5] = f;
									array[6] = g;
									array[7] = h;
									array[8] = i;

									if (testArray(array) && testOK(array)) {
										cout << "Result:: ";
										for (int index = 0; index < 9; index++) {
											cout << array[index];
										}
										cout << endl;
									}
									else {
										/*
										for (int index = 0; index < 9; index++) {
											cout << array[index];
										}
										cout << endl;
										*/
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}