# ifndef  STUDENTMIS_H
# define  STUDENTMIS_H
#define SUCCESS 0  
#define FAILURE 1

const int W_NUMBER=10;          //各个字段的宽度
const int W_NAME=10;
const int W_AGE=3;
const int W_SEX=2;
const int W_DORM=3;
const int W_CLASS=2;
const int W_SCORE=4;
const int W_PRINT=5;            //打印时各字段之间的间隔

//定义学生类
class  Student
{
    //链表结点的定义
private:
    unsigned long ulCount;          //链表中结点的个数
    struct StudentNode
    {
        StudentNode *pPrev;          //当前结点的前驱结点指针
        StudentNode *pNext;          //当前结点的后继结点指针
        unsigned long ulNumber;      //学号
        char   cName[W_NAME];        //姓名
        unsigned int    nAge;        //年龄
        char   cSex[W_SEX];          //性别
        char   cDorm[W_DORM];        //宿舍
        char   cClass[W_CLASS];      //班级
        double  fScore;               //综合成绩
    };
    
//链表相关的公共数据成员及方法
public:
    StudentNode *pHead;              //链表的头指针    
    StudentNode *pTail;              //链表的尾指针
    StudentNode *pCurrent;           //链表的当前结点指针
    Student();                       //构造函数
    ~Student();
    void   InsertAfter(void);        //在当前结点的后面插入新结点
    int    Delete(void);             //删除指定的学生档案
    void   Sort(void);               //对链表按照选定的方式排序
    template <class T>                 //将链表冒泡排序,SelType为排序字段的数据类型cSel为排序依据,cDirection：0 升序,1 降序
        int    SortBubble(T SelType,int iSel,int iDirection);
    void   QuerySimp(void);          //单项查询单项查询,查询的主关键字的记录,结果唯一
    void   QueryComb(void);          //组合查询
    void   GoTop(void);              //将头结点设为当前结点
    void   GoBottom(void);           //将尾结点设为当前结点
    int    Print(void);              //打印全部学生档案,失败返回FAILURE，成功返回SUCCESS
    int    PrintCurrent(int iMethod);//打印当前结点,iMethod选择打印方式,列表 0,详细 1,失败返回FAILURE，成功返回SUCCESS
    void   Total(void);              //资料统计
    void   Import(void);             //导入
    void   Export(void);             //导出
    void   Clear(void);              //清空数据库
    unsigned long GetCount();        //取得结点总数
};

char * GetSubStr(char *cSourceStr,int iStartPos,int iSubLen);
# endif



学生挡案管理系统原代码头文件
# ifndef  XSZL1_H
# define  XSZL1_H

# include <iostream.h>
#include <iomanip.h>
class  XSZL
{
protected:
        struct XSZLJD
        {
            XSZLJD *prev;
            XSZLJD *next;
            void   *dataptr;
            unsigned long XH;
            char   XM[20];
            int    NL;
            char   XB[10];
            char   SS[20];
            char   BJ[20];
            float  ZHCJ;
        };
public:
        XSZLJD *head;    
        XSZLJD *tail;
        XSZLJD *current;
        XSZL();
        insert();
        int    delet();
        void   sequence();
        void   search();
        void   gotohead();
        void   gototail();
        void   print();
        void   open();
        void   out();
        friend ostream &operator<<(ostream &output,const XSZL::XSZLJD *s)
        {
        output<<s->XH<<"   ";
        int i=0;
        while(s->XM[i]!=null)
        {
        output<<s->XM[i];
        i=i+1;
        }
        output<<"   "<<s->NL<<"   "<<s->XB<<"   "<<s->SS<<"   "<<s->BJ<<"   "<<s->ZHCJ<<endl;
        return output;
        }
        void   empty();
           unsigned long getcount()
        {
            return count;
        }
private:
        unsigned long count;

};

# endif
