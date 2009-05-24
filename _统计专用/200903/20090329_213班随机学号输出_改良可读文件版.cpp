//20090328 Random Number Generator
//Edited by: Guo Yishi
//modified: 20090329
#include <iostream>
#include <fstream>	//for file streams
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	bool flag = true;
	cout << "========0813213 Student Number Random Maker========" << endl;

	//get the class total number
	int total;
	cout << "Enter your class total number of students:";
	cin >> total;

	//Open related file
	////////////////////////////////////////////////////////////////////////
	ifstream name_file;
	string fileName;

	cout << "Enter student file name:" << endl;
	cin >> fileName;
	name_file.open(fileName.c_str());
	
	map<int, string> trans_map;
	if (!name_file) {
		cerr << "Could not open file!" << endl;
		flag = false;
	}
	else {
		string stuNo;
		string stuName;
		while (name_file >> stuNo >> stuName) {
			trans_map.insert(make_pair(atol(stuNo.c_str()), stuName));
		}
	}
	/////////////////////////////////////////////////////////////////////////
	cout << "Maker begin!!!" << endl;

	vector<int> ivec;
	int next;
	int count = 0;

	srand((unsigned)time(NULL));	//Random number generator

	int n = total;
	while (n--) {
		flag = true;
		//get 1 <= number <= total
		cout << "Enter next:";
		cin >> next;
		
		int number;
		while (true) {
			number = rand();
			number %= total;
			number += 1;

			//Is the number exist?
			if(!ivec.empty() && find(ivec.begin(),ivec.end(),number) != ivec.end()) {
				continue;	//get the number again
			}
			else {
				ivec.push_back(number);	//add the number to vector<int>
				break;
			}
		}
		
		//Print student names
		/////////////////////////////////////////////////////////////////////////////
		map<int, string>::const_iterator map_it;
		if (flag) {
			map_it = trans_map.find(number);
			if (map_it == trans_map.end())	//Is the stuNo exist?
				flag = false;
		}
		/////////////////////////////////////////////////////////////////////////////
		//Print the number
		cout << "==== ==== ====" << endl;
		cout << "No." << ++count << ": " << number << " ";
		if (flag)	//print name
			cout << map_it->second << endl;
		else
			cout << endl;
		cout << "==== ==== ====\n" << endl;
	}
	
	//Print all numbers
	count = 0;
	for (vector<int>::iterator iter = ivec.begin();
	iter != ivec.end(); ++iter) {
		cout << "No." << ++count << ":" << *iter << endl;
	}

	cout << "Thanks!" << endl;
	cin >> count;	//No meaning!

	return 0;
}
