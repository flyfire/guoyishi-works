//20090328 Random Number Generator
#include <iostream>
#include <fstream>	//for file streams
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cout << "========0813213 Student Number Random Maker========" << endl;

	//get the class total number
	int total;
	cout << "Enter your class total number of students:";
	cin >> total;

	//Open related file
	ofstream os;
	string fileName;

	cout << "Enter student file name:" << endl;
	cin >> fileName;
	os.open(fileName.c_str());
	if (!os) {
		cerr << "Could not open file!" << endl;
	}

	cout << "Maker begin!!!" << endl;

	vector<int> ivec;
	int next;
	int count = 0;

	srand((unsigned)time(NULL));	//Random number generator

	bool flag = true;
	while (flag) {
		//get 1 <= number <= total
		cout << "Enter next:";
		cin >> next;
		if(count++ == total - 1)	//end the maker
			flag = false;
		
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
		
		/////////////////////////////////////////////////////////////////////////////
		vector<string>::iterator it = os.b
		//Print the number
		cout << "==== ==== ====" << endl;
		cout << "No." << count << ": " << number << endl;
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
