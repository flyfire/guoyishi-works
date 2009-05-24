//For [Network Engineering] Random Number Generator
//Author:Guo Yishi
//Date: 20090330
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
using namespace std;

bool open_file(string className, map<string, int>& class_map, int& n, vector<string>& svec)
{
	string classFile = className + ".txt";

	ifstream name_file;
	name_file.open(classFile.c_str());
	if (!name_file) {
		cerr << "Could not open file!" << endl;
		return false;
	}
	else {
		cout << "Open file successful!" << endl;
		svec.push_back(className);
		++n;
		int stuNoMax = 0;
		string stuNo;
		string stuName;
		while (name_file >> stuNo >> stuName) {
			int number = atol(stuNo.c_str());
			if (number > stuNoMax) {
				stuNoMax = number;
			}
		}

		class_map.insert(make_pair(className, stuNoMax));
	}

	name_file.close();

	return true;
}

void getAllStu (map<string, int> class_map, map<string, string>& stu_map)
{
	for (map<string, int>::const_iterator map_it = class_map.begin();
	map_it != class_map.end(); ++map_it) {
		ifstream opFile;
		string stuNo;
		string stuName;
		opFile.open((map_it->first + ".txt").c_str());
		if(opFile)
			while (opFile >> stuNo >> stuName) {
				stu_map.insert(make_pair(map_it->first + stuNo, stuName));
			}
	}

	return;
}

int getAllStuNumber(map<string, int> class_map)
{
	int allStuCnt = 0;
	for (map<string, int>::const_iterator class_map_it = class_map.begin();
	class_map_it != class_map.end(); ++class_map_it) {
		allStuCnt += class_map_it->second;
	}

	return allStuCnt;
}

//int to string
string itos(int i)
{
	stringstream s;
	s << i;
	return s.str();
}

void printStart(map<string, int> class_map, int n, int allStuCnt)
{
	//////////////////////////////////////////////
	cout << "==== ==== Generator Start!!! ==== ====" << endl;
	cout << n << " classes\t" << allStuCnt << " students" << endl;
	for (map<string, int>::const_iterator it = class_map.begin();
	it != class_map.end(); ++it) {
		cout << "class: " << it->first
			<< "\tnumber: " << it->second << endl;
	}
	cout << "======================================" << endl;
}

int main()
{
	cout << "==== ==== Random Number Generator ==== ====" << endl;

	int n = 0;
	string className;
	map<string, int> class_map;	////////////////////////////////
	vector<string> svec;
	cout << "Enter class name(Ctrl+Z to end):" << endl;
	while (true) {
		cout << "Class: ";
		if (cin >> className) {
			open_file(className, class_map, n, svec);
		}
		else
			break;
	}
	cin.clear();

	//Save file
	bool isSavedOk = true;
	cout << "Enter save file name: ";
	string saveFileName;
	if (!(cin >> saveFileName))
		saveFileName = "meiyou.org";
	ofstream saveFile(saveFileName.c_str());
	if (!saveFile) {
		cerr << "Could not save!" << endl;
		isSavedOk = false;
	}

	map<string, string> stu_map;	//////////////////////////////
	getAllStu(class_map, stu_map);

	int allStuCnt = 0;
	allStuCnt = getAllStuNumber(class_map);

	printStart(class_map, n, allStuCnt);

	srand((unsigned)time(NULL));

	int cnt = allStuCnt;
	vector<string> nameVec;
	while (cnt--) {
		cout << "NEXT(" << cnt << "):";
		getch();

		int classNo;
		while (true) {
			classNo = rand();
			classNo %= n;

			string className;
			className = svec[classNo];

			int stuNumber = class_map[className];

			int stuNo = rand();
			stuNo %= stuNumber;
			stuNo += 1;

			string stuName;
			stuName = itos(stuNo);

			stuName = className + stuName;

			if (!nameVec.empty() && find(nameVec.begin(), nameVec.end(), stuName) != nameVec.end()) {
				continue;
			}
			else {
				nameVec.push_back(stuName);
				if (isSavedOk) {
					saveFile << stuNo << "\t" << stuName << endl;
				}
			}

			cout << endl;
			cout << "==== ==== ====" << endl;
			cout << "Class:\t" << className << endl;
			cout << "Number:\t" << stuNo << endl;
			cout << "Name:\t" << stu_map[stuName] << endl;
			cout << "==== ==== ====" << endl;

			break;
		}
	}

	for (vector<string>::iterator iter = nameVec.begin();
	iter != nameVec.end(); ++iter) {
		cout << *iter << endl;
	}
	cout << "Thanks!" << endl;
	saveFile.close();

	return 0;
}