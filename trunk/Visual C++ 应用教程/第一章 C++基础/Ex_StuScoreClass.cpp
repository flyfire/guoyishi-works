#include <iostream.h>
class CStuscore {
public:
	float Average( void );
	char* getName() {
		return strName;
	}
	char* getNo() {
		return strStuNO;
	}
private:
	char strName[12];
	char strStuNO[9];
private:
	float fScore[3];
};
float CStuscore::Average( void ) {
	return (float)((fScore[0] + fScore[1] + fScore[2])/3.0);
}

int main() {
	return 0;
}
