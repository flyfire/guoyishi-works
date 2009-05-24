#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include <iomanip.h>
#include <fstream.h>
#include <stdlib.h>

#include "studentmis.h"

//*********************����Ϊѧ�����ʵ�ִ���***********************************
Student::Student()
{  //���캯��
    ulCount=0;
    pHead=pTail=pCurrent=NULL;
}
Student::~Student()
{  //��������   
}

//-------------------------------------------------------------------------------
void Student::InsertAfter(void)//����һ��ѧ����¼���½����ڵ�ǰ���֮��
{
    //����ѧ����¼
    StudentNode *pStuInfo;
    pStuInfo=new struct StudentNode;
    cout<<"������ѧ��������Ϣ:"<<endl;
    //����:ѧ��,����,����,�Ա�,����,�༶���ۺϳɼ�
    
    cout<<"ѧ��(10λ���ڵ�����):";
    cin>>pStuInfo->ulNumber;
    
    cout<<"����(���"<<W_NAME<<"����ĸ,"<<W_NAME/2<<"������):";
    cin>>pStuInfo->cName;

    cout<<"����(0��100֮��):";
    do
    {
        cin>>pStuInfo->nAge;
        if (pStuInfo->nAge<0||pStuInfo->nAge>100)
            cout<<"����������0��100֮��!,����������:";

    } while (pStuInfo->nAge<0||pStuInfo->nAge>100);
    
    cout<<"�Ա�(m:�� f:Ů):";
    cout<<"�����(��)������:m;�����(Ů)������:f::";
    cin>>pStuInfo->cSex;
        
    cout<<"����("<<W_DORM<<"λ����):";
    cin>>pStuInfo->cDorm;
    
    cout<<"�༶("<<W_CLASS<<"λ����):";
    cin>>pStuInfo->cClass;

    cout<<"�ۺϳɼ�(3λ���ڵ�����):";
    do
    {
        cin>>pStuInfo->fScore;
        if (pStuInfo->fScore<0||pStuInfo->fScore>100)
            cout<<"�ɼ��������0��100֮��!,����������:";
    } while (pStuInfo->fScore<0||pStuInfo->fScore>100);
    
    
    //��ʼ��ָ���ϵ
    pStuInfo->pPrev=NULL;              //����ǰ��
    pStuInfo->pNext=NULL;              //���ú��
    
    //����Ϊ�յ����
    if(pHead==NULL)
    {
        cout<<"ѧ���������ݿ�ĿǰΪ��!"<<endl;
        pHead=pTail=pCurrent=pStuInfo;
    }
    else
    {     
        //����Ϊ�գ��ҵ�ǰ����������β����������������β��
        if(pCurrent==pTail)
        {
            pStuInfo->pPrev=pCurrent;
            pStuInfo->pNext=NULL;
            pCurrent->pNext=pStuInfo;
            pTail=pCurrent=pStuInfo;
        }
        else
        {   //����Ϊ�գ��ҵ�ǰ�����������м䣬�����ڵ�ǰ���֮��
            pStuInfo->pPrev=pCurrent;
            pStuInfo->pNext=pCurrent->pNext;
            pCurrent->pNext->pPrev=pStuInfo;
            pCurrent->pNext=pStuInfo;
        }
    }
    ulCount++;
    cout<<"�²����ѧ����������:"<<endl;
    PrintCurrent(2);
}

//-------------------------------------------------------------------------------
int Student::Delete()//���Ը���ѧ�Ż�����ɾ��һ��ѧ����������
{
    StudentNode *pNodeToDel; //��ɾ������ָ��
    char cSele;                 //����ѡ���Ժ��ַ�ʽɾ������
    unsigned long ulNumberToDel;
    char cNameToDel[20];
    if(pHead==NULL)
    {
        cout<<"��ѧ������,ɾ�������޷�����!"<<endl;
        return FAILURE;
    }
    
       cout<<"ѡ��ɾ������(1:ѧ�� 2:���� 0:����):";
    do
    {
        cin>>cSele;
    } while (cSele!='0'&&cSele!='1'&&cSele!='2');
    if (cSele=='0') return FAILURE;
    if (cSele=='1')
    {
        cout<<"�������ɾ��ѧ����ѧ��:";
        cin>>ulNumberToDel;
    }
    else
        if (cSele=='2')
        {
            cout<<"�������ɾ��ѧ��������:";
            cin>>cNameToDel;
        }
        
    pNodeToDel=new struct StudentNode;    
    pNodeToDel=pHead;
    int iFindFlag; //���ҳɹ�����ֵSUCESS��ʧ�ܸ�ֵFAILURE
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
        cout<<"û����Ҫɾ����ѧ������!"<<endl;
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
    cout<<"ɾ���ɹ�!"<<endl;
    return SUCCESS;
}

//-------------------------------------------------------------------------------
void Student::Sort() //��������ѡ���ķ�ʽ����
{
    int iSel,iOrder;
    char *cOrderField,*cOrderMethod;
    if(pHead==NULL)
    {
        cout<<"�յ�ѧ�����ݿ�,�޷�����!"<<endl;
        return;
    }
    cout<<"ѡ�������ֶ�(1:��ѧ�� 2:������ 3:���ۺϳɼ� 0:����):";
    do
    {
        cin>>iSel;
    } while (iSel!=0&&iSel!=1&&iSel!=2&&iSel!=3);
    if (iSel==0) return;
    cout<<"ѡ������˳��(1:���� 2:����):";
    do
    {
        cin>>iOrder;
    } while (iOrder!=1&&iOrder!=2);
    switch (iSel)
    {
    case 1:
        SortBubble(1l,iSel,iOrder);
        cOrderField="��ѧ��";
        break;
    case 2:
        SortBubble(1,iSel,iOrder);
        cOrderField="������";
        break;
    case 3:
        SortBubble(1.0,iSel,iOrder);
        cOrderField="���ۺϳɼ�";
        break;
    }
    cOrderMethod="����";
    if (iOrder==2)
    {
        cOrderMethod="����";
    }
    cout<<cOrderField<<cOrderMethod<<"������Ϊ��"<<endl;
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
        cout<<"ѧ���������ݿ������ݿɴ�ӡ!"<<endl;
        return FAILURE;
    }

    cout<<"1:�б��ӡ 2:��ϸ��ӡ 0:����:";
    do
    {
        cin>>iMethod;
    } while (iMethod<0||iMethod>2);
    if (iMethod==0) return 0;
    if (iMethod==1)
    {
        cout<<"                             ѧ�������б�                                 "<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<setw(W_NUMBER+W_PRINT)<<"ѧ��"<<setw(W_NAME+W_PRINT)<<"����";
        cout<<setw(W_AGE+W_PRINT)<<"����"<<setw(W_SEX+W_PRINT)<<"�Ա�";
        cout<<setw(W_DORM+W_PRINT)<<"����"<<setw(W_CLASS+W_PRINT)<<"�༶";
        cout<<setw(W_SCORE+W_PRINT)<<"�ۺϳɼ�"<<endl;

    }
    if (iMethod==2)
        cout<<"========================"<<endl;
    while(pCurrent!=NULL)
    {
        //��ӡ��ǰ���
        PrintCurrent(iMethod);
        if (iMethod==2)
            cout<<"========================"<<endl;
        pCurrent=pCurrent->pNext;
        nLoop++;
    }
    if (iMethod==1)
       cout<<"=========================================================================="<<endl;    
    //�ѵ�ǰ���ָ������ʼ
    GoTop();
    //ִ�гɹ�
    return SUCCESS;
}

//-------------------------------------------------------------------------------
int Student::PrintCurrent(int iMethod)
{ 
    
    if(pHead==NULL)
    {
        cout<<"ѧ���������ݿ��������ݿɴ�ӡ!"<<endl;
        return FAILURE;
    }
    if (pCurrent!=NULL)
    {
        //��ӡ��ǰ���
        if (iMethod==1)
        {
            cout<<setw(W_NUMBER+W_PRINT)<<pCurrent->ulNumber<<setw(W_NAME+W_PRINT)<<pCurrent->cName;
            cout<<setw(W_AGE+W_PRINT)<<pCurrent->nAge;
            if (!strcmp(pCurrent->cSex,"m"))
            {
                cout<<setw(W_SEX+W_PRINT)<<"��";
            }
            else 
                if (!strcmp(pCurrent->cSex,"f"))
                {
                    cout<<setw(W_SEX+W_PRINT)<<"Ů";
                }
            cout<<setw(W_DORM+W_PRINT)<<pCurrent->cDorm<<setw(W_CLASS+W_PRINT)<<pCurrent->cClass;
            cout<<setw(W_SCORE+W_PRINT)<<pCurrent->fScore<<endl;
        }
        else
            if (iMethod==2)
            {
                cout<<"ѧ��:"<<pCurrent->ulNumber<<endl;
                cout<<"����:"<<pCurrent->cName<<endl;
                cout<<"����:"<<pCurrent->nAge<<endl;
                if (!strcmp(pCurrent->cSex,"m"))
                {
                    cout<<"�Ա�:��"<<endl;
                }
                else 
                    if (!strcmp(pCurrent->cSex,"f"))
                    {
                        cout<<"�Ա�:Ů"<<endl;
                    }
                cout<<"����:"<<pCurrent->cDorm<<endl;
                cout<<"�༶:"<<pCurrent->cClass<<endl;
                cout<<"�ۺϳɼ�:"<<pCurrent->fScore<<endl;
            }
    }
    //ִ�гɹ�
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
        cout<<"ѧ���������Ѿ�Ϊ��!"<<endl;
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
    cout<<"ѧ���������Ѿ����!"<<endl;
}

//-------------------------------------------------------------------------------------
unsigned long Student::GetCount()
{
    return ulCount;
}

//-------------------------------------------------------------------------------------
void Student::QuerySimp() //�����ѯ,��ѯ�����ؼ��ֵļ�¼,���Ψһ
{
    StudentNode *pNodeToQry; //����ѯ����ָ��
    int iSele;                 //����ѡ���ѯ�ؼ���
    unsigned long ulNumberToQry;
    char cNameToQry[W_NAME],cSexToQry[W_SEX],cClassToQry[W_CLASS],cDormToQry[W_DORM];
    unsigned int nAgeToQry;
    float fScoreToQry;
    if(pHead==NULL)
    {
        cout<<"��ѧ������,��ѯ�޷�����!"<<endl;
        return;
    }
    
       cout<<"ѡ�����ѯ����(1:ѧ�� 2:���� 3:���� 4:�Ա� 5:���� 6:�༶ 7:�ۺϳɼ� 0:����):";
    do
    {
        cin>>iSele;
    } while (iSele<0||iSele>7);
    switch (iSele)
    {
    case 0:
        return;
    case 1:
        cout<<"�������ѯѧ����ѧ��:";
        cin>>ulNumberToQry;
        break;
    case 2:
        cout<<"�������ѯѧ��������:";
        cin>>cNameToQry;
        break;
    case 3:
        cout<<"�������ѯѧ��������:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"����������0��100֮��!,����������:";

        } while (nAgeToQry<0||nAgeToQry>100);
        break;
    case 4:
        cout<<"�������ѯѧ�����Ա�:";
        cout<<"�����(��)������:m;�����(Ů)������:f::";
        cin>>cSexToQry;
        break;
    case 5:
        cout<<"�������ѯѧ���������:";
        cin>>cDormToQry;
        break;
    case 6:
        cout<<"�������ѯѧ���İ༶��:";
        cin>>cClassToQry;
        break;
    case 7:
        cout<<"�������ѯѧ�����ۺϳɼ�:";
        do
        {
        cin>>fScoreToQry;
        if (fScoreToQry<0||fScoreToQry>100)
            cout<<"�ɼ��������0��100֮��!��������:";
        } while (fScoreToQry<0||fScoreToQry>100);
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //���ҳɹ�����ֵSUCESS��ʧ�ܸ�ֵFAILURE
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
               cout<<"��ѯ���Ϊ:"<<endl;
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
        cout<<"û����Ҫ��ѯ��ѧ������!"<<endl;
    else
        cout<<"����ѯ��"<<iCount<<"��ѧ������"<<endl;

}

//-------------------------------------------------------------------------------------
void Student::QueryComb() //��ϲ�ѯ
{
    StudentNode *pNodeToQry; //����ѯ����ָ��
    int iSele;                 //����ѡ���ѯ�ؼ���
    char cSexToQry[W_SEX],cClassToQry[W_CLASS];
    unsigned int nAgeToQry;
    float fScoreToQry;
    if(pHead==NULL)
    {
        cout<<"��ѧ������,��ѯ�޷�����!"<<endl;
        return;
    }
    
       cout<<"ѡ����ϲ�ѯ����(1:����+�Ա� 2:����+�༶ 3:�Ա�+�༶ 4:�༶+�ۺϳɼ� 0:����):";
    do
    {
        cin>>iSele;
    } while (iSele<0||iSele>4);
    switch (iSele)
    {
    case 0:
        return;
    case 1:
        cout<<"�������ѯѧ��������:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"����������0��100֮��!,����������:";

        } while (nAgeToQry<0||nAgeToQry>100);
        cout<<"�������ѯѧ�����Ա�:";
        cin>>cSexToQry;
        break;
    case 2:
        cout<<"�������ѯѧ��������:";
        do
        {
        cin>>nAgeToQry;
        if (nAgeToQry<0||nAgeToQry>100)
            cout<<"����������0��100֮��!,����������:";

        } while (nAgeToQry<0||nAgeToQry>100);
        cout<<"�������ѯѧ���İ༶:";
        cin>>cClassToQry;
        break;
    case 3:
        cout<<"�������ѯѧ�����Ա�:";
        cin>>cSexToQry;
        cout<<"�������ѯѧ���İ༶:";
        cin>>cClassToQry;
        break;
    case 4:
        cout<<"�������ѯѧ���İ༶:";
        cin>>cClassToQry;
        cout<<"�������ѯѧ�����ۺϳɼ�:";
        do
        {
        cin>>fScoreToQry;
        if (fScoreToQry<0||fScoreToQry>100)
            cout<<"�ɼ��������0��100֮��!��������:";
        } while (fScoreToQry<0||fScoreToQry>100);
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //���ҳɹ�����ֵSUCESS��ʧ�ܸ�ֵFAILURE
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
               cout<<"��ѯ���Ϊ:"<<endl;
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
        cout<<"û����Ҫ��ѯ��ѧ������!"<<endl;
    else
        cout<<"����ѯ��"<<iCount<<"��ѧ������"<<endl;
}

//-------------------------------------------------------------------------------------
void Student::Total(void) //����ͳ��
{
    StudentNode *pNodeToQry; //����ѯ����ָ��
    int iSele;                 //����ѡ���ѯ�ؼ���
    unsigned int nAgeToQryH,nAgeToQryL;
    float fScoreToQryH,fScoreToQryL;
    char cClassToQry[W_CLASS];
    unsigned long ulTotal;
    if(pHead==NULL)
    {
        cout<<"��ѧ������,ͳ���޷�����!"<<endl;
        return;
    }
    
       cout<<"ѡ��ͳ������(1:������ 2:�༶���� 3:���� 4:�ۺϳɼ� 0:����):";
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
        cout<<"������Ҫͳ�������İ༶:";
        cin>>cClassToQry;
        break;
    case 3:
        cout<<"������Ҫͳ�Ƶ���������:";
        do
        {
        cin>>nAgeToQryL;
        if (nAgeToQryL<0||nAgeToQryL>100)
            cout<<"����������0��100֮��!,����������:";

        } while (nAgeToQryL<0||nAgeToQryL>100);
        cout<<"������Ҫͳ�Ƶ���������:";
        do
        {
        cin>>nAgeToQryH;
        if (nAgeToQryH<0||nAgeToQryH>100)
            cout<<"����������0��100֮��!,����������:";
        } while (nAgeToQryH<0||nAgeToQryH>100);
        if (nAgeToQryL>nAgeToQryH)
        {
            cout<<"���ޱ���С������!"<<endl;
            return;
        }
        break;
    case 4:
        cout<<"������Ҫͳ�Ƶ��ۺϳɼ�����:";
        do
        {
        cin>>fScoreToQryL;
        if (fScoreToQryL<0||fScoreToQryL>100)
            cout<<"�ɼ��������0��100֮��!,����������:";
        } while (fScoreToQryL<0||fScoreToQryL>100);
        cout<<"������Ҫͳ�Ƶ��ۺϳɼ�����:";
        do
        {
        cin>>fScoreToQryH;
        if (fScoreToQryH<0||fScoreToQryH>100)
            cout<<"�ɼ��������0��100֮��!��������:";
        } while (fScoreToQryH<0||fScoreToQryH>100);
        if (fScoreToQryL>fScoreToQryH)
        {
            cout<<"���ޱ���С������!"<<endl;
            return;
        }
        break;
    }
        
    pNodeToQry=new struct StudentNode;    
    pNodeToQry=pHead;
    int iFindFlag; //���ҳɹ�����ֵSUCESS��ʧ�ܸ�ֵFAILURE
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
        cout<<"ѧ����������ѧ������Ϊ"<<GetCount()<<"��."<<endl;
        break;
    case 2:
        cout<<"ѧ��������"<<cClassToQry<<"�������Ϊ"<<ulTotal<<"��."<<endl;
        break;
    case 3:
        cout<<"ѧ��������ѧ���������"<<nAgeToQryL<<"��"<<nAgeToQryH<<"֮�������Ϊ"<<ulTotal<<"��."<<endl;
        break;
    case 4:
        cout<<"ѧ��������ѧ���ۺϳɼ�����"<<fScoreToQryL<<"��"<<fScoreToQryH<<"֮�������Ϊ"<<ulTotal<<"��."<<endl;
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
    // ���ļ�
    if (pHead!=NULL)
    {
        cout<<"��������µ�����,ԭ�е����ݶ��������!Ϊ�����ݶ�ʧ���Ƚ����ݵ���."<<endl;
        cout<<"1:���� 0:����";
        do
        {
            cin>>iSel;
        } while (iSel!=0&&iSel!=1);
        if (iSel==0) return;
    }
    cout<<"��������ѧ���������ļ���(*.txt):";
    cin>>cFileToImport;
    fsStuDB.open(cFileToImport,ios::in|ios::nocreate);
    if (!fsStuDB.is_open())
    {
        cout<<"�ļ����ܱ���!�޷���������."<<endl;
        return;
    }
    //���³�ʼ������
    ulCount=0;
    pHead=pTail=pCurrent=NULL;

    streampos here=fsStuDB.tellg();
    //�����ļ�����
    while (!fsStuDB.eof())
    {   //ÿ�ж���һ��ѧ������,��Ϊ�����е�һ�����
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

    cout<<"����ɹ�!�ļ��е�ѧ�������ܼ�"<<ulCount<<"��."<<endl;
}

//-------------------------------------------------------------------------------
void Student::Export()
{
    ofstream fsStuDB;
    char cFileToExport[50]; //����ļ�������
    cout<<"����:�����������ļ��Ѵ���,��Ḳ�ǵ��ļ������е�����!"<<endl;
    cout<<"������Ҫ�����ļ�������(*.txt):";
    cin>>cFileToExport;
    fsStuDB.open(cFileToExport,ios::out);
    if (!fsStuDB.is_open())
    {
        cout<<"�ļ����ܱ���!�޷���������"<<endl;
        return;
    }
    //���������
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
    fsStuDB.seekp(0); //���ļ�ָ���Ƶ��ļ�ͷ
    fsStuDB.close();
    cout<<ulCount<<"��ѧ���������������ļ���."<<endl;
}
//******************************ѧ����������******************************************



//*****************************����������ȫ�ֺ�������***********************************
void ShowTitle(void)
//��ʾ�����棬���ṩѡ��
{
    cout<<"=========================================================================="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=                        ѧ����������ϵͳ  Version 1.0                   ="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=========================================================================="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=   ���ʱ��: 2003��12��               �� �� ��: ***(��)   ="<<endl; 
    cout<<"=                                                ***(��)   ="<<endl;
    cout<<"=   ��Ʒ��λ: ************                       ***(��)   ="<<endl;
    cout<<"=                                                                        ="<<endl;
    cout<<"=========================================================================="<<endl<<endl;
    cout<<"1:������Ϣ              2:ɾ����Ϣ"<<endl;
    cout<<"3:��    ѯ              4:��    ��"<<endl;
    cout<<"5:ͳ    ��              6:��յ���"<<endl;
    cout<<"7:��������              8:��������"<<endl;
    cout<<"9:��    ӡ              0:�˳�ϵͳ"<<endl<<endl;  
}

//-----------------------------------------------------------------------------
char * GetSubStr(char *cSourceStr,int iStartPos,int iSubLen)
{   //���256���ַ�
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

//****************************����ȫ�ֺ����������***************************

//*****************************����������������******************************
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
        ShowTitle(); //��ʾ�����棬���ṩѡ��
        cout<<"��ѡ��(0-9):";
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
            cout<<"1:�����ѯ 2:��ϲ�ѯ 0:����";
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
            cout<<"��лʹ�ñ�ѧ����������ϵͳ,�ټ�!"<<endl;
            return;
        }
    }
}
//***************************�������������*************************************
