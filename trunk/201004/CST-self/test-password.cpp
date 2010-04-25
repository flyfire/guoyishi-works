// FOR GENERATE PASSWORDS
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <string>

using namespace std;

template <class T>
T s2i( const char* ca ) {
    T value;
    stringstream ss;
    ss << ca;
    ss >> value;
    
    return value;
}

template <class T>
string num2str( T num ) {
    stringstream ss;
    ss << num;
    
    return ss.str();
}

template <class T>
string num2str( T num, int length ) {
    string value = num2str( num );
    string zeros = "";
    for ( int i = 0; i < (length-value.size()); ++i ) {
        zeros += "0";
    }
    value = zeros + value;
    
    return value;
}

void help() {
    cout << "Usage: " << endl;
    cout << "\tpassword\t"
         << "[length]\t"
         << "[max]"
         << endl;
}
         

int length = 6;
long max_num = 100;

int main( int argc, char** argv ) {
    if ( argc >= 2 ) {
        length = s2i<int>( argv[1] );
    } else {
        help();
        exit( EXIT_FAILURE );
    }
    
    if ( argc >= 3 ) {
        max_num = s2i<long>( argv[2] );
    }
    
    cout << "length: " << length << endl;
    
    for ( long l = max_num; l > 9; --l ) {
        cout << num2str( l, length ) << endl;
    }
    
    return 0;
}
