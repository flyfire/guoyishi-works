//20090427 by Yishi Guo
//...
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <cctype>
#include <iomanip>
using namespace std;

//print a line with 4
void printLine()
{
	cout << "==== ==== ==== ====" << endl;
}

//print a line with "cnt"
void printLine(int cnt)
{
	while (cnt--) {
		cout << "==== ";
	}
	cout << endl;
}

//print the beginning
void beginPrint()
{
	cout << ">>> 软件学院五四青年节朗诵比赛评分程序 <<<" << endl;
	printLine(6);
	cout << "程序使用:" << endl;
	cout << "1, 评委人数应大于3(因为去掉一个最高分,一个最低分以后最少应剩下一个人)." << endl;
	cout << "2, 录入成绩时,输入数字'0'结束单个选手的成绩录入." << endl;
	cout << "3, 录入成绩后,请确认所录入成绩是否正确." << endl;
	cout << "4, 选手最后成绩排名会在最后显示." << endl;
	cout << "5, 如果某位选手没有参加比赛,录入成绩时请直接输入0,进行下一位选手的成绩输入." << endl;
	cout << "6, 程序如有什么问题,请及时与作者联系:13578916371." << endl;
	printLine(6);
}

//test the open file
string testFile()
{
	string fileName;
	string number;
	string name;
	string classes;
	bool flag = true;
	do {
		cout << "请输入比赛选手名单:" << endl;
		cin >> fileName;

		ifstream contFile;
		contFile.open(fileName.c_str());

		if (!contFile) {
			cerr << "输入错误,请重新输入:" << endl;
		}
		else {
			cout << "选手名单已经成功打开!" << endl;
			flag = false;
			printLine();
			contFile >> number >> name >> classes;
			cout << "编号\t姓名\t班级" << endl;
			while (contFile >> number >> name >> classes) {
				cout << "第" << number << "号\t" << name << "\t" << classes << "班" << endl;
			}
		}
	}while (flag);



	return fileName;
}

//test the string
bool testStr(string str)
{
	for (string::size_type index = 0; index != str.size(); ++index) {
		if (!isdigit(str[index]) && str[index] != '.')
			return false;
	}
	return true;
}

//string to double
double convertString(string str)
{
	double value;
	stringstream ss(str);
	ss >> value;
	return value;
}

//print double Vector
void printVector(vector<double>::const_iterator beg, vector<double>::const_iterator end)
{
	for (vector<double>::const_iterator iter = beg; iter != end; iter++) {
		cout << *iter << "\t";
	}
	cout << endl;
}

//class for Contestant
class contestant
{
public:
	contestant(): 
	  number("0"), name("NULL"), classes("000"), totalPoints(0.0) { }
	contestant(string nu, string contName, string clsNo):
	  number(nu), name(contName), classes(clsNo) { }
	
	double getScore()
	{
		return totalPoints;
	}

	void setTotalPoints(double total)
	{
		totalPoints = total;
	}

	void setPoints(vector<double> contPoints)
	{
		vector<double>::const_iterator iter1 = contPoints.begin();
		for (; iter1 != contPoints.end(); iter1++) {
			points.push_back(*iter1);
		}
	}

	void getPoints()
	{
		int cnt = 0;
		for (vector<double>::const_iterator iter = points.begin(); iter != points.end(); iter++) {
			cout << *iter << " ";
			++cnt;
			if (cnt % 10 == 0)
				cout << endl;
		}
	}

	string getName()
	{
		return name;
	}

	string getClass()
	{
		return classes;
	}

	string getNumber()
	{
		return number;
	}

private:
	string number;
	string name;
	string classes;
	double totalPoints;
	vector<double> points;
};

//main function
int main()
{
	beginPrint();	// print the beginning
	cout << setprecision(3);

	string fileName;
	fileName = testFile();	//test if the file
	ifstream openFile(fileName.c_str());

	string number;
	string name;
	string classes;

	//print the first line
	openFile >> number >> name >> classes;

	///////////////////////////////////////////////////////////////////
	/////////////// GET THE VALUE OF EVERY CONTESTANT /////////////////

	map<string, contestant> students;
	multimap<double, string> stuResult;
	//print the list of contestant
	while (openFile >> number >> name >> classes) {
		printLine(6);

		int cnt = 0;
		double point = 0.0;
		double totalPoints = 0.0;
		contestant newStu(number, name, classes);	//create new contestant class
		vector<double> points;
		vector<double> pointsResult;
		string yesNo;

		//get the value of every contestant
		do {
			cout << "请输入第 " << number << " 号选手: " << name << " 的成绩(输入0结束):" << endl;
			
			if(!points.empty())
				points.clear();

			string str;
			while (cin >> str) {
				if (testStr(str))
					point = convertString(str);
				else {
					cout << "错误输入,请重新输入!" << endl;
					continue;
				}
				if (point == 0.0)
					break;
				points.push_back(point);
			}
			cin.clear();
			if (points.empty())
				break;

			cout << "以下为您输入的选手成绩:" << endl;
			printLine();
			for (vector<double>::const_iterator iter = points.begin();
			iter != points.end(); ++iter) {
				cout << *iter << "\t";
			}
			cout << endl;

			cout << "请您确认输入是否正确(Y/N): ";
			cin >> yesNo;

		}while (yesNo[0] != 'y' && yesNo[0] != 'Y');
		printLine();
		
		if (points.empty()) {
			cout << "第 " << number << " 号选手: " << name << " 没有参加比赛,比赛资格被取消!" << endl;
			continue;
		}

		//take off the highest mark and the lowest mark
		sort(points.begin(), points.end());

		printVector(points.begin(), points.end());
		printLine(2);
		cout << "去掉一个最高分: " << *(points.end() - 1) << endl;
		cout << "去掉一个最低分: " << *points.begin() << endl;
		printLine(2);
		cout << "以下为可用成绩: " << endl;
		for (vector<double>::const_iterator iter = points.begin() + 1; iter != points.end() - 1; ++iter) {
			cout << *iter << "\t";
			totalPoints += *iter;
			cnt++;
			pointsResult.push_back(*iter);
		}
		cout << endl;

		printLine();
		cout << "Total: " << totalPoints << "\t" << "Cnt: " << cnt << "\t";
		totalPoints /= cnt;
		cout << "Avg: " << totalPoints << endl;
		cout << "第 " << number << " 号选手 " << name << " 最后得分为:\t" << totalPoints  << "分." << endl;
		cout << endl;
		

		newStu.setPoints(pointsResult);
		newStu.setTotalPoints(totalPoints);
		students.insert(make_pair(number, newStu));
		stuResult.insert(make_pair(totalPoints, number));
	}

	///////////////////////////////////////////////////////////////////
	///////////////// CALULATE THE LIST OF RESULT /////////////////////
	int allStuNo = students.size();

	printLine(6);
	cout << "共有 " << allStuNo << " 名选手参加比赛:" << endl;
	printLine(6);
	cout << "==== ==== 最后成绩排名: ==== ====" << endl;
	
	//print the result!
	map<string, contestant>::iterator iter;
	string stuNo;
	double stuScore;
	double preScore = -1;
	int ranking = 0;
	///////////////CREAT SAVE FILE /////////////////
	char buffer[256];
	string strDate;
	time_t time_current;
	time_current = time((time_t*)NULL);
	strftime(buffer, sizeof(buffer), "%Y%m%d-%H`%M", localtime(&time_current));
	strDate = buffer;
	
	string saveFileName = strDate + "-选手名次列表.txt";

	ofstream saveFile(saveFileName.c_str());
	//////////////////END///////////////////////////

	for (multimap<double, string>::reverse_iterator riter = stuResult.rbegin(); riter != stuResult.rend(); riter++) {

		stuNo = riter->second;
		iter = students.find(stuNo);
				
		stuScore = (iter->second).getScore();

		if (stuScore != preScore)
			ranking++;
		preScore = stuScore;

		//print on screen
		cout << "第" << ranking << "名:\t"
			<< (iter->second).getNumber() << "号\t"
			<< (iter->second).getClass() << "班\t"
			<< (iter->second).getName() << "\t总分:"
			<< (iter->second).getScore() << endl;

		//print in save file
		saveFile << "第" << ranking << "名:\t"
			<< (iter->second).getNumber() << "号\t"
			<< (iter->second).getClass() << "班\t"
			<< (iter->second).getName() << "\t总分: "
			<< (iter->second).getScore() << endl;
	}

	printLine(6);
	cout << "感谢使用,祝比赛圆满举办!" << endl;

	//end the program
	while(true) {
		char ch;
		ch = getch();
		if (ch == '.')
			break;
	}


	return 0;
}