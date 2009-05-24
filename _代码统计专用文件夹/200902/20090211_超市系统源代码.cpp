/*************************************************/ 
//Ϊ��˳����ϰһ��ʹ������ṹ������������ṹʵ�֡� 
// -----By kuaidh00--------2008/01/08------------- 
//**************************************************** 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include <stdio.h> 


using namespace std; 

struct Sale 
{ 
//������ 
string m_code; 
string m_name; 
float m_price; 
unsigned int m_quantity; 
//ָ���� 
struct Sale* next; 
}; 

typedef struct Sale Node;//ȡ�������Node. 
typedef Node* Link;//ȡ������,Link. 

//�������� 
Link Create(Link Head) 
{ 
//-----��ʼ��ͷ�ڵ� Head------- 
Head=(Link)new Node;//ÿ�ζ�̬����һ��Node�ڴ��С�� 
Head->m_code=""; 
Head->m_name=""; 
Head->m_price=0.0; 
Head->m_quantity=0; 
Head->next=NULL; 

//----- 
Link ptr;//����һ�����������ָ�� ptr�� 
ptr=Head;//ָ���׽ڵ㡣 
Link DNode;//�������ݽڵ㣬����������ݡ� 
char GoOn; 
do 
{ 
cout<<"��Ʒ��Ϣ¼��! "<<endl; 
string code,name; 
float price; 
unsigned int quantity; 
cout<<"������룺"<<endl; 
cin>>code; 
cout<<"�������ƣ�"<<endl; 
cin>>name; 
cout<<"����۸�"<<endl; 
cin>>price; 
while(cin.fail()) 
{ 
cout<<"��������ȷ�ĸ�ʽ��"<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>price; 
} 
cout<<"����������"<<endl; 
cin>>quantity; 
while(cin.fail()) 
{ 
cout<<"��������ȷ�ĸ�ʽ��"<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>quantity; 
} 
//----������----- 
DNode=(Link)new Node;//ÿ�ζ�̬����һ��Node�ڴ��С�� 
DNode->m_code=code; 
DNode->m_name=name; 
DNode->m_price=price; 
DNode->m_quantity=quantity; 
//----ָ����----- 
DNode->next=NULL;//��Ϊβ�ڵ���롣 
ptr->next=DNode;//���������С� 
ptr=DNode;//ʹ�½ڵ��Ϊ��һ�ε�ǰ���� 
cout<<"��Ʒ��Ϣ¼��ɹ��� �Ƿ����¼��?(Y/N) "; 
cin>>GoOn; 

}while(GoOn=='Y'||GoOn=='y'); 
return Head; 
} 

//�ͷ����� 
void Release(Link Head) 
{ 
Link ptr; 
while(Head!=NULL) 
{ 
ptr=Head; 
Head=Head->next; 
delete ptr; 
} 
} 

//��ѯ�� 
Link Search(Link Head,string& code) 
{ 
Link ptr; 
//Link front; 
ptr=Head;//����һ�����ڲ�����ָ��ptr�� 
//ptr=fornt->next; 
while(ptr!=NULL) 
{ 
if(ptr->m_code==code) 
return ptr; 
else 
ptr=ptr->next; 
} 
cout<<"�޴���Ʒ��"<<endl; 
return ptr;//��ʱ��ptrΪNULL�ˡ� 
} 

//��ӡ���� 
void Display(Link Head) 
{ 
Link ptr; 
ptr=Head->next;//,��Ҫͷ�ڵ㣬ֻ������ݽڵ㡣 
cout<<"==========================================================="<<endl; 
cout<<"===============������Ʒ��Ϣ�嵥============================"<<endl; 
cout<<"==========================================================="<<endl; 
cout<<"��Ʒ����=======��Ʒ����======��Ʒ�۸�======��Ʒ����===="<<endl; 
while(ptr!=NULL) 
{ 
cout<<setw(15)<<left<<ptr->m_code 
<<setw(15)<<left<<ptr->m_name 
<<setw(15)<<left<<ptr->m_price 
<<setw(15)<<left<<ptr->m_quantity<<endl; 
ptr=ptr->next; 
} 
} 
void Display_One(Link Head,string& code,unsigned quantity) 
{ 
Link ptr; 
ptr=Search(Head,code);//,��Ҫͷ�ڵ㣬ֻ������ݽڵ㡣 
cout<<"��Ʒ����=======��Ʒ����======��Ʒ�۸�======��Ʒ����======С��(Ԫ)===="<<endl; 
cout<<setw(15)<<left<<ptr->m_code 
<<setw(15)<<left<<ptr->m_name 
<<setw(15)<<left<<ptr->m_price 
<<setw(15)<<left<<quantity 
<<setw(15)<<left<<quantity*ptr->m_price<<endl; 

} 


//������ƷС�ᡣ 
float CheckOut(Link Head,string& code,unsigned quantity) 
{ 
Link ptr; 
float sum(0); 
ptr=Search(Head,code); 
sum=(ptr->m_price*quantity); 
return sum; 
} 

//�ܽ��ʡ� 
void Total(Link Head) 
{ 
Link ptr; 
ptr=Head; 
float sum(0); 
float factly; 
char GoOn; 
while(1) 
{ 
cout<<"Ҫ������Ʒ�����밴\'N\',�����������ʾ��������! "<<endl; 
cin>>GoOn; 
if(GoOn=='N'||GoOn=='n') 
break; 
else 
{ 
string code; 
unsigned int quantity; 
cout<<"����Ҫ�������Ʒ����:"<<endl; 
cin>>code; 
cout<<"����Ҫ���������:"<<endl; 
cin>>quantity; 
sum+=CheckOut(ptr,code,quantity); 
cout<<"�㹺�����ƷΪ��"<<endl; 
Display_One(ptr,code,quantity); 
} 
} 
cout<<"----------------------------------------------------"<<endl; 
cout<<"��Ӧ�ø� "<<sum<<"Ԫ!"<<endl; 
cout<<"��ʵ�ʸ�(Ԫ): "; 
cin>>factly; 
cout<<"Ӧ���һ��� "<<factly-sum<<"Ԫ!"<<endl;//���㡣 
} 


int main() 
{ 
//---------�˵�ѡ��---------------- 
Link Head=NULL; 
//Head=Create(Head); 

int loop=1; 
while(loop) 
{ 
cout<<"***************************************************"<<endl; 
cout<<"*---------------------�˵�ѡ��--------------------*"<<endl; 
cout<<"*-------------------------------------------------*"<<endl; 
cout<<"* 1.�������� 2.������Ʒ 3.��ʾ���� 0.�˳�ϵͳ *"<<endl; 
cout<<"***************************************************"<<endl; 
int menu; 
cin>>menu; 
if(cin.fail()) 
{ 
cout<<"�밴�˵���Ӧ������ѡ����ʵĲ�����лл����!"<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>menu; 
} 
switch(menu) 
{ 
case 0: 
cout<<"���˳�ϵͳ!"<<endl; 
loop=0; 
break; 
case 1: 
Head=Create(Head); 
break; 
case 2: 
Total(Head); 
break; 
case 3: 
Display(Head); 
break; 
}//switch(menu) 
}//while(loop) 

//Display(Head); 
//Total(Head); 
Release(Head); 
return 0; 
} 