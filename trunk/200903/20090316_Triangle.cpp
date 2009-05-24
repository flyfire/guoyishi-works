//20090316 Triangle
class TrianglePoint{
private:
	int Ax, Ay;
	int Bx, By;
	int Cx, Cy;
public:
	TrianglePoint(int a1, int a2, int b1, int b2, int c1, int c2){
		Ax = a1; Ay = a2;
		Bx = b1; By = b2;
		Cx = c1; Cy = c2;
	}
	int getFirst()