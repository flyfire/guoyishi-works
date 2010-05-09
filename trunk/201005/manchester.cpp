////////////////////////////////
// Date:    2010-05-09
// Author:  Yishi Guo
// About:   Manchester Code
////////////////////////////////
// Test SVN 1
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#include <stdlib.h>
#include <time.h>

using namespace std;

string str_value = "";  // string of value
string str_binary = ""; // string of binary
string str_man = "";    // string of manchester

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
        return "/";
    }
    else if ( b == '1' ) {
        return "\\";
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

int main() {
    int length = rand_length_get(1, 4);
    str_value = get_hex_str( length );
    cout << "RANDOM HEX : " << str_value << endl;
    str_binary = hex2bin_str( str_value );
    cout << "BINARY     : " << str_binary << endl;
    str_man = bin2man_str( str_binary );
    cout << "MANCHESTER : " << str_man << endl;

    return 0;
}
