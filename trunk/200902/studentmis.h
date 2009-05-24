# ifndef  STUDENTMIS_H
# define  STUDENTMIS_H
#define SUCCESS 0  
#define FAILURE 1

const int W_NUMBER=10;          //�����ֶεĿ��
const int W_NAME=10;
const int W_AGE=3;
const int W_SEX=2;
const int W_DORM=3;
const int W_CLASS=2;
const int W_SCORE=4;
const int W_PRINT=5;            //��ӡʱ���ֶ�֮��ļ��

//����ѧ����
class  Student
{
    //������Ķ���
private:
    unsigned long ulCount;          //�����н��ĸ���
    struct StudentNode
    {
        StudentNode *pPrev;          //��ǰ����ǰ�����ָ��
        StudentNode *pNext;          //��ǰ���ĺ�̽��ָ��
        unsigned long ulNumber;      //ѧ��
        char   cName[W_NAME];        //����
        unsigned int    nAge;        //����
        char   cSex[W_SEX];          //�Ա�
        char   cDorm[W_DORM];        //����
        char   cClass[W_CLASS];      //�༶
        double  fScore;               //�ۺϳɼ�
    };
    
//������صĹ������ݳ�Ա������
public:
    StudentNode *pHead;              //�����ͷָ��    
    StudentNode *pTail;              //�����βָ��
    StudentNode *pCurrent;           //����ĵ�ǰ���ָ��
    Student();                       //���캯��
    ~Student();
    void   InsertAfter(void);        //�ڵ�ǰ���ĺ�������½��
    int    Delete(void);             //ɾ��ָ����ѧ������
    void   Sort(void);               //��������ѡ���ķ�ʽ����
    template <class T>                 //������ð������,SelTypeΪ�����ֶε���������cSelΪ��������,cDirection��0 ����,1 ����
        int    SortBubble(T SelType,int iSel,int iDirection);
    void   QuerySimp(void);          //�����ѯ�����ѯ,��ѯ�����ؼ��ֵļ�¼,���Ψһ
    void   QueryComb(void);          //��ϲ�ѯ
    void   GoTop(void);              //��ͷ�����Ϊ��ǰ���
    void   GoBottom(void);           //��β�����Ϊ��ǰ���
    int    Print(void);              //��ӡȫ��ѧ������,ʧ�ܷ���FAILURE���ɹ�����SUCCESS
    int    PrintCurrent(int iMethod);//��ӡ��ǰ���,iMethodѡ���ӡ��ʽ,�б� 0,��ϸ 1,ʧ�ܷ���FAILURE���ɹ�����SUCCESS
    void   Total(void);              //����ͳ��
    void   Import(void);             //����
    void   Export(void);             //����
    void   Clear(void);              //������ݿ�
    unsigned long GetCount();        //ȡ�ý������
};

char * GetSubStr(char *cSourceStr,int iStartPos,int iSubLen);
# endif



ѧ����������ϵͳԭ����ͷ�ļ�
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
