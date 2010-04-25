// TEST FOR UTF-9 ENCODING
#include <iostream>
#include <string>
using namespace std;

int main( int argc, char** argv ) {
    string str1, str2;
    
    str1 = "我是中华人民共和国公民！";
    str2 = "中华";
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    
    if ( str1.find( str2 ) != string::npos ) {
        cout << "Find!" << endl;
    }
    
    return 0;
}
