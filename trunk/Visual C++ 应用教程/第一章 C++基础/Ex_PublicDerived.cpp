///////////////////////////////////
// Date: 2009-09-20
// Author: Yishi Guo
// Chapter: 1
// Pages: 22
// Exercises: Ex_PublicDerived
///////////////////////////////////
#include <iostream.h>
#include <string.h>

class CPerson {
public:
	CPerson( char* name, int age, char sex = 'M' ) {
		strncpy( this->name, name, 20 );
		this->age = age;  this->sex = sex;
	}
	void SetNameAndSex( char* name, char sex = 'M' ) {
		strncpy( this->name, name, 20 );
		this->sex = sex;
	}
protected:
	void SetAge( int age ) {
		this->age = age;
	}
	void ShowInfo() {
		cout << "Name: " << name << endl;
		cout << "Sex: " << (sex=='M'?"Male":"Female") << endl;
		cout << "Age: " << age << endl;
	}
private:
	char name[20];
	char sex;
	int age;
};

class CStudent: public CPerson {
public:
	CStudent(char* name, char* no, int age, char sex='M')
		:CPerson(name, age, sex) {
		strncpy(this->stuno, no, 20);
	}
	void SetScore( float s1, float s2, float s3 ) {
		score[0] = s1;  score[1] = s2; score[2] = s3;
		total = s1 + s2 + s3;  ave = total / (float)3.0;
	}
	void SetNoAndAge( char* no, int age ) {
		strncpy( this->stuno, no, 20);  this->SetAge( age );
	}
	void ShowAll() {
		ShowInfo();
		cout << "No.: " << stuno << endl;
		cout << "Scores: " << score[0] << "\t"
			               << score[1] << "\t"
						   << score[2] << endl;
		cout << "Total&Average: " << total << "\t" << ave << endl;
	}
private:
	char stuno[20];
	float score[3], ave, total;
};
int main() {
	CStudent one("LiMing", "21050101", 19 );
	one.SetScore( 90, 80, 84 );
	one.ShowAll();
	one.SetNameAndSex("WangFang", 'W');
	one.SetNoAndAge("21050102", 18);
	one.ShowAll();

	return 0;
}

