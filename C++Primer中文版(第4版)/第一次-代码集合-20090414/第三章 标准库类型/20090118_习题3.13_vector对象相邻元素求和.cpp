#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<int> ivec;
	int ival;

	//�������ݵ�vector����
	cout << "Enter numbers(Ctrl+Z to end):" << endl;
	while(cin >> ival)
		ivec.push_back(ival);

	//��������Ԫ�صĺͲ����
	if(ivec.size()==0){
		cout << "No element?!" << endl;
		return -1;
	}
	cout << "Sum of each pair of adjacent element in the vector:"
		<<endl;
	for(vector<int>::size_type ix =0;ix < ivec.size()-1;ix+=2){
		cout << ivec[ix]+ivec[ix+1] << "\t";
		if((ix+1)%6==0)	//ÿ�����6����
			cout << endl;
	}

	if(ivec.size()%2!=0)	//��Ϊ����,��ʾ���һ��Ԫ��û�к�
		cout << endl
		<< "The last element is not been summed "
		<< "and its value is "
		<< ivec[ivec.size()-1] << endl;

	return 0;


}