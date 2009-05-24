#include <iostream>
#include <fstream>
#include <sstream>

std::istream& get(std::istream& in)
{
	int ival;

	while (in >> ival, !in.eof()) {
		if (in.bad())
			throw std::runtime_error("IO stream corrtupted");
		if (in.fail()) {
			std::cerr << "bad data,try again";
			in.clear();
			in.ignore(200,' ');
			continue;
		}

		std::cout << ival << " ";
	}
	in.clear();

	return in;
}