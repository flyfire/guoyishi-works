////////////////////////////
// Date: 2009-09-20
// Author: Yishi Guo
// Chapter: 1
// Pages: 19
////////////////////////////
#include <iostream.h>

class CPoint {
public:
	CPoint( int x = 0, int y = 0 ) {
		xPos = x;
		yPos = y;
	}
public:
	void Copy( CPoint one ) {
		*this = one;
	}
	void Print() {
		cout << "Point(" << xPos << ", " << yPos << ")" << endl;
	}
private:
	int xPos, yPos;
};
int main() {
	CPoint pt1(10, 20), pt2(30, 40);
	pt1.Print();  pt1.Copy(pt2);  pt1.Print();

	return 0;
}