//20090414
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream inOut("20090414-copyOut",
		fstream::ate | fstream::in | fstream::out);

	if (!inOut) {
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}

	ifstream::pos_type end_mark = inOut.tellg();
	inOut.seekg(0, fstream::beg);
	int cnt = 0;
	string line;

	while (inOut && (inOut.tellg() != end_mark) && (getline(inOut, line))) {
		cnt += line.size() + 1;
		ifstream::pos_type mark = inOut.tellg();
		inOut << cnt;

		if (mark != end_mark)
			inOut << " ";
		inOut.seekg(mark);
	}
	inOut.clear();
	inOut.seekp(0, fstream::end);
	inOut << "\n";

	return 0;
}