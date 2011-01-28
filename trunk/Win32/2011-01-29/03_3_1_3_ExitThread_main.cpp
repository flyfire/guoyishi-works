// ** 2011-01-29 Win32 3.1.3 ExitThread()
// ** Yishi Guo
#include <stdio.h>
#include <windows.h>

class CMyClass {
public:
	CMyClass() {
		printf( "Constructor\n" );
	};
	~CMyClass() {
		printf( "Destructor\n" );
	};
};

int main( int argc, char** argv ) {
	CMyClass theObject;
	::ExitThread( 0 );	// No "Destructor" print

	return 0;
}