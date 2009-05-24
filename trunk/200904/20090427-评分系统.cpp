//20090427 by Yishi Guo
//...
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cctype>
using namespace std;

//print a line with 4
void printLine()
{
	cout << "==== ==== ==== ====" << endl;
}

//print a line with "cnt"
void printLine(int cnt)
{
	while (cnt--) {
		cout << "==== ";
	}
	cout << endl;
}

//print the beginning
void beginPrint()
{
	cout << ">>> Elocnte Begin <<<" << endl;
	printLine(5);
}

//test the open file
string testFile()
{
	string fileName;
	bool flag = true;
	do {
		cout << "Enter contestant file:" << endl;
		cin >> fileName;

		ifstream contFile;
		contFile.open(fileName.c_str());

		if (!contFile) {
			cerr << "Could not open file!" << endl;
		}
		else {
			cout << "Open successfully!" << endl;
			flag = false;
		}
	}while (flag);

	return fileName;
}

//test the string
bool testStr(string str)
{
	for (string::size_type index = 0; index != str.size(); ++index) {
		if (!isdigit(str[index]) && str[index] != '.')
			return false;
	}
	return true;
}

//string to double
double convertString(string str)
{
	double value;
	stringstream ss(str);
	ss >> value;
	return value;
}

//print double Vector
void printVector(vector<double>::const_iterator beg, vector<double>::const_iterator end)
{
	for (vector<double>::const_iterator iter = beg; iter != end; iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
}

//class for Contestant
class contestant
{
public:
	contestant(): 
	  number("0"), name("NULL"), classes("000"), totalPoints(0.0) { }
	contestant(string nu, string contName, string clsNo):
	  number(nu), name(contName), classes(clsNo) { }
	
	double getScore()
	{
		return totalPoints;
	}

	void setTotalPoints(double total)
	{
		totalPoints = total;
	}

	void setPoints(vector<double> contPoints)
	{
		vector<double>::const_iterator iter1 = contPoints.begin();
		for (; iter1 != contPoints.end(); iter1++) {
			points.push_back(*iter1);
		}
	}

	void getPoints()
	{
		int cnt = 0;
		for (vector<double>::const_iterator iter = points.begin(); iter != points.end(); iter++) {
			cout << *iter << " ";
			++cnt;
			if (cnt % 10 == 0)
				cout << endl;
		}
	}

	string getName()
	{
		return name;
	}

	string getClass()
	{
		return classes;
	}

private:
	string number;
	string name;
	string classes;
	double totalPoints;
	vector<double> points;
};

//main function
int main()
{
	beginPrint();	// print the beginning

	string fileName;
	fileName = testFile();	//test if the file
	ifstream openFile(fileName.c_str());

	string number;
	string name;
	string classes;

	//print the first line
	openFile >> number >> name >> classes;
	cout << number << "\t" << name << "\t" << classes << endl;

	///////////////////////////////////////////////////////////////////
	/////////////// GET THE VALUE OF EVERY CONTESTANT /////////////////

	map<string, contestant> students;
	multimap<double, string> stuResult;
	//print the list of contestant
	while (openFile >> number >> name >> classes) {
		printLine(6);
		cout << number << "\t" << name << "\t" << classes << endl;

		int cnt = 0;
		double point = 0.0;
		double totalPoints = 0.0;
		contestant newStu(number, name, classes);	//create new contestant class
		vector<double> points;
		vector<double> pointsResult;
		string yesNo;

		//get the value of every contestant
		do {
			cout << "Enter points(enter 0 to end):" << endl;
			if(!points.empty())
				points.clear();

			string str;
			while (cin >> str) {
				if (testStr(str))
					point = convertString(str);
				else {
					cout << "Error enter!" << endl;
					continue;
				}
				if (point == 0.0)
					break;
				points.push_back(point);
			}
			cin.clear();
			if (points.empty())
				break;

			cout << "Please confirm the points:" << endl;
			printLine();
			for (vector<double>::const_iterator iter = points.begin();
			iter != points.end(); ++iter) {
				cout << *iter << "\t";
			}
			cout << endl;

			cout << "Do you sure above is correct?(Y/N): ";
			cin >> yesNo;

		}while (yesNo[0] != 'y' && yesNo[0] != 'Y');
		printLine();
		
		if (points.empty()) {
			cout << "The " << name << " has not attend the contest!" << endl;
			continue;
		}

		//take off the highest mark and the lowest mark
		sort(points.begin(), points.end());

		printVector(points.begin(), points.end());
		printLine(2);
		cout << "Take off the highest mark: " << *(points.end() - 1) << endl;
		cout << "Take off the lowest mark: " << *points.begin() << endl;
		printLine(2);
		for (vector<double>::const_iterator iter = points.begin() + 1; iter != points.end() - 1; ++iter) {
			cout << *iter << "\t";
			totalPoints += *iter;
			cnt++;
			pointsResult.push_back(*iter);
		}
		cout << endl;

		printLine();
		cout << "Total:\t" << totalPoints << endl;
		cout << "Cnt:\t" << cnt << endl;
		totalPoints /= cnt;
		cout << "Avg:\t" << totalPoints << endl;

		newStu.setPoints(pointsResult);
		newStu.setTotalPoints(totalPoints);
		students.insert(make_pair(number, newStu));
		stuResult.insert(make_pair(totalPoints, number));
	}

	///////////////////////////////////////////////////////////////////
	///////////////// CALULATE THE LIST OF RESULT /////////////////////
	int allStuNo = students.size();

	printLine(6);
	cout << allStuNo << " students attended the contest:" << endl;
	printLine(6);
	
	//print the result!
	map<string, contestant>::iterator iter;
	string stuNo;
	string stuScore;
	string preScore;
	int ranking = 1;

	for (multimap<double, string>::reverse_iterator riter = stuResult.rbegin(); riter != stuResult.rend(); riter++) {

		stuNo = riter->second;
		stuScore = riter->first;
		if (riter != stuResult.rbegin()) {
			if (stuScore != preScore)
				++ranking;
		}
		preScore = stuScore;
		iter = students.find(stuNo);

		cout << "No." << ranking << ":\t"
			<< (iter->second).getClass() << "\t"
			<< (iter->second).getName() << "\t"
			<< (iter->second).getScore() << endl;
	}

	//end the program
	while(true) {
		char ch;
		ch = getch();
		if (ch == '.')
			break;
	}
	printLine(6);
	cout << "THANKS FOR USING IT!" << endl;

	return 0;
}