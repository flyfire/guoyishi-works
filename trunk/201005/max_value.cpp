/////////////////////////////////////////
// THIS IS MY 40,000 LINES FILE! ////////
// Date: 2010-05-11
// Author: Yishi Guo
// About: Networking
//        Subnet_id and Hostnet_id
/////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int host_length = 16;
const int begin_num = 2;
const int end_num = 14;
const int max_value = 256;
const string mask_prefix = "255.255";

// n >= 0
long square( int k,unsigned int n ) {
    long value = 0;
    if ( n <= 0 ) {
        value = 1;
    } else {
        value = k * square( k, n-1 );
    }
    
    return value;
}

int mask_value ( int n ) {
    int value = 2;
    int total = 0;
    for ( int i = 0; i < n; ++i ) {
        total += max_value/value;
        value *= 2;
    }
    
    return total;
}

string i2s ( int n ) {
    stringstream ss;
    ss << n;
    return ss.str();
}

string postfix( int n, bool b_end = true ) {
    string post = "";
    post += ".";
    if ( n > 0 ) {
        post += i2s( mask_value(n) );
    } else {
        post += "0";
    }

    if ( !b_end ) {
        post += postfix( n-8, true );
    }

    return post;
}

long subnet_num( int n ) {
    return square(2,n)-2;
}

long hostnet_num( int n ) {
    return square(2,host_length-n)-2;
}

string print_if_max( int n ) {
    static bool is_printed = false;
    if ( n != end_num &&
         subnet_num(n)*hostnet_num(n) - subnet_num(n+1)*hostnet_num(n+1) > 0 &&
         !is_printed ) {
        is_printed = true;
        return " <<< MAX HERE!";
    }
    return "";
}

int main() {
    /* Test square function:
    for ( int i = 0; i < 10; ++i ) {
        cout << "2^" << i <<"=" << square( 2, i ) << endl;
    }
    */

    // cout << "MASK VALUE(8):" << mask_value ( 8 ) << endl;

    for ( int i = begin_num; i <= end_num; ++i ) {
        long sub = subnet_num(i);
        long host = hostnet_num(i);
        cout << setw(3) << i << "    "
             << setiosflags(ios::left) << setw(18) << ( mask_prefix + postfix( i, false ) ) << resetiosflags(ios::left)
             << setw(8) << sub
             << setw(8) << host
             << setw(10) << sub*host
             << print_if_max( i )
             << endl;
    }

    return 0;
}
