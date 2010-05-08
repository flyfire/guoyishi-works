#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
    bitset<8> M;
    bitset<3> G;
    bitset<3> CRC;

    // Set values:
    M.set( 1,1 );
    M.set( 2,1 );
    M.set( 5,1 );
    M.set( 6,1 );
    M.set( 7,1 );  // M: 11100110

    G.set( 0,1 );
    G.set( 1,1 );  // G: 1011

    for ( int i = 0; i < M.size(); ++i ) {
        bitset<3> shift;
        shift.set(shift.size()-1,M[i]);

        if ( CRC[CRC.size()-1] == 1 ) {
            CRC = (CRC << 1) | shift;
            CRC ^= G;
        } else {
            CRC = (CRC << 1) | shift;
        }

        // test for CRC value:
        cout << i << " " << CRC << " M:" << M[i] << endl;
    }

    cout << CRC << endl;

    return 0;
}
