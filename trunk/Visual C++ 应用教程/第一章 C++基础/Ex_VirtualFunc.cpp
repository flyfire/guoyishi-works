//////////////////////////////////////
// Date:              2009-09-20
// Author:            Yishi Guo
// Chapter:           1
// Page:              29
// Exercise:          Ex_VirtualFunc
//////////////////////////////////////
#include <iostream.h>
#define PI 3.14159265

class CShape {
public:
	virtual float area() {
		return 0.0;
	}
};
class CTriangle : public CShape {
public:
	CTriangle( float h = 0, float w = 0 ) {
		H = h;  W = w;
	}
	float area() {
		return ( float) (H * W * 0.5);
	}
private:
	float H, W;
};

class CCircle: public CShape {
public:
	CCircle(float r = 0) {
		R = r;
	}
	float area() {
		return (float)(PI * R * R);
	}
private:
	float R;
};

int main() {
	CTriangle tri( 3, 4 );
	cout << "tri.area() = " << tri.area() << endl;
	CCircle cir(5);
	cout << "cir.area() = " << cir.area() << endl;
	CShape *s1 = &tri;
	cout << "s1->area() = " << s1->area() << endl;
	CShape &s2 = cir;
	cout << "s2.area() = " << s2.area() << endl;

	return 0;
}