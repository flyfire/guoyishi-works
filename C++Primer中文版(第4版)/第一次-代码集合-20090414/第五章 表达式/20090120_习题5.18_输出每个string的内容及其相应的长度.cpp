#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string*> spvec;

	//get vector 
	string str;
	cout << "Enter some strings(Ctrl+Z to end)" << endl;
	while(cin >> str){
		string *pstr = new string;
		*pstr = str;
		spvec.push_back(pstr);
	}

	//
	vector<string*>::iterator iter = spvec.begin();
	while(iter != spvec.end()){
		cout << **iter << (**iter).size() << endl;
		iter++;
	}

	//
	iter = spvec.begin();
	while(iter != spvec.end()){
		delete *iter;
		iter++;
	}

	return 0;
}