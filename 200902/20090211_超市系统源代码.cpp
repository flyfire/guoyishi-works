/*************************************************/ 
//为了顺便练习一下使用链表结构，所以用链表结构实现。 
// -----By kuaidh00--------2008/01/08------------- 
//**************************************************** 
#include <iostream> 
#include <string> 
#include <iomanip> 
#include <stdio.h> 


using namespace std; 

struct Sale 
{ 
//数据域。 
string m_code; 
string m_name; 
float m_price; 
unsigned int m_quantity; 
//指针域。 
struct Sale* next; 
}; 

typedef struct Sale Node;//取外别名，Node. 
typedef Node* Link;//取个别名,Link. 

//创建链表。 
Link Create(Link Head) 
{ 
//-----初始化头节点 Head------- 
Head=(Link)new Node;//每次动态分配一个Node内存大小。 
Head->m_code=""; 
Head->m_name=""; 
Head->m_price=0.0; 
Head->m_quantity=0; 
Head->next=NULL; 

//----- 
Link ptr;//定义一个用来运算的指针 ptr。 
ptr=Head;//指到首节点。 
Link DNode;//定义数据节点，用来存放数据。 
char GoOn; 
do 
{ 
cout<<"商品信息录入! "<<endl; 
string code,name; 
float price; 
unsigned int quantity; 
cout<<"输入代码："<<endl; 
cin>>code; 
cout<<"输入名称："<<endl; 
cin>>name; 
cout<<"输入价格："<<endl; 
cin>>price; 
while(cin.fail()) 
{ 
cout<<"请输入正确的格式："<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>price; 
} 
cout<<"输入数量："<<endl; 
cin>>quantity; 
while(cin.fail()) 
{ 
cout<<"请输入正确的格式："<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>quantity; 
} 
//----数据域----- 
DNode=(Link)new Node;//每次动态分配一个Node内存大小。 
DNode->m_code=code; 
DNode->m_name=name; 
DNode->m_price=price; 
DNode->m_quantity=quantity; 
//----指针域----- 
DNode->next=NULL;//作为尾节点加入。 
ptr->next=DNode;//链入链表中。 
ptr=DNode;//使新节点成为下一次的前驱。 
cout<<"商品信息录入成功！ 是否继续录入?(Y/N) "; 
cin>>GoOn; 

}while(GoOn=='Y'||GoOn=='y'); 
return Head; 
} 

//释放链表。 
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

//查询。 
Link Search(Link Head,string& code) 
{ 
Link ptr; 
//Link front; 
ptr=Head;//定义一个用于操作的指针ptr。 
//ptr=fornt->next; 
while(ptr!=NULL) 
{ 
if(ptr->m_code==code) 
return ptr; 
else 
ptr=ptr->next; 
} 
cout<<"无此商品！"<<endl; 
return ptr;//此时的ptr为NULL了。 
} 

//打印链表。 
void Display(Link Head) 
{ 
Link ptr; 
ptr=Head->next;//,不要头节点，只输出数据节点。 
cout<<"==========================================================="<<endl; 
cout<<"===============所有商品信息清单============================"<<endl; 
cout<<"==========================================================="<<endl; 
cout<<"货品代码=======货品名称======货品价格======货品数量===="<<endl; 
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
ptr=Search(Head,code);//,不要头节点，只输出数据节点。 
cout<<"货品代码=======货品名称======货品价格======货品数量======小计(元)===="<<endl; 
cout<<setw(15)<<left<<ptr->m_code 
<<setw(15)<<left<<ptr->m_name 
<<setw(15)<<left<<ptr->m_price 
<<setw(15)<<left<<quantity 
<<setw(15)<<left<<quantity*ptr->m_price<<endl; 

} 


//单个商品小结。 
float CheckOut(Link Head,string& code,unsigned quantity) 
{ 
Link ptr; 
float sum(0); 
ptr=Search(Head,code); 
sum=(ptr->m_price*quantity); 
return sum; 
} 

//总结帐。 
void Total(Link Head) 
{ 
Link ptr; 
ptr=Head; 
float sum(0); 
float factly; 
char GoOn; 
while(1) 
{ 
cout<<"要结束商品买入请按\'N\',其它任意键表示继续买入! "<<endl; 
cin>>GoOn; 
if(GoOn=='N'||GoOn=='n') 
break; 
else 
{ 
string code; 
unsigned int quantity; 
cout<<"输入要购买的商品代码:"<<endl; 
cin>>code; 
cout<<"输入要购买的数量:"<<endl; 
cin>>quantity; 
sum+=CheckOut(ptr,code,quantity); 
cout<<"你购买的商品为："<<endl; 
Display_One(ptr,code,quantity); 
} 
} 
cout<<"----------------------------------------------------"<<endl; 
cout<<"你应该付 "<<sum<<"元!"<<endl; 
cout<<"你实际付(元): "; 
cin>>factly; 
cout<<"应该找回你 "<<factly-sum<<"元!"<<endl;//找零。 
} 


int main() 
{ 
//---------菜单选项---------------- 
Link Head=NULL; 
//Head=Create(Head); 

int loop=1; 
while(loop) 
{ 
cout<<"***************************************************"<<endl; 
cout<<"*---------------------菜单选项--------------------*"<<endl; 
cout<<"*-------------------------------------------------*"<<endl; 
cout<<"* 1.输入数据 2.买入商品 3.显示数据 0.退出系统 *"<<endl; 
cout<<"***************************************************"<<endl; 
int menu; 
cin>>menu; 
if(cin.fail()) 
{ 
cout<<"请按菜单对应的数字选择合适的操作，谢谢合作!"<<endl; 
cin.clear(); 
fflush(stdin); 
cin>>menu; 
} 
switch(menu) 
{ 
case 0: 
cout<<"已退出系统!"<<endl; 
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