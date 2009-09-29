//////////////////////////////////////
// Date:         2009-09-20
// Author:       Yishi Guo
// Chapter:      1
// Pages:        25
// Exercises:    Ex_ClassDerived
//////////////////////////////////////
#include <iostream.h>
class CPoint {
public:
	CPoint( int x = 0, int y = 0 ) {
		xPos = x;  yPos = y;
		cout << "CPoint Constructor" << endl;
	}
	void ShowPos( bool isEnd = false ) {
		cout << "pos(" << xPos << ", " << yPos << ")";
		if (isEnd) cout << endl;
	}
private:
	int xPos, yPos;
};

class CRect {
public:
	CRect( int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0 )
		: ptLT(x1, y1), ptRB( x2, y2 ) {
		cout << "CRect Constructor" << endl;
	}
	void ShowPos() {
		ptLT.ShowPos();
		cout << ",";
		ptRB.ShowPos(true);
	}
private:
	CPoint ptLT, ptRB;
};

class CCuboid: public CRect {
public:
	CCuboid( int x1, int y1, int x2, int y2, float height )
		: CRect(x1, y1, x2, y2 ),
		ptCenter((x1+x2)/2, (y1+y2)/2),
		fHeight(height)
	{
		cout << "CCuboid Constructor" << endl;
	}
	void ShowAll() {
		cout << "Rect Points: ";  CRect::ShowPos();
		cout << "Center: ";  ptCenter.ShowPos(true);
		cout << "Height: " << fHeight << endl;
	}
private:
	CPoint  ptCenter;
	float   fHeight;
};

int main() {
	CCuboid one( 5, 5, 30, 30, 50 );
	one.ShowAll();

	return 0;
}\
