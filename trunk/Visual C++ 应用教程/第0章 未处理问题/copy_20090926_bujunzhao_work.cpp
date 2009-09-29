#include<stdlib.h>
#include<iostream.h>
#include<string.h>
class CPerson
{
protected:
	char strName[20];
	char chSex;
	int nAge;
public:
	CPerson()
	{
	};
	void SetPersonInfo(char*strname,int age,char sex='M')
	{
		strncpy(strName,strname,sizeof(strName));
		nAge=age;
		chSex=sex;
	}
	void Show()
	{
		cout<<"����:"<<strName<<",����:"<<nAge<<",�Ա�:"
			<<(chSex=='M'?"��":"Ů")<<endl;
	}
};
class CCourse
{
// private:
public:
	char strName[40];
	float fCredit;
	float fScore;
public:
	CCourse()
	{
	};
	CCourse(CCourse &one)
	{
		strcpy(strName,one.strName);
		fCredit=one.fCredit;
		fScore=one.fScore;
	}
	void SetCourseInfo(char*strname,float credit,float score)
	{
		strcpy(strName,strname);
		fCredit=credit;
		fScore=score;
	}
	void Show()
	{
		cout<<"�γ���:"<<strName
			<<",ѧ��:"<<fCredit
			<<",�ɼ�:"<<fScore
			<<endl;
	}
	float GetCredit()
	{
		return fCredit;
	}
	float GetScore()
	{
		return fScore;
	}
};
class CStudent:public CPerson
{
// For debug
// private:
public:
	int nSize;
	CCourse *cc;
	char strNO[20];
	float allScore;
	float aveScore;
	float allCredit;
	int nNum;
public:
	CStudent()
		:nNum(0),allScore(0.0),aveScore(0.0),allCredit(0.0)
	{
        this->nSize = 9;
		cc=new CCourse[nSize];
	}
	CStudent(CStudent &one)
	{
		cc = new CCourse[one.nSize];
		nNum = one.nNum;
		nSize = one.nSize;

		for(int i=0;i<nNum;i++)//�˴������д�
			cc[i]=one.cc[i];
		allScore=one.allScore;
		aveScore=one.aveScore;
		allCredit=one.allCredit;
		strncpy(strNO,one.strNO,sizeof(strNO));
		strcpy(strName,one.strName);
		nAge=one.nAge;
		chSex=one.chSex;
	}
	~CStudent()
	{
		if(cc)
		{
			delete []cc;
			cc=NULL;
		}
	}
	void SetStudentInfo(char*strname,char*strno,int age,char sex='M')
	{
		SetPersonInfo(strname,age,sex);
		strcpy(strNO,strno);
	}
	char* GetStuNo()
	{
		return strNO;
	}
	void Add(CCourse one)
	{
		cc[nNum].SetCourseInfo( one.strName, one.fCredit, one.fScore);
		nNum++;

		if(nNum>=8)
		{
			cout<<"�γ����ݴ洢���ڴ�ռ䲻��!"<<endl;
			exit(1);
		}
		allScore+=one.GetScore();
		aveScore=allScore/(float)nNum;
		allCredit+=one.GetCredit();
	}
	void Show()
	{
		cout<<"ѧ��:"<<strNO<<endl;
		CPerson::Show();
		for(int i=0;i<nNum;i++)
			cc[i].Show();
		cout<<"�γ���:"<<nNum<<",��ѧ��:"<<allCredit
			<<",�ܳɼ�:"<<allScore<<",ƽ���ɼ�:"<<aveScore<<endl;
	}
};
class CClass
{
private:
	CStudent *theStudent;
	char strNO[20];
	int nNum;
	int nSize;
public:
	CClass(char*strNO,int nSize=10)
		:nNum(0)
	{
		theStudent = new CStudent[nSize];
		this->nSize = nSize;
		strcpy(this->strNO,strNO);
	}
	~CClass()
	{
		if(theStudent)
		{
			delete []theStudent;
			theStudent=NULL;
		}
	}
	void Add(CStudent one)
	{
		theStudent[nNum] = one;
		nNum++;
		if(nNum>=nSize)
		{
			cout<<"ѧ�����ݴ洢���ڴ�ռ䲻��!"<<endl;
			exit(1);
		}
	}
	void Seek(char *strStuNo)
	{
		bool isFind=false;
		int i;
		for(i=0;i<nNum;i++)
		{
			if(0==strcmp(theStudent[i].GetStuNo(),strStuNo))
			{
				isFind=true;
				break;
			}
		}
		cout<<endl;
		if(isFind)
		{
			cout<<"�ҵ�ѧ��Ϊ["<<strStuNo<<"]��ѧ��:"<<endl;
			theStudent[i].Show();
		}
		else
			cout<<"ѧ��Ϊ["<<strStuNo<<"]��ѧ��û���ҵ�!"<<endl;
	}
	void ShowAll()
	{
		cout<<"���:"<<strNO<<",�༶����"<<nNum<<endl;
		for(int i=0;i<nNum;i++)
		{
			theStudent[i].Show();
			cout<<endl;
		}
	}
};
int main()
{
	CClass theClass("210501");
	CStudent one,two,three;
	CCourse cc;

	// For debug
	int count = 0;
	cout << "#" << count++ << endl;

	one.SetStudentInfo("LiMing","21050101",18);
	cc.SetCourseInfo("C++�������",3.5,80);
	one.Add(cc);
	cc.SetCourseInfo("���ݽṹ",3,81);
	one.Add(cc);
	cc.SetCourseInfo("�����������",2,85);
	one.Add(cc);

	// For debug
	cout << "#" << count++ << endl;
	cout << "nNum: " << one.nNum
		 << "nSize: " << one.nSize
		 << endl;
	theClass.Add(one);

	// For debug
	cout << "#" << count++ << endl;

	two.SetStudentInfo("WangFang","21050102",18,'W');
	cc.SetCourseInfo("C++�������",3.5,70);
	two.Add(cc);
	cc.SetCourseInfo("���ݽṹ",3,78);
	two.Add(cc);
	cc.SetCourseInfo("�����������",2,84);
	two.Add(cc);
	theClass.Add(two);

	// For debug
	cout << "#" << count++ << endl;

	three.SetStudentInfo("YangYang","21050103",19);;
	cc.SetCourseInfo("C++�������",3.5,81);
	three.Add(cc);
	cc.SetCourseInfo("���ݽṹ",3,75);
	three.Add(cc);
	cc.SetCourseInfo("�����������",2,84);
	theClass.Add(three);

	theClass.ShowAll();
	theClass.Seek("21050102");
	return 0;
}
