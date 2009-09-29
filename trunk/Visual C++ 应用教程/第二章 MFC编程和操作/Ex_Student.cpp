////////////////////////////////
// Date: 2009-09-21
// Author: Yishi Guo
// Exercise: 3
// Page: 266
////////////////////////////////
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

class CPerson {
public:
	CPerson() {};
	void SetPersonInfo( char* strname, int age, char sex = 'M' ) {
		strncpy( strName, strname, sizeof( strName ));
		nAge = age;
		chSex = sex;
	}
	void Show() {
		cout << "Name: " << strName
			 << ", Age: " << nAge
			 << ", Sex: " << ( chSex == 'M'?"Male":"Female" )
			 << endl;
	}
protected:
	char strName[20];
	char chSex;
	int nAge;
};

class CCourse {
public:
	CCourse() {};
	CCourse( CCourse &one ) {
		strncpy( strName, one.strName, sizeof( strName ) );
		fCredit = one.fCredit;
		fScore = one.fScore;
	}
	void SetCourseInfo( char* strname, float credit, float score ) {
		strncpy( strName, strname, sizeof( strName ) );
		fCredit = credit;
		fScore = score;
	}
	void Show() {
		cout << "Course name: " << strName
			 << ", Credit: " << fCredit
			 << ", Score: " << fScore
			 << endl;
	}
	float GetCredit() { return fCredit; }
	float GetScore() { return fScore; }
private:
	char strName[40];
	float fCredit;
	float fScore;
};

class CStudent: public CPerson {
public:
	CStudent()
		: nNum( 0 ), allScore( 0.0 ), aveScore( 0.0 ), allCredit( 0.0 ) {
	}
	CStudent( CStudent &one ) {
		for ( int i = 0; i < nNum; i++ ) {
			cc[i] = one.cc[i];
		}
		allScore = one.allScore;
		aveScore = one.aveScore;
		allCredit = one.allCredit;
		strncpy( strNO, one.strNO, sizeof(strNO));
		strcpy( strName, one.strName );
		nAge = one.nAge;
		chSex = one.chSex;
	}
	void SetStudentInfo( char* strname, char* strno, int age, char sex = 'M') {
		SetPersonInfo( strname, age, sex );
		strcpy( strNO, strno );
	}
	char* GetStuNo() {
		return strNO;
	}
	void Add( CCourse one ) {
		cc[ nNum ] = one;
		nNum++;
		if ( nNum >= 8 ) {
			cout << "No course space!" << endl;
			exit( 1 );
		}
			allScore += one.GetScore();
			aveScore = allScore / (float)nNum;
			allCredit += one.GetCredit();
		}
	void Show() {
		cout << "Number: " << strNO << endl;
		CPerson::Show();
		for (int i = 0; i < nNum; i++ )
			cc[i].Show();
		cout << "Total course: " << nNum
			 << ",Total credit: " << allCredit
			 << ", Total score: " << allScore
			 << ", Average score: " << aveScore
			 << endl;
	}
private:
	char strNO[20];
	CCourse cc[8];
	float allScore;
	float aveScore;
	float allCredit;
	int nNum;
};

class CClass {
public:
	CClass( char* strNO, int nSize = 10 )
		: nNum( 0 ) {
		theStudent = new CStudent[nSize];
		this->nSize = nSize;
		strcpy( this->strNO, strNO );
	}
	~CClass() {
		if (theStudent) {
			delete[] theStudent;
			theStudent = NULL;
		}
	}
	void Add( CStudent one ) {
		theStudent[nNum] = one;
		nNum++;
		if (nNum >= nSize) {
			cout << "No Space!" << endl;
			exit(1);
		}
	}
	void Seek( char* strStuNo) {
		bool isFind = false;
		int i;
		for (i = 0; i < nNum; i++) {
			if ( 0 == strcmp( theStudent[i].GetStuNo(), strStuNo ) ) {
				isFind = true;
				break;
			}
		}
		cout << endl;
		if ( isFind ) {
			cout << "Find the number[" << strStuNo << "] student:" << endl;
			theStudent[i].Show();
		} else {
			cout << "Could not find the [" << strStuNo << "] student!" << endl;
		}
	}
	void ShowAll() {
		cout << "Class: " << strNO << ", Number: " << nNum << endl;
		for ( int i = 0; i < nNum; i++ ) {
			theStudent[i].Show();
			cout << endl;
		}
	}
private:
	CStudent *theStudent;
	char strNO[20];
	int nNum;
	int nSize;
};

int main() {
	CClass theClass("210501");
	CStudent one, two, three;
	CCourse cc;
	
	// for debug
	cout << "#1" << endl;

	one.SetStudentInfo( "LiMing", "21050101", 18 );
	cc.SetCourseInfo( "C++ Programming", 3.5, 80);
	one.Add( cc );
	cc.SetCourseInfo( "Data Structure", 3, 81 );
	one.Add( cc );
	cc.SetCourseInfo( "Software ABC", 2, 85 );
	one.Add( cc );
	theClass.Add( one );

	// for debug
	cout << "#2" << endl;

	two.SetStudentInfo( "WangFang", "21050102", 18, 'W');
	cc.SetCourseInfo( "C++ Programming", 3.5, 70 );
	two.Add( cc );
	cc.SetCourseInfo( "Data Structure", 3, 78 );
	two.Add( cc );
	cc.SetCourseInfo( "Software ABC", 2, 81 );
	two.Add( cc );
	theClass.Add( two );

	// for debug
	cout << "#3" << endl;

	three.SetStudentInfo( "YangYang", "21050103", 19 );
	cc.SetCourseInfo( "C++ Programming", 3.5, 81 );
	three.Add( cc );
	cc.SetCourseInfo( "Data Structure", 3, 75 );
	three.Add( cc );
	cc.SetCourseInfo( "Software ABC", 2, 84 );
	three.Add( cc );
	theClass.Add( three );

	// for debug
	cout << "#4" << endl;

	theClass.ShowAll();

	// for debug
	cout << "#5" << endl;

	theClass.Seek( "21050102" );

	return 0;
}