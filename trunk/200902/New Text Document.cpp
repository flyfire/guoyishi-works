#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include "studentmis.h"

//*********************以下为学生类的实现代码***********************************
Student::Student()
{  //构造函数
    ulCount=0;
    pHead=pTail=pCurrent=NULL;
}
Student::~Student()
{  //析构函数   
}

//-------------------------------------------------------------------------------
void Student::InsertAfter(void)//插入一条学生记录，新结点插在当前结点之后
{
    //输入学生记录
    StudentNode *pStuInfo;
    pStuInfo=new struct StudentNode;
    cout<<"请输入学生档案信息:"<<endl;
    //包括:学号,姓名,年龄,性别,宿舍,班级及综合成绩
    
    cout<<"学号(10位以内的数字):";
    cin>>pStuInfo->ulNumber;
    
    cout<<"姓名(最多"<<W_NAME<<"个字母,"<<W_NAME/2<<"个汉字):";
    cin>>pStuInfo->cName;

    cout<<"年龄(0－100之间):";
    do
    {
        cin>>pStuInfo->nAge;
        if (pStuInfo->nAge<0||pStuInfo->nAge>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";

    } while (pStuInfo->nAge<0||pStuInfo->nAge>100);
    
    cout<<"性别(m:男 f:女):";
    cout<<"如果是(男)请输入:m;如果是(女)请输入:f::";
    cin>>pStuInfo->cSex;
        
    cout<<"宿舍("<<W_DORM<<"位数字):";
    cin>>pStuInfo->cDorm;
    
    cout<<"班级("<<W_CLASS<<"位数字):";
    cin>>pStuInfo->cClass;

    cout<<"综合成绩(3位以内的数字):";
    do
    {
        cin>>pStuInfo->fScore;
        if (pStuInfo->fScore<0||pStuInfo->fScore>100)
            cout<<"成绩必须介于0和100之间!,请重新输入:";
    } while (pStuInfo->fScore<0||pStuInfo->fScore>100);
    
    
    //初始化指针关系
    pStuInfo->pPrev=NULL;              //设置前驱
    pStuInfo->pNext=NULL;              //设置后继
    
    //链表为空的情况
    if(pHead==NULL)
    {
        cout<<"学生档案数据库目前为空!"<<endl;
        pHead=pTail=pCurrent=pStuInfo;
    }
    else
    {     
        //链表不为空，且当前结点在链表的尾部，则插入在链表的尾部
        if(pCurrent==pTail)
        {
            pStuInfo->pPrev=pCurrent;
            pStuInfo->pNext=NULL;
            pCurrent->pNext=pStuInfo;
            pTail=pCurrent=pStuInfo;
        }
        else
        {   //链表不为空，且当前结点在链表的中间，插入在当前结点之后
            pStuInfo->pPrev=pCurrent;
            pStuInfo->pNext=pCurrent->pNext;
            pCurrent->pNext->pPrev=pStuInfo;
            pCurrent->pNext=pStuInfo;
        }
    }
    ulCount++;
    cout<<"新插入的学生数据如下:"<<endl;
    PrintCurrent(2);
}

//-------------------------------------------------------------------------------
int Student::Delete()//可以根据学号或姓名删除一个学生档案数据
{
    StudentNode *pNodeToDel; //待删除结点的指针
    char cSele;                 //用于选择以何种方式删除数据
    unsigned long ulNumberToDel;
    char cNameToDel[20];
    if(pHead==NULL)
    {
        cout<<"无学生档案,删除操作无法进行!"<<endl;
        return FAILURE;
    }
    
       cout<<"选择删除依据(1:学号 2:姓名 0:返回):";
    do
    {
        cin>>cSele;
    } while (cSele!='0'&&cSele!='1'&&cSele!='2');
    if (cSele=='0') return FAILURE;
    if (cSele=='1')
    {
        cout<<"请输入待删除学生的学号:";
        cin>>ulNumberToDel;
    }
    else
        if (cSele=='2')
        {
            cout<<"请输入待删除学生的姓名:";
            cin>>cNameToDel;
        }
        
    pNodeToDel=new struct StudentNode;    
    pNodeToDel=pHead;
    int iFindFlag; //查找成功，赋值SUCESS，失败赋值FAILURE
    iFindFlag=FAILURE;
    while(pNodeToDel!=NULL)
    {
        if (cSele=='2')
        {
            if(!strcmp(pNodeToDel->cName,cNameToDel))
            {
                iFindFlag=SUCCESS;
                break;
            }
        }
        else
            if (cSele=='1')
            {
                if(pNodeToDel->ulNumber==ulNumberToDel)
                {
                    iFindFlag=SUCCESS;
                    break;
                }
            }
        pNodeToDel=pNodeToDel->pNext;
    }
    if (iFindFlag==FAILURE)
    {
        cout<<"没有您要删除的学生档案!"<<endl;
        return FAILURE;
    }
    
    if(pNodeToDel==pCurrent)
    {
        if (pCurrent!=pHead)
        {
            pCurrent->pPrev->pNext=pNodeToDel->pNext;
        }
        pCurrent=pNodeToDel->pNext;
    }
    if(pNodeToDel->pPrev==NULL)
    {
        pHead=pNodeToDel->pNext;
        if(pHead!=NULL)
            pHead->pPrev=NULL;
        if(pNodeToDel->pNext==NULL)
            pTail=NULL;
    }
    else
    {
        pNodeToDel->pPrev->pNext=pNodeToDel->pNext;
        if(pNodeToDel->pNext==NULL)
            pTail=pNodeToDel->pPrev;
        else
            pNodeToDel->pNext->pPrev=pNodeToDel->pPrev;
    }
    delete pNodeToDel;
    ulCount--;
    cout<<"删除成功!"<<endl;
    return SUCCESS;
}

//-------------------------------------------------------------------------------
void Student::Sort() //对链表按照选定的方式排序
{
    int iSel,iOrder;
    char *cOrderField,*cOrderMethod;
    if(pHead==NULL)
    {
        cout<<"空的学生数据库,无法排序!"<<endl;
        return;
    }
    cout<<"选择排序字段(1:按学号 2:按年龄 3:按综合成绩 0:返回):";
    do
    {
        cin>>iSel;
    } while (iSel!=0&&iSel!=1&&iSel!=2&&iSel!=3);
    if (iSel==0) return;
    cout<<"选择排列顺序(1:升序 2:降序):";
    do
    {
        cin>>iOrder;
    } while (iOrder!=1&&iOrder!=2);
    switch (iSel)
    {
    case 1:
        SortBubble(1l,iSel,iOrder);
        cOrderField="按学号";
        break;
    case 2:
        SortBubble(1,iSel,iOrder);
        cOrderField="按年龄";
        break;
    case 3:
        SortBubble(1.0,iSel,iOrder);
        cOrderField="按综合成绩";
        break;
    }
    cOrderMethod="升序";
    if (iOrder==2)
    {
        cOrderMethod="降序";
    }
    cout<<cOrderField<<cOrderMethod<<"排序结果为："<<endl;
    Print();
}
//---------------------------------------------------------------------------
template <class T>
int Student::SortBubble(T SelType,int  iSel,int iDirection)
{
    StudentNode *pNode,*pNodeNext;
    T a,b;
    bool bTmp; 
    for(unsigned long i=0;i<ulCount;i++)
    {
        pNode=pHead;
        while(pNode->pNext!=NULL)
        {
            switch (iSel)
            {
            case 1:
                a=(T)pNode->ulNumber;
                b=(T)pNode->pNext->ulNumber;
                break;
            case 2:
                a=(T)pNode->nAge;
                b=(T)pNode->pNext->nAge;
                break;
            case 3:
                a=(T)pNode->fScore;
                b=(T)pNode->pNext->fScore;
                break;
            }
            bTmp=(iDirection==1?a>b:a<b);
            if(bTmp)
            {
                pNodeNext=pNode->pNext;
                if(pNode==pCurrent)
                    pCurrent=pNode->pNext;
                if(pNode->pPrev==NULL)
                {
                    pHead=pNode->pNext;
                    if(pHead!=NULL)
                        pHead->pPrev=NULL;
                    if(pNode->pNext==NULL)
                        pTail=NULL;
                }
                else
                {
                    pNode->pPrev->pNext=pNode->pNext;
                    if(pNode->pNext==NULL)
                        pTail=pNode->pPrev;
                    else
                        pNode->pNext->pPrev=pNode->pPrev;
                }
                pNode->pNext=pNodeNext->pNext;
                if(pNode->pNext!=NULL)
                {
                    pNode->pPrev=pNodeNext;
                    pNodeNext->pNext=pNode;
                    pNode->pNext->pPrev=pNode;
                }
                else
                {
                    pNodeNext->pNext=pNode;
                }
            }
            else
                pNode=pNode->pNext;
        }
        pTail=pNode;
    }
    return SUCCESS;
}
//-------------------------------------------------------------------------------
void Student::GoTop()
{
    pCurrent=pHead;
}

//-------------------------------------------------------------------------------
void Student::GoBottom()
{
    pCurrent=pTail;
}

//-------------------------------------------------------------------------------
int Student::Print()
{ 
    unsigned int nLoop;
    int iMethod;
    GoTop();
    nLoop=1;
    iMethod=0;
    if(pHead==NULL)
    {
        cout<<"学生档案数据库无数据可打印!"<<endl;
        return FAILURE;
    }

    cout<<"1:列表打印 2:详细打印 0:返回:";
    do
    {
        cin>>iMethod;
    } while (iMethod<0||iMethod>2);
    if (iMethod==0) return 0;
    if (iMethod==1)
    {
        cout<<"                             学生档案列表                                 "<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<setw(W_NUMBER+W_PRINT)<<"学号"<<setw(W_NAME+W_PRINT)<<"姓名";
        cout<<setw(W_AGE+W_PRINT)<<"年龄"<<setw(W_SEX+W_PRINT)<<"性别";
        cout<<setw(W_DORM+W_PRINT)<<"宿舍"<<setw(W_CLASS+W_PRINT)<<"班级";
        cout<<setw(W_SCORE+W_PRINT)<<"综合成绩"<<endl;

    }
    if (iMethod==2)
        cout<<"========================"<<endl;
    while(pCurrent!=NULL)
    {
        //打印当前结点
        PrintCurrent(iMethod);
        if (iMethod==2)
            cout<<"========================"<<endl;
        pCurrent=pCurrent->pNext;
        nLoop++;
    }
    if (iMethod==1)
       cout<<"=========================================================================="<<endl;    
    //把当前结点指到链表开始
    GoTop();
    //执行成功
    return SUCCESS;
}

//-------------------------------------------------------------------------------
int Student::PrintCurrent(int iMethod)
{ 
    
    if(pHead==NULL)
    {
        cout<<"学生档案数据库中无数据可打印!"<<endl;
        return FAILURE;
    }
    if (pCurrent!=NULL)
    {
        //打印当前结点
        if (iMethod==1)
        {
            cout<<setw(W_NUMBER+W_PRINT)<<pCurrent->ulNumber<<setw(W_NAME+W_PRINT)<<pCurrent->cName;
            cout<<setw(W_AGE+W_PRINT)<<pCurrent->nAge;
            if (!strcmp(pCurrent->cSex,"m"))
            {
                cout<<setw(W_SEX+W_PRINT)<<"男";
            }
            else 
                if (!strcmp(pCurrent->cSex,"f"))
                {
                    cout<<setw(W_SEX+W_PRINT)<<"女";
                }
            cout<<setw(W_DORM+W_PRINT)<<pCurrent->cDorm<<setw(W_CLASS+W_PRINT)<<pCurrent->cClass;
            cout<<setw(W_SCORE+W_PRINT)<<pCurrent->fScore<<endl;
        }
        else
            if (iMethod==2)
            {
                cout<<"学号:"<<pCurrent->ulNumber<<endl;
                cout<<"姓名:"<<pCurrent->cName<<endl;
                cout<<"年龄:"<<pCurrent->nAge<<endl;
                if (!strcmp(pCurrent->cSex,"m"))
                {
                    cout<<"性别:男"<<endl;
                }
                else 
                    if (!strcmp(pCurrent->cSex,"f"))
                    {
                        cout<<"性别:女"<<endl;
                    }
                cout<<"宿舍:"<<pCurrent->cDorm<<endl;
                cout<<"班级:"<<pCurrent->cClass<<endl;
                cout<<"综合成绩:"<<pCurrent->fScore<<endl;
            }
    }
    //执行成功
    return SUCCESS;
}

//-------------------------------------------------------------------------------
void Student::Clear()
{
    StudentNode *pTmp,*pTmpNext;
    pTmp=new struct StudentNode;
    pTmpNext=new struct StudentNode;
    pTmp=pHead;
    if(pTmp==NULL)
    {
        cout<<"学生档案库已经为空!"<<endl;
        return;
    }
    while(pTmp!=NULL)
    {
        pTmpNext=pTmp->pNext;
        delete pTmp;
        pTmp=pTmpNext;
    }
    pHead=pTail=pCurrent=NULL;
    ulCount=0;
    cout<<"学生档案库已经清空!"<<endl;
}

//-------------------------------------------------------------------------------------
unsigned long Student::GetCount()
{
    return ulCount;
}

//-------------------------------------------------------------------------------------
void Student::QuerySimp() //单项查询,查询的主关键字的记录,结果唯一
{
    StudentNode *pNodeToQry; //待查询结点的指针
    int iSele;                 //用于选择查询关键字
    unsigned long ulNumberToQry;
    char cNameToQry[W_NAME],cSexToQry[W_SEX],cClassToQry[W_CLASS],cDormToQry[W_DORM];
    unsigned int nAgeToQry;
    float fScoreToQry;
    if(pHead==NULL)
    {
        cout<<"无学生档案,查询无法进行!"<<endl;
        return;
    }
    
       cout<<"选择单项查询依据(1:学号 2:姓名 3:年龄 4:性别 5:宿舍 6:班级 7:综合成绩 0:返回):";
    do
    {
        cin>>iSele;
    } while (iSele<0||iSele>7);
    switch (iSele)
    {
    case 0:
        return;
    case 1:
        cout<<"请输入查询学生的学号:";
        cin>>ulNumberToQry;
        break;
    case 2:
        cout<<"请输入查询学生的姓名:";
        cin>>cNameToQry;
        break;
    case 3:
        cout<<"请输入查询学生的年龄:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";

        } while (nAgeToQry<0||nAgeToQry>100);
        break;
    case 4:
        cout<<"请输入查询学生的性别:";
        cout<<"如果是(男)请输入:m;如果是(女)请输入:f::";
        cin>>cSexToQry;
        break;
    case 5:
        cout<<"请输入查询学生的宿舍号:";
        cin>>cDormToQry;
        break;
    case 6:
        cout<<"请输入查询学生的班级号:";
        cin>>cClassToQry;
        break;
    case 7:
        cout<<"请输入查询学生的综合成绩:";
        do
        {
        cin>>fScoreToQry;
        if (fScoreToQry<0||fScoreToQry>100)
            cout<<"成绩必须介于0和100之间!重新输入:";
        } while (fScoreToQry<0||fScoreToQry>100);
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //查找成功，赋值SUCESS，失败赋值FAILURE
    int iCount;
    iCount=0;
    iFindFlag=FAILURE;
    while(pNodeToQry!=NULL)
    {
        switch (iSele)
        {
        case 1:
            if(pNodeToQry->ulNumber==ulNumberToQry)
              iFindFlag=SUCCESS;
            break;
        case 2:
            if(!strcmp(pNodeToQry->cName,cNameToQry))
               iFindFlag=SUCCESS;
            break;
         case 3:
            if(pNodeToQry->nAge==nAgeToQry)
               iFindFlag=SUCCESS;
            break;
        case 4:
            if(!strcmp(pNodeToQry->cSex,cSexToQry))
               iFindFlag=SUCCESS;
            break;
        case 5:
            if(!strcmp(pNodeToQry->cDorm,cDormToQry))
               iFindFlag=SUCCESS;
            break;
        case 6:
            if(!strcmp(pNodeToQry->cClass,cClassToQry))
               iFindFlag=SUCCESS;
            break;
        case 7:
            if(pNodeToQry->fScore==fScoreToQry)
               iFindFlag=SUCCESS;
            break;
        }
        if (iFindFlag==SUCCESS)
        {
            iCount++;
            if (iCount==1)
            {
               cout<<"查询结果为:"<<endl;
               cout<<"-------------------------"<<endl;
            }
            pCurrent=pNodeToQry;
            PrintCurrent(2);
            cout<<"-------------------------"<<endl;
        }
        iFindFlag=FAILURE;
        pNodeToQry=pNodeToQry->pNext;
    }

    if (iCount==0)
        cout<<"没有您要查询的学生档案!"<<endl;
    else
        cout<<"共查询到"<<iCount<<"条学生档案"<<endl;

}

//-------------------------------------------------------------------------------------
void Student::QueryComb() //组合查询
{
    StudentNode *pNodeToQry; //待查询结点的指针
    int iSele;                 //用于选择查询关键字
    char cSexToQry[W_SEX],cClassToQry[W_CLASS];
    unsigned int nAgeToQry;
    float fScoreToQry;
    if(pHead==NULL)
    {
        cout<<"无学生档案,查询无法进行!"<<endl;
        return;
    }
    
       cout<<"选择组合查询依据(1:年龄+性别 2:年龄+班级 3:性别+班级 4:班级+综合成绩 0:返回):";
    do
    {
        cin>>iSele;
    } while (iSele<0||iSele>4);
    switch (iSele)
    {
    case 0:
        return;
    case 1:
        cout<<"请输入查询学生的年龄:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";

        } while (nAgeToQry<0||nAgeToQry>100);
        cout<<"请输入查询学生的性别:";
        cin>>cSexToQry;
        break;
    case 2:
        cout<<"请输入查询学生的年龄:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";

        } while (nAgeToQry<0||nAgeToQry>100);
        cout<<"请输入查询学生的班级:";
        cin>>cClassToQry;
        break;
    case 3:
        cout<<"请输入查询学生的性别:";
        cin>>cSexToQry;
        cout<<"请输入查询学生的班级:";
        cin>>cClassToQry;
        break;
    case 4:
        cout<<"请输入查询学生的班级:";
        cin>>cClassToQry;
        cout<<"请输入查询学生的综合成绩:";
        do
        {
        cin>>fScoreToQry;
        if (fScoreToQry<0||fScoreToQry>100)
            cout<<"成绩必须介于0和100之间!重新输入:";
        } while (fScoreToQry<0||fScoreToQry>100);
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //查找成功，赋值SUCESS，失败赋值FAILURE
    int iCount;
    iCount=0;
    iFindFlag=FAILURE;
    while(pNodeToQry!=NULL)
    {
        switch (iSele)
        {
        case 1:
            if(pNodeToQry->nAge==nAgeToQry&&!strcmp(pNodeToQry->cSex,cSexToQry))
              iFindFlag=SUCCESS;
            break;
        case 2:
            if(pNodeToQry->nAge==nAgeToQry&&!strcmp(pNodeToQry->cClass,cClassToQry))
               iFindFlag=SUCCESS;
            break;
         case 3:
            if(!strcmp(pNodeToQry->cSex,cSexToQry)&&!strcmp(pNodeToQry->cClass,cClassToQry))
               iFindFlag=SUCCESS;
            break;
        case 4:
            if(!strcmp(pNodeToQry->cClass,cClassToQry)&&pNodeToQry->fScore==fScoreToQry)
               iFindFlag=SUCCESS;
            break;
        }
        if (iFindFlag==SUCCESS)
        {
            iCount++;
            if (iCount==1)
            {
               cout<<"查询结果为:"<<endl;
               cout<<"-------------------------"<<endl;
            }
            pCurrent=pNodeToQry;
            PrintCurrent(2);
            cout<<"-------------------------"<<endl;
        }
        iFindFlag=FAILURE;
        pNodeToQry=pNodeToQry->pNext;
    }

    if (iCount==0)
        cout<<"没有您要查询的学生档案!"<<endl;
    else
        cout<<"共查询到"<<iCount<<"条学生档案"<<endl;
}

//-------------------------------------------------------------------------------------
void Student::Total(void) //资料统计
{
    StudentNode *pNodeToQry; //待查询结点的指针
    int iSele;                 //用于选择查询关键字
    unsigned int nAgeToQryH,nAgeToQryL;
    float fScoreToQryH,fScoreToQryL;
    char cClassToQry[W_CLASS];
    unsigned long ulTotal;
    if(pHead==NULL)
    {
        cout<<"无学生档案,统计无法进行!"<<endl;
        return;
    }
    
       cout<<"选择统计依据(1:总人数 2:班级人数 3:年龄 4:综合成绩 0:返回):";
    do
    {
        cin>>iSele;
    } while (iSele<0||iSele>4);
    switch (iSele)
    {
    case 0:
        return;
    case 1:
        break;
    case 2:
        cout<<"请输入要统计人数的班级:";
        cin>>cClassToQry;
        break;
    case 3:
        cout<<"请输入要统计的年龄下限:";
        do
        {
        cin>>nAgeToQryL;
        if (nAgeToQryL<0||nAgeToQryL>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";

        } while (nAgeToQryL<0||nAgeToQryL>100);
        cout<<"请输入要统计的年龄上限:";
        do
        {
        cin>>nAgeToQryH;
        if (nAgeToQryH<0||nAgeToQryH>100)
            cout<<"年龄必须介于0和100之间!,请重新输入:";
        } while (nAgeToQryH<0||nAgeToQryH>100);
        if (nAgeToQryL>nAgeToQryH)
        {
            cout<<"下限必须小于上限!"<<endl;
            return;
        }
        break;
    case 4:
        cout<<"请输入要统计的综合成绩下限:";
        do
        {
        cin>>fScoreToQryL;
        if (fScoreToQryL<0||fScoreToQryL>100)
            cout<<"成绩必须介于0和100之间!,请重新输入:";
        } while (fScoreToQryL<0||fScoreToQryL>100);
        cout<<"请输入要统计的综合成绩上限:";
        do
        {
        cin>>fScoreToQryH;
        if (fScoreToQryH<0||fScoreToQryH>100)
            cout<<"成绩必须介于0和100之间!重新输入:";
        } while (fScoreToQryH<0||fScoreToQryH>100);
        if (fScoreToQryL>fScoreToQryH)
        {
            cout<<"下限必须小于上限!"<<endl;
            return;
        }
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //查找成功，赋值SUCESS，失败赋值FAILURE
    ulTotal=0;
    iFindFlag=FAILURE;
    while(pNodeToQry!=NULL)
    {
        switch (iSele)
        {
        case 2:
            if(!strcmp(pNodeToQry->cClass,cClassToQry))
               iFindFlag=SUCCESS;
            break;
        case 3:
            if(pNodeToQry->nAge>=nAgeToQryL&&pNodeToQry->nAge<=nAgeToQryH)
               iFindFlag=SUCCESS;
            break;
         case 4:
            if(pNodeToQry->fScore>=fScoreToQryL&&pNodeToQry->fScore<=fScoreToQryH)
               iFindFlag=SUCCESS;
            break;
        }
        if (iFindFlag==SUCCESS)
           ulTotal++;
        iFindFlag=FAILURE;
        pNodeToQry=pNodeToQry->pNext;
    }
       switch (iSele)
    {
    case 1:
        cout<<"学生档案中总学生人数为"<<GetCount()<<"个."<<endl;
        break;
    case 2:
        cout<<"学生档案中"<<cClassToQry<<"班的人数为"<<ulTotal<<"个."<<endl;
        break;
    case 3:
        cout<<"学生档案中学生年龄介于"<<nAgeToQryL<<"和"<<nAgeToQryH<<"之间的人数为"<<ulTotal<<"个."<<endl;
        break;
    case 4:
        cout<<"学生档案中学生综合成绩介于"<<fScoreToQryL<<"和"<<fScoreToQryH<<"之间的人数为"<<ulTotal<<"个."<<endl;
        break;
    }
}

//-------------------------------------------------------------------------------
void Student::Import(void)
{
    ifstream fsStuDB;
    char cFileToImport[50];
    char cInStr[80];
    int iSel;    
    // 打开文件
    if (pHead!=NULL)
    {
        cout<<"如果导入新的数据,原有的数据都将被清除!为防数据丢失请先将数据导出."<<endl;
        cout<<"1:继续 0:返回";
        do
        {
            cin>>iSel;
        } while (iSel!=0&&iSel!=1);
        if (iSel==0) return;
    }
    cout<<"请输入存放学生档案的文件名(*.txt):";
    cin>>cFileToImport;
    fsStuDB.open(cFileToImport,ios::in|ios::nocreate);
    if (!fsStuDB.is_open())
    {
        cout<<"文件不能被打开!无法导入数据."<<endl;
        return;
    }
    //重新初始化链表
    ulCount=0;
    pHead=pTail=pCurrent=NULL;

    streampos here=fsStuDB.tellg();
    //读入文件内容
    while (!fsStuDB.eof())
    {   //每行都是一条学生档案,作为链表中的一个结点
        fsStuDB.seekg(here);
        fsStuDB.getline(cInStr,80);
        if (cInStr[0]=='\0') continue;
        here=fsStuDB.tellg();
        ulCount++;
        StudentNode * pNewNode;
        pNewNode=new struct StudentNode;
        pNewNode->pPrev=NULL;
        pNewNode->pNext=NULL;
        pNewNode->ulNumber=atol(GetSubStr(cInStr,0,W_NUMBER));
        memcpy(pNewNode->cName,GetSubStr(cInStr,W_NUMBER+1,W_NAME),W_NAME);
        pNewNode->nAge=atoi(GetSubStr(cInStr,W_NUMBER+W_NAME+1,W_AGE));
        memcpy(pNewNode->cSex,GetSubStr(cInStr,W_NUMBER+W_NAME+W_AGE+1,W_SEX),W_SEX);
        memcpy(pNewNode->cDorm,GetSubStr(cInStr,W_NUMBER+W_NAME+W_AGE+W_SEX+1,W_DORM),W_DORM);
        memcpy(pNewNode->cClass,GetSubStr(cInStr,W_NUMBER+W_NAME+W_AGE+W_SEX+W_DORM+1,W_CLASS),W_CLASS);
        pNewNode->fScore=atof(GetSubStr(cInStr,W_NUMBER+W_NAME+W_AGE+W_SEX+W_DORM+W_CLASS+1,W_SCORE));
        if(pHead==NULL)
        {
            pHead=pTail=pCurrent=pNewNode;
        }
        else
        {
            if(pCurrent==pTail)
            {
                pNewNode->pPrev=pCurrent;
                pNewNode->pNext=NULL;
                pCurrent->pNext=pNewNode;
                pTail=pCurrent=pNewNode;
            }
            else
            {
                pNewNode->pPrev=pCurrent;
                pNewNode->pNext=pCurrent->pNext;
                pCurrent->pNext->pPrev=pNewNode;
                pCurrent->pNext=pNewNode;
            }
        } //end if 
    } //end while
    
    fsStuDB.close();

    cout<<"导入成功!文件中的学生档案总计"<<ulCount<<"个."<<endl;
}

//-------------------------------------------------------------------------------
void Student::Export()
{
    ofstream fsStuDB;
    char cFileToExport[50]; //输出文件的名字
    cout<<"警告:如果您输入的文件已存在,则会覆盖掉文件中已有的数据!"<<endl;
    cout<<"请输入要导出文件的名称(*.txt):";
    cin>>cFileToExport;
    fsStuDB.open(cFileToExport,ios::out);
    if (!fsStuDB.is_open())
    {
        cout<<"文件不能被打开!无法导出数据"<<endl;
        return;
    }
    //做输出处理
    pCurrent=pHead;
    while(pCurrent!=NULL)
    {
        fsStuDB<<setw(W_NUMBER)<<pCurrent->ulNumber;
        fsStuDB<<setw(W_NAME)<<pCurrent->cName;
        fsStuDB<<setw(W_AGE)<<pCurrent->nAge;
        fsStuDB<<setw(W_SEX)<<pCurrent->cSex;
        fsStuDB<<setw(W_DORM)<<pCurrent->cDorm;
        fsStuDB<<setw(W_CLASS)<<pCurrent->cClass;
        fsStuDB<<setw(W_SCORE)<<pCurrent->fScore<<endl;
        pCurrent=pCurrent->pNext;
        flush(cout);
    }
    fsStuDB.seekp(0); //把文件指针移到文件头
    fsStuDB.close();
    cout<<ulCount<<"条学生档案被导出到文件中."<<endl;
}
//******************************学生类代码完毕******************************************



//*****************************以下是其他全局函数部分***********************************
void ShowTitle(void)
//显示主画面，并提供选项
{
    cout<<"=========================================================================="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=                        学生档案管理系统  Version 1.0                   ="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=========================================================================="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=   设计时间: 2003年12月               设 计 者: ***(修)   ="<<endl; 
    cout<<"=                                                ***(修)   ="<<endl;
    cout<<"=   出品单位: ************                       ***(修)   ="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=========================================================================="<<endl<<endl;
    cout<<"1:插入信息              2:删除信息"<<endl;
    cout<<"3:查    询              4:排    序"<<endl;
    cout<<"5:统    计              6:清空档案"<<endl;
    cout<<"7:导入数据              8:导出数据"<<endl;
    cout<<"9:打    印              0:退出系统"<<endl<<endl;  
}

//-----------------------------------------------------------------------------
char * GetSubStr(char *cSourceStr,int iStartPos,int iSubLen)
{   //最多256个字符
    int iTmp,iTmp1;
    char cReturnStr[256];
    iTmp=iTmp1=0;
    while (cSourceStr[iTmp++]!='\0');
    if (iTmp==0||iTmp<iStartPos) return NULL;
    iTmp=0;
    while (iTmp<iSubLen)
    {
        if (cSourceStr[iTmp+iStartPos]=='\0') break;
        if (cSourceStr[iTmp+iStartPos]==' ') 
        {
            iTmp++;  
            continue;
        }
        cReturnStr[iTmp1++]=cSourceStr[iStartPos+iTmp++];
    }
    cReturnStr[iTmp1]='\0';
    return cReturnStr;
}

//****************************其他全局函数部分完毕***************************

//*****************************以下是主函数部分******************************
#include <iostream.h>
#include <iomanip.h>
#include "studentmis.H"
void main()
{
    int iUserSelect;
    int iQrySel;
    Student student;
    while(1)
    {
        ShowTitle(); //显示主画面，并提供选项
        cout<<"请选择(0-9):";
        do 
        {
            cin>>iUserSelect;
        } while(iUserSelect<0||iUserSelect>9);
        switch(iUserSelect)
        {
        case 1:
            student.InsertAfter();
            break;
        case 2:
            student.Delete();
            break;
        case 3:
            cout<<"1:单项查询 2:组合查询 0:返回";
            do
            {
                cin>>iQrySel;
            } while(iQrySel<0||iQrySel>2);
            switch (iQrySel)
            {
            case 0: continue;
            case 1: 
                student.QuerySimp();
                break;
            case 2: 
                student.QueryComb();
                break;
            }
            break;
        case 4:
            student.Sort();
            break;
        case 5:
            student.Total();
            break;
        case 6:
            student.Clear();
            break;
        case 7:
            student.Import();
            break;
        case 8:
            student.Export();
            break;
        case 9:
            student.Print();
            break;
        case 0:
            cout<<"感谢使用本学生档案管理系统,再见!"<<endl;
            return;
        }
    }
}
//***************************主函数部分完毕*************************************
