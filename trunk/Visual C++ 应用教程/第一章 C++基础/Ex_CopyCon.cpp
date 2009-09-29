/////////////////////////
// Date: 2009-09-20
// Author: Yishi Guo
// Chapter: 1
// Pages: 18
/////////////////////////
#include <iostream.h>
#include <string.h>

class CName {
public:
	CName() {
		strName = NULL;
	}
	CName( char* str ) {
		strName = (char*)new char[strlen(str)+1];
		strcpy( strName, str );
	}
	CName( CName &one ) {
		strName = (char*)new char[strlen(one.strName)+1];
		strcpy( strName, one.strName );
	}
	CName( CName &one, char* add ) {
		strName = (char*)new char[strlen(one.strName)+strlen(add)+1];
		strcpy( strName, one.strName );
		strcat( strName, add );
	}
	~CName() {
		if (strName) delete[] strName;
		strName = NULL;
	}
	char* getName() {
		return strName;
	}

private:
	char* strName;
};

int main() {
	CName o1("DING");
	CName o2(o1);
	cout << o2.getName() << endl;
	CName o3(o1, "YOU HE");
	cout << o3.getName() << endl;

	return 0;
}