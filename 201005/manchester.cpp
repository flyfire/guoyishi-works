////////////////////////////////
// Date:    2010-05-09
// Author:  Yishi Guo
// About:   Manchester Code
////////////////////////////////
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stdlib.h>
#include <time.h>

using namespace std;

string str_value = "";     // string of value
string str_binary = "";    // string of binary
string str_man = "";       // string of manchester
string str_diff_man = "";  // string of differential Manchester
bool b_value = false;      // bool of now binary value
string now_signal = "";    // string of now signal
string up_signal = "/";    // UP
string down_signal = "\\"; // DOWN

// Get the random number 
// which between min and max
int rand_number_get( int min = 0, int max = 16 ) {
    static int add_value = 1;
    srand ( time(NULL) + add_value++ );
    return rand() % ( max - min ) + min;
}

// Get the random length
int rand_length_get( int min = 10, int max = 30 ) {
    return rand_number_get( min, max );
}

// Generate random number
string rand_hex() {
    stringstream ss;
    int value = rand_number_get( 0, 16 );
    ss << hex << value;
    return ss.str();
}

// Convert a hex to binary
string hex2bin( char h ) {
    int value;
    stringstream ss;
    ss << hex << h;
    ss >> value;
    bitset<4> bin( value );
    return bin.to_string();
}

// Convert hex to binary
string hex2bin_str( string hex ) {
    string bin_str = "";
    for ( int i = 0; i < hex.length(); ++i ) {
        bin_str += hex2bin( hex.at(i) );
    }

    return bin_str;
}

// Convert a binary to manchester
string bin2man( char b ) {
    if ( b == '0' ) {
        return up_signal;
    }
    else if ( b == '1' ) {
        return down_signal;
    }
    return "X";
}

// Convert binary to manchester
string bin2man_str( string bin ) {
    string man = "";
    for ( int i = 0; i < bin.length(); ++i ) {
        man += bin2man( bin.at(i) );
    }
    
    return man;
}

// Get the hex string
string get_hex_str( int length ) {
    string hex_str = "";
    for ( int i = 0; i < length; ++i ) {
        hex_str += rand_hex();
        //cout << hex_str << endl;
    }
    return hex_str;
}

// Change the value of bool
void change_bool( bool & b ) {
    if ( b == false ) {
        b = true;
    } else {
        b = false;
    }
}

// Get now signal
string get_now_signal() {
    if ( b_value ) {
        if ( now_signal == down_signal ) {
            now_signal = up_signal;
        } else if ( now_signal == up_signal ) {
            now_signal = down_signal;
        }
    }
    return now_signal;
} 

// Get the differential Manchester encoding
string get_diff_man( string bin ) {
    string diff_man = "";
    for ( int i = 0; i < bin.length(); ++i ) {
        if ( i == 0 ) {
            b_value = false;
            now_signal = down_signal;
        } else if ( bin.at(i) == '1' ) {
            b_value = true;
        } else {
            b_value = false;
        }
        diff_man += get_now_signal();
    }
    return diff_man;
}

int main() {
    int length = rand_length_get( 5, 10 );
    str_value = get_hex_str( length );
    cout << "RANDOM HEX : " << str_value << endl;
    str_binary = hex2bin_str( str_value );
    cout << "BINARY     : " << str_binary << endl;
    str_man = bin2man_str( str_binary );
    cout << "MANCHESTER : " << str_man << endl;
    str_diff_man = get_diff_man( str_binary );
    cout << "DIFF MAN   : " << str_diff_man << endl;

    return 0;
}
