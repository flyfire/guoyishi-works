//For my friend Kim
#include <iostream>
using namespace std;

int main()
{
	char new_year_2009;
	int flag=0;
	cout << "Do you happy in 2009?(y/n)" << endl;
	cin >> new_year_2009;
	if(new_year_2009=='y')
		flag=1;
	switch(flag){
	case 1:
		cout << "Yes! Happy New Year!" << endl;
		break;
	case 0:
		cout << "Why? man?";
		cout << "Do you know:"
			 << "�ྡ������Ϊ��,��������ӿ��Ȫ"
			 << endl;
		break;
	default:
		break;
	}

	cout << "For Kim!" <<endl;

	return 0;

}