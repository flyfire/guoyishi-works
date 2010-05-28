////////////////////////////////////////////
// Date:      2010-05-17
// Modified:  2010-05-28
// Author:    Yishi Guo
// About:     CRC(Cyclic Redundancy Check)
// Editor:    GVIM
////////////////////////////////////////////
#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>

using namespace std;

// Get remainder bits
template <size_t N1, size_t N2>
bitset<N2> get_remainder( bitset<N1> bitString, size_t start, size_t length ) {
  bitset<N2> returnBits;
  for ( size_t i = start; i < start+length; ++i ) {
    if ( bitString[i] == 1 ) {
      returnBits.set( i-start, 1 );
    }
  }
  return returnBits;
}

// Print bits with return
template <size_t N>
void print_bits( bitset<N> bits, size_t len = N ) {
  print_bit( bits, len );
  cout << endl;
}

// Print bits without return
template <size_t N>
void print_bit( bitset<N> bits, size_t len = N ) {
  for ( size_t i = 0; i < bits.size() && i < len; ++i ) {
    cout << bits[i];
  }
}

// Print char
void print_char( size_t num, char ch ) {
  for ( size_t i = 0; i < num; ++i ) {
    cout << ch;
  }
  return;
}

//Print space
void print_space( size_t num ) {
  print_char( num, ' ' );
  return;
}

// Set random bits
template <size_t N>
void rand_bits( bitset<N>& bits ) {
  static int addValue = 1;
  srand( time(NULL) + addValue++ );
  for ( size_t i = 0; i < bits.size(); ++i ) {
    bits.set( i, rand()%2 );
  }
  return;
}

// Set bits with string
template <size_t N>
void set_bits( bitset<N>& bits, string bitString ) {
  for ( size_t i = 0; i < bits.size() && i < bitString.size(); ++i ) {
    if ( bitString[i] == '1' ) {
      bits.set( i, 1 );
    }
  }

  return;
}

// Set bits
template <size_t N1, size_t N2>
void set_bits( const bitset<N1> srcBits, bitset<N2>& dstBits ) {
  for ( size_t i = 0; i < srcBits.size() && i < dstBits.size(); ++i ) {
    dstBits.set( i, srcBits[i] );
  }
  return;
}

// Do xor for bits
template <size_t N>
bitset<N> bits_xor( const bitset<N> bits1, const bitset<N> bits2 ) {
  bitset<N> returnBits;
  for ( size_t i = 0; i < bits1.size() && i < bits2.size(); ++i ) {
    returnBits[i] = bits1[i] ^ bits2[i];
  }

  return returnBits;
} 

int main( int argc, char** argv ) {
  bitset<16> bits;
  bitset<4> remainder;
  bitset<4> generator;
  bitset<4> zero_generator;
  bitset<19> nowBits;
  
  set_bits( generator, "1101" );
  set_bits( zero_generator, "0000" );
  // set_bits( bits, "101001");
  
  if ( argc > 1 ) {
    set_bits( bits, string( argv[1] ) );
  } else {
    rand_bits( bits );
  }
  cout << "BITS:     ";
  print_bits( bits );
  
  set_bits( bits, nowBits );
  remainder = get_remainder<16,4>( bits, 0, 4 );
  cout << "NOW BITS: ";
  print_bits( nowBits );

  cout << "KEY BITS: ";
  print_bits( generator );

  print_bits( nowBits );

  size_t i = 0;
  for ( i = 0; i < bits.size(); ++i ) {

    print_space( i );
    print_bit( remainder );
    print_char( nowBits.size()-i-remainder.size(), '|' );
    cout << endl;
    if ( remainder[0] == 1 ) {
      print_space( i );
      print_bit( generator );
    } else {
      print_space( i );
      print_bit( zero_generator );
    }
    print_char( nowBits.size()-i-remainder.size(), '|' );
    cout << endl;
    if ( remainder[0] == 1 ) {
      remainder = bits_xor( remainder, generator );
    }
    remainder = remainder >> 1;
    remainder.set( remainder.size()-1, nowBits[i+remainder.size()] );
  }
  
  // for the last remainder
  print_space( i );
  print_bits( remainder, 3 );

  // Print the result
  cout << "RESULT:   ";
  print_bit( bits );
  print_bits( remainder, 3 );

  return 0;
}
