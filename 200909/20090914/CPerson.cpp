#include <iostream.h>
#include <stdlib.h>
#include <string.h>

class CPerson
{
public:
	CPerson(){};
	CPerson( char* strname, char* strno ){
		strcpy( strName, strname );
		strcpy( strStuNO, strno );
	}
	CPerson( CPerson &one ) {
		strcpy( strName, one.strName );
		strcpy( strStuNO, one.strStuNO );
	}
	void SetData( char* strname, char* strno ) {
		strcpy( strName, strname );
		strcpy( strStuNO, strno );
	}
	void Output(void) {
		cout << "Name: " << strName << endl;
		cout << "No: " << strStuNO << endl;
	}
	void Input(void) {
		cout << "Name: ";
		cin >> strName;

		cout << "No: ";
		cin >> strStuNO;
	}

private:
	char strName[12];
	char strStuNO[9];
};

class CScore
{
public:
	CScore() {};
	CScore( char* stuName, char* stuNo ) {
		stu.SetData( stuName, stuNo );
	}
	CScore( CScore &one ) {
		stu = one.stu;
		fScore[0] = one.fScore[0];
		fScore[1] = one.fScore[1];
		fScore[2] = one.fScore[2];
	}
	void SetData( char* strname, char* strno, float s1, float s2, float s3 ) {
		stu.SetData( strname, strno );
		fScore[0] = s1;
		fScore[1] = s2;
		fScore[2] = s3;
	}
	void Output( void ) {
		stu.Output();
		cout << "Three Mark: " << fScore[0] << ", "
			 << fScore[1] << ", "
			 << fScore[2] << endl;
	}
	void Input( void ) {
		stu.Input();
		cout << "Three Mark: ";
		cin >> fScore[0] >> fScore[1] >> fScore[2];
	}
private:
	CPerson stu;
	float fScore[3];
};

class CStack
{
public:
	CStack( int nSize = 10 );
	~CStack();
public:
	void push( CScore a );
	CScore pop(void);
private:
	CScore* sp;
	CScore* buffer;
	int m_nSize;
};

CStack::CStack(int nSize) {
	m_nSize = nSize;
	buffer = new CScore[m_nSize];
	if ( buffer != NULL ) {
		sp = buffer;
	} else {
		exit(1);
	}
	cout << "Complately!" << endl;
}
CStack::~CStack() {
	if ( buffer ) {
		delete [m_nSize]buffer;
		buffer = NULL;
		cout << "Release the space!" << endl;
	}
}
void CStack::push( CScore a ) {
	if ( sp >= buffer+m_nSize ) {
		cout << "Not more space!" << endl;
		exit(1);
	} else {
		*sp++ = a;
	}
}
CScore CStack::pop(void) {
	sp--;
	if ( sp <= buffer ) {
		cout << "Throught the bottom!" << endl;
		exit(1);
	} else {
		return *sp;
	}
}

int main(int argc, char** argv) {
	/*
	CStack one(3);
	CScore stu;
	stu.Input();
	one.push(stu);
	stu.SetData( "DING", "21010102", 80, 80, 90 );
	one.push(stu);
	stu.SetData( "ZHANG", "21010103", 80, 90, 70 );
	one.push(stu);
	cout << "Begining pop!" << endl;
	stu = one.pop();
	stu.Output();
	stu = one.pop();
	stu.Output();
	stu = one.pop();
	stu.Output();
	*/

	CScore stu2("23", "32");
	stu2.Input();

	int a;

	return 0;
}