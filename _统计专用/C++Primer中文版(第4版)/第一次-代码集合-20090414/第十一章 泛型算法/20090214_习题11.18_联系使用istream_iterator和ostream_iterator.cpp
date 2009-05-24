#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	ofstream oddFile("20090214_oddfile.dat");
	ofstream evenFile("20090214_evenfile.dat");

	if (!oddFile || !evenFile) {
		cerr << "Can not open output file!" << endl;
		return EXIT_FAILURE;
	}

	cout << "Enter some integers(Ctrl+Z to end):" << endl;
	istream_iterator<int> inIter(cin), eof;
	ostream_iterator<int> outOddIter(oddFile, " ");
	ostream_iterator<int> outEvenIter(evenFile, "\n");

	while (inIter != eof) {
		if (*inIter % 2 != 0) {
			*outOddIter = *inIter;
			++outOddIter;
		}
		else {
			*outEvenIter = *inIter;
			++outEvenIter;
		}
		++inIter;
	}

	oddFile.close();
	evenFile.close();

	return 0;
}
