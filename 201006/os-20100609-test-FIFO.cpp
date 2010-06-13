////////////////////////////////////////////
// Date:    2010-06-12 / Create this file
//          2010-06-13 / Add comments
// Author:  Yishi Guo
// About:   OS Expriment
//          FIFO
////////////////////////////////////////////
#include <string>
#include <sstream>
#include <vector>
#include "os-20100609-header.hpp"

using namespace std;

int block_size = 3;

int main( int argc, char** argv ) {
  if ( argc > 1 ) {
    int size = string2int( string( argv[1] ) );
    set_block_size( block_size, size );  // Set the value of block size
  }
  vector<int> vec, block;
  if ( argc > 2 ) {
    set_vector_by_string( vec, string( argv[2] ), "," );
                                         // Set the vector by string
  } else {
    set_test_vector( vec );              // Set the vector by test value
  }
  int pos_index = 0;
  int fault_count = 0;
  int oldValue = -1;
  for ( int i = 0; i < vec.size(); ++i ) {
    if ( i < block_size ) {  // First block_size values add to block
      block.push_back( vec[i] );
    } else {
      if ( pos_block( block, vec[i] ) < block_size ) {
        // The value if already in the block
        print_page( vec, block, i );
        continue;
      } else {
        oldValue = block[pos_index%block_size];  // Set old value
        block[pos_index%block_size] = vec[i];    // Set new value
      }
    }
    ++pos_index;
    ++fault_count;
    // cout << "FAULT COUNT: " << fault_count << endl;
    print_page( vec, block, i, oldValue );
  }
  print_fault_rate( fault_count, vec.size() );

  return 0;
}
