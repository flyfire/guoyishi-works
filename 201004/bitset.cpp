////////////////////////////////////////
// Date: 2010-04-14
// Author: Yishi Guo
// About: C++ STL bitset
//        and its operations
////////////////////////////////////////
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

// Output the bit values of bitset
// Different from "cout << bits << endl;"
template <size_t N>
void output_bitset( bitset<N> bits ) {
    for ( int i = 0; i < bits.size(); ++i ) {
        cout << bits[i];
    }
    cout << endl;
}

// Reverse the bitset
template <size_t N>
bitset<N> reverse_bitset( bitset<N> bits ) {
    bitset<N> returnBits;
    for ( int i = 0; i < bits.size(); ++i ) {
        returnBits[i] = bits[bits.size()-i-1];
    }

    return returnBits;
}

int main() {
    bitset<8> bits;

    bits.set( 1, 1 );
    bits.set( 3, 1 );

    // Output the value of bitset:
    cout << "bitset:\n";
    cout << bits << endl;

    // Test the flip of bitset:
    cout << "filp of bitset:\n";
    bits.flip();
    cout << bits << endl;

    // reset the fliped bitset
    bits.flip();

    // Test the reverse of bitset:
    cout << "reverse of bitset:\n";
    bitset<8> reBits = reverse_bitset( bits );
    cout << reBits << endl;

    // Test the add operation
    cout << "add operation:\n";
    cout << ( reBits & bits ) << endl;

    // Test the or operation
    cout << "or operation:\n";
    cout << ( reBits | bits ) << endl;

    // Test the exclusive or operation
    cout << "xor operation:\n";
    cout << ( reBits ^ bits ) << endl;

    // Test the logical left shift
    cout << "left shift:\n";
    cout << ( bits << 1 ) << endl;

    // Test the logical right shift
    cout << "right shift:\n";
    cout << ( bits >> 1 ) << endl;

    // Test the count operation
    cout << "count of bitset:\n";
    cout << bits.count() << endl;

    // Test the size() operation
    cout << "size of bitset:\n";
    cout << bits.size() << endl;

    // Test the final value of bitset:
    cout << "final value:\n";
    cout << bits << endl;

    // Test another example
    cout << bitset<16>(0x0001) << endl;

    return 0;
}
