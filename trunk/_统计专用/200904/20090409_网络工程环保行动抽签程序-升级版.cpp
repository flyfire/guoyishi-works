//For [Network Engineering] Random Number Generator
//Author:Guo Yishi
//Date: 20090330
//Modified: 20090409
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

void printLine()
{
	cout << "======================================" << endl;
}

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

//print the start line and content
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
	printLine();
}

//print the students name and the finish
void printFinish(vector<string> answerVec,int cnt)
{
	//output the names who had answer the question
	cout << endl;
	printLine();
	cout << "The Following " << cnt << " students answered the questions:" << endl;
	int i = 0;
	for (vector<string>::iterator iter = answerVec.begin();
	iter != answerVec.end(); ++iter) {
		cout << *iter << "\t";
		if (((i++) + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
	//print the finish
	printLine();
	getch();
	cout << "Science Software College" << endl;
	getch();
	cout << "Innovation Group" << endl;
	getch();
	cout << "Yishi Guo" << endl;
	getch();
	cout << "Thanks!" << endl;
	printLine();
	while (getch() != '.')
		;	//empty
	return;
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
	string saveFileName;

	//get the localtime for savename
	char buffer[256];
	string strDate;
	time_t time_current;
	time_current = time((time_t*)NULL);
	strftime(buffer,sizeof(buffer),"%Y%m%d-%H%M",localtime(&time_current));
	strDate = buffer;

	//add ".txt" to the file
	saveFileName = strDate + "-saveNameFile" + ".txt";

	//check the saveFile
	ofstream saveFile(saveFileName.c_str());
	if (!saveFile) {
		cerr << "Could not save!" << endl;
		isSavedOk = false;
	}
	else {
		//add start time to the saveNameFile
		strftime(buffer,sizeof(buffer),"%Y%m%d %H:%M",localtime(&time_current));
		string saveTime = buffer;
		saveFile << "START TIME: " << saveTime << endl;
	}

	map<string, string> stu_map;	//////////////////////////////
	getAllStu(class_map, stu_map);

	int allStuCnt = 0;
	allStuCnt = getAllStuNumber(class_map);

	printStart(class_map, n, allStuCnt);

	srand((unsigned)time(NULL));

	int cnt = allStuCnt;
	vector<string> nameVec;
	vector<string> answerVec;

	bool finishAll = true;	//Finish the program yet?

	cout << "Enter . to end" << endl;

	while (cnt--) {
		cout << "NEXT(" << allStuCnt - cnt << "):";
		if (getch() == '.') {
			finishAll = false;
			break;
		}

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
				answerVec.push_back(stu_map[stuName]);
				if (isSavedOk) {
					saveFile << "No." << allStuCnt - cnt << "\t" << stu_map[stuName] << "\t" << className << "\t";
					if (itos(stuNo).size() != 2)
						saveFile << "0" << stuNo << endl;
					else
						saveFile << stuNo << endl;
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

	//print students name & finish
	printFinish(answerVec,allStuCnt - cnt - 1);
	saveFile.close();

	return 0;
}