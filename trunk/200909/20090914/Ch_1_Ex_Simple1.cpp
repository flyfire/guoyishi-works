#include <iostream.h>

void DoDraw(int num);
int main() {
	int num = 5;
	DoDraw(num);
	return 0;
}

void DoDraw( int num ) {
	for ( int i = 0; i < num; i++ ) {
		for ( int j = 0; j <= i; j++ ) {
			cout << '*';
		}
		cout << '\n';
	}
}
