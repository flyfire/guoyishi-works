#include <iostream.h>

class CDrawArray
{
public:
	void DoDraw( int num );
};
void CDrawArray::DoDraw( int num ) {
	for ( int i = 0; i < num; i++ ) {
		for ( int j = 0; j <= i; j++ ) {
			cout << '*';
		}
		cout << '\n';
	}
}

int main() {
	int num = 5;
	CDrawArray myDraw;
	myDraw.DoDraw( num );
	
	return 0;
}