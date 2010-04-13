////////////////////////////////////
// Date:     2010-04-13
// Author:   Yishi Guo
// About:    C++ bit operation
////////////////////////////////////
#include <iostream>

using namespace std;

// For Binary Operations
// AND (&), OR (|), XOR (^)
int bit_operation( int n1, int n2, char op ) {
    int nValue = 0;

    switch ( op ) {
        case '&':
            nValue = n1 & n2;
            break;
        case '|':
            nValue = n1 | n2;
            break;
        case '^':
            nValue = n1 ^ n2;
            break;
        default:
            nValue = n1 & n2;
            op = '&';
        break;
    }

    return nValue;
}

// For Unary Operations
// NOT (~)
int bit_operation( int n, char op ) {
    int nValue;

    switch( op ) {
        case '~':
            nValue = ~n;
            break;
        default:
            nValue = ~n;
            op = '~';
        break;
    }

    return nValue;
}

// For Left-Shift and Right-Shift
int bit_shift( int n, int offset, char op ) {
    int nValue = 0;
    switch( op ) {
        case 'l':
            nValue = n << offset;
            break;
        case 'r':
            nValue = n >> offset;
            break;
        default:
            nValue = n << offset;
            break;
    }

    return nValue;
}

void output_bit_operation( int n1, int n2, char op ) {
    cout << n1 << " " << op << " " << n2 << " = "
         << bit_operation( n1, n2, op ) << endl;
}

void output_bit_operation( int n, char op ) {
    cout << op << " " << n << " = "
         << bit_operation( n, op ) << endl;
}

void output_bit_shift( int n, int offset, char op ) {
    cout << n << ( op == 'l' ? " << " : " >> " )
         << offset << " = " << bit_shift( n, offset, op )
         << endl;
}

int main() {
    int nBuffer = 0x00000001;

    cout << "nBuffer: " << nBuffer << endl;

    // Test for "Left-Shift( << )"
    for ( int i = 0; i < 32; ++i ) {
        output_bit_shift( nBuffer, i, 'l' );
    }

    // Test for "Right-Shift( >> )"
    nBuffer |= 0x10000000;

    cout << "nBuffer: " << nBuffer << endl;

    for ( int i = 0; i < 32; ++i ) {
        output_bit_shift( nBuffer, i, 'r' );
    }

    // Test for AND, OR, XOR, NOT

    int nBuffer1 = 5;
    int nBuffer2 = 3;
    int nValue;

    output_bit_operation( nBuffer1, nBuffer2, '&' );  // AND
    output_bit_operation( nBuffer1, nBuffer2, '|' );  // OR
    output_bit_operation( nBuffer1, nBuffer2, '^' );  // XOR
    output_bit_operation( nBuffer1, '~' );            // NOT

    return 0;
}
