#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

class saddle {
public:
	saddle() {}
	saddle(int i, int j, int val):
	  row(i), column(j), value(val) {}
	int row;
	int column;
	int value;

};

int main()
{
	int n;
	cout << "Enter N(for N * N matrix):" << endl;
	cin >> n;

	vector<saddle> svec;	//original matrix
	vector<saddle> sadvec;	//save the saddle point

	//get the values for matrix
	int i, j, val;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cin >> val;
			saddle sad(i, j, val);
			svec.push_back(sad);
		}
	}

	//Test the row for max value
	for (i = 1; i <= n; ++i) {
		cout << "\n\n\nTEST #1 for loop : " << " i = " << i << endl;///////////////
		int max = svec[n * (i - 1)].value;
		cout << "TEST $1 max = " << max << endl;///////////////////
		int max_id;
		bool repeat = false;
		for (j = 1; j < n; ++j) {
			cout << "TEST #2 for loop : " << " j = " << j << endl;/////////////////
			if (svec[n * (i - 1) + j].value > max) {
				max = svec[n * (i - 1) + j].value;
				max_id = n * (i - 1) + j;
				continue;
			}
			if (svec[n * (i - 1) + j].value == max)
				repeat = true;
			cout << "TEST $2 n * (i - 1) + j = " << n << " * (" << i << " - 1) + " << j << " = " << n * (i - 1) + j << endl; ///////////////
			if (repeat)
				cout << "TEST #3 repeat = " << repeat << endl;////////////////////
		}

		//Test for column
		int col = max_id % n;
		int col_min = svec[max_id].value;

		if (!repeat) {
			cout << "TEST #4 if !repeat" << endl;///////////////
			for (int k = 0; k < n; ++k) {

				cout << "TEST #5 for loop : " << " k = " << k << endl;///////////////////
				cout << "TEST $3 " << "col = " << col << "\tcol_min = " << col_min << "\tn * k + col = " << n * k + col << endl;//////////

				if (svec[n * k + col].value <= col_min) {
					if (n * k + col != max_id) {
						repeat = true;
						cout << "#2 true" << endl;
						break;
					}
				}
			}
			if (!repeat) {
				cout << "TEST #6 end" << endl;
				sadvec.push_back(svec[max_id]);
			}
		}
	}

	cout << "\n\n";
	for (vector<saddle>::iterator iter = svec.begin(); iter != svec.end(); ++iter) {
		cout<< " " << iter->value;
		if (iter->column == n)
			cout << endl;
	}

	cout << "\n\n";
	for (iter = sadvec.begin(); iter != sadvec.end(); ++iter) {
		cout << "row = " << iter->row << " column = " << iter->column << " value = " << iter->value << endl;
	}



	return 0;
}