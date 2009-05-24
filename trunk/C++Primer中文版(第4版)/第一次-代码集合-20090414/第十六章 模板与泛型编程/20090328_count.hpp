#ifndef COUNT_H
#define COUNT_H

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename Type>
size_t count (const vector<Type> &vec,const vector<Type> &sought)
{
	size_t result = 0;
	for (typename vector<Type>::const_iterator iter = sought.begin();
	iter != sought.end(); ++iter)
		result += std::count(vec.begin(), vec.end(), *iter);

	return result;
}

//template specialization
template <>
size_t count<string>(const vector<string> &vec, const vector<string> &sought)
{
	size_t result = 0;
	for (vector<string>::const_iterator iter = sought.begin();
	iter != sought.end(); ++iter)
		result += std::count(vec.begin(), vec.end(), *iter);

	//note print
	cout << "template spacialization" << endl;

	return result;
}

#endif
