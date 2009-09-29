//////////////////////////
// Date: 2009-09-21
// Author: Yishi Guo
// Page: 271
// Exercise: Ex_Shape
//////////////////////////
#include <iostream.h>
#define PI 3.14159265

class CShape
{
public:
	virtual float Area() {
		return 0.0;
	}
	virtual void SetData( float, float ) {
	}
};

class CRect : public CShape {
public:
	CRect( float h = 0, float w = 0 ) {
		H = h;
		W = w;
	}
	float Area() {
		return (float)(H * W * 0.5);
	}
	void SetData( float h, float w ) {
		H = h;
		W = w;
	}
private:
	float H, W;
};

class CCircle : public CShape {
public:
	CCircle(float r = 0) {
		R = r;
	}
	float Area() {
		return (float)(PI * R * R);
	}
	void SetData( float r, float ) {
		R = r;
	}
private:
	float R;
};

class CArea {
public:
	CArea()
		: fSum(0), nNum(0), pCur(NULL) {
	}
	void SetShape( CShape *p ) {
		pCur = p;
	}
	void SetData( float f1, float f2 = 0.0 ) {
		pCur->SetData( f1, f2 );
	}
	void AddShape() {
		nNum++;
		fSum += pCur->Area();
	}
	void ShowSumArea() {
		cout << "Now Shapes: " << nNum << ", Total Area: " << fSum << endl;
	}
	void Clear() {
		fSum = 0;
		nNum = 0;
		pCur = NULL;
	}
private:
	float fSum;
	int nNum;
	CShape *pCur;
};

int main() {
	CArea all;
	CRect rc(3, 4);
	CCircle cir( 5 );

	all.SetShape( &rc );
	all.AddShape();
	all.SetShape( &cir );
	all.AddShape();
	all.ShowSumArea();

	all.Clear();
	all.SetShape( &rc );   all.SetData( 6, 8 );  all.AddShape();
	all.SetShape( &cir );  all.SetData( 10 );    all.AddShape();
	all.ShowSumArea();

	return 0;
}
