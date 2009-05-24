#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	//读入数据到vector对象
	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	//计算相邻元素的和并输出
	if(ivec.size()==0){
		cout << "No element?!" << endl;
		return -1;
	}
	cout << "Sum of each pair of adjacent element in the vector:"
		<<endl;
	for(vector<int>::size_type ix =0;ix < ivec.size()-1;ix+=2){
		cout << ivec[ix]+ivec[ix+1] << "\t";
		if((ix+1)%6==0)	//每行输出6个和
			cout << endl;
	}

	if(ivec.size()%2!=0)	//如为奇数,提示最后一个元素没有和
		cout << endl
		<< "The last element is not been summed "
		<< "and its value is "
		<< ivec[ivec.size()-1] << endl;

	return 0;


}