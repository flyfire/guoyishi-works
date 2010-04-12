///////////////////////////////////
// Date:     2010-04-12
// Author:   Yishi Guo
// About:    Computer Networks
//           |--Zero-bit Insertion
///////////////////////////////////

#include <iostream>
#include <string>

#define SIZE 5

using namespace std;

// The bits can just content '0' and '1'
bool isRightBits( string bits ) {
    for ( int i = 0; i < bits.size(); ++i ) {
        char bit = bits.at(i);
        // For debug:
        // cout << bit << " ";
        if ( bit != '1' && bit != '0' ) {
            return false;
        }
    }

    return true;
}

// Encode the bits
string zeroBitEncode( string bits ) {
    string encodeBits = "";
    int numOneCount = 0;
    for ( int i = 0, numOneCount = 0; i < bits.size(); ++i ) {
        char bit = bits.at(i);
        if ( bit == '1' ) {
            numOneCount++;
        } else if ( bit == '0' ) {
            numOneCount = 0;  // reset the count
        }

        encodeBits.push_back( bit );

        if ( numOneCount == SIZE ) {  // if there have five '1' add a '0'
            encodeBits.push_back( '0' );  // add the '0' bit

            numOneCount = 0;  // reset the count
        }
    }

    return encodeBits;
}

// Decode the bits
string zeroBitDecode( string encoded ) {
    string decodeBits = "";
    int numOneCount = 0;
    for ( int i = 0, numOneCount = 0; i < encoded.size(); ++i ) {
        char bit = encoded.at(i);

        if ( numOneCount == SIZE ) {
            numOneCount = 0;
            continue;
        }

        if ( bit == '1' ) {
            numOneCount++;
        } else if ( bit == '0' ) {
            numOneCount = 0;
        }

        decodeBits.push_back( bit );

    }

    return decodeBits;
}

int main() {
    string bits;
    cout << "Input your bits:" << endl;

    cin >> bits;

    if ( isRightBits( bits ) ) {
        cout << "Your input right bits!" << endl;
    } else {
        cout << "Your input wrong bits!" << endl;
        return -1;
    }

    string encoded = zeroBitEncode( bits );
    string decoded = zeroBitDecode( encoded );

    cout << "Original bits:\n" << bits << "\n"
         << "Zero Encoded Bits:\n" << encoded << "\n"
         << "Zero Decoded Bits:\n" << decoded << endl;

    return 0;
}
