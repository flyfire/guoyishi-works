#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<char> cvec;
	char cval;

	//Get
	cout << "Enter Character(# to end):" << endl;
	while(cin >> cval && cval != '#'){
		cvec.push_back(cval);
	}

	//Print
	for(vector<char>::iterator iter = cvec.begin();iter != cvec.end();++iter){
		cout << *iter ;
		if(iter != cvec.end()-1)
			cout << " ";
		else
			cout << endl;
	}

	//Change
	for(vector<char>::iterator iter1 = cvec.begin(),iter2 = cvec.end()-1;iter1 < iter2;++iter1,--iter2){
		char ch;
		ch = *iter1;
		*iter1 = *iter2;
		*iter2 = ch;
	}

	//Preit again
	for(vector<char>::iterator iter3 = cvec.begin();iter3 != cvec.end();++iter3){
		cout << *iter3;
		if(iter3 != cvec.end()-1)
			cout << " ";
		else
			cout << endl;
	}

	return 0;
}


