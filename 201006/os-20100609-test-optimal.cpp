///////////////////////////////////////////
// Date:    2010-06-10
//          2010-06-12 / Set header file
//          2010-06-13 / Add comments
// Author:  Yishi Guo
// About:   OS Expriment
//          optimal
///////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include "os-20100609-header.hpp"

using namespace std;

const int block_size = 3;

// Is the last one?
// ( Which is the optimal one )
bool is_last_one( vector<bool> bvec ) {
  int count = 0;
  for ( int i = 0; i < bvec.size(); ++i ) {
    if ( bvec[i] ) {
      ++count;
    }
    if ( count > 1 ) {
      return false;
    }
  }
  return true;
}

// Get the first "true" position
int first_true( vector<bool> bvec ) {
  int i = 0;
  for ( i = 0; i < bvec.size(); ++i ) {
    if ( bvec[i] ) {
      return i;
    }
  }

  return i;
}

// Set all vector value to "true"
void set_bool_vector( vector<bool>& bvec, int count = block_size ) {
  for ( int i = 0; i < count; ++i ) {
    bvec.push_back( true );
  }
}

// Get the optimal value position
int pos_optimal( vector<int> vec, vector<int> block, int pos ) {
  vector<bool> temp;
  set_bool_vector( temp, block.size() );
  for ( int i = pos+1; i < vec.size(); ++i ) {
    int pos_b = 0;
    if ( ( pos_b = pos_block( block, vec[i] )) < block.size() ) {
      temp[pos_b] = false;
    } else {
      continue;
    }
    if ( is_last_one( temp ) ) {
      break;
    }
  }
  return first_true( temp );
}

int main() {
  vector<int> vec, block;
  set_test_vector( vec );  // Set the vector test value
  // print_vector( vec );
  // cout << endl;
  int pos = 0;
  int fault_count = 0;
  for ( int i = 0; i < vec.size(); ++i ) {
    if ( block.size() < block_size ) {  // First block_size value
                                        // add to block
      block.push_back( vec[i] );
      print_page( vec, block, i );
    } else {
      int pos_b = 0, oldValue = -1;
      if ( ( pos_b = pos_block( block, vec[i] ) ) < block.size() ) {
        // The value is in already in the block
        print_page( vec, block, i );
        continue;
      } else {
        pos = pos_optimal( vec, block, i );  // Get the optimal position
        oldValue = block[pos];  // Get the old value
        block[pos] = vec[i];    // Set the new value
      }
      print_page( vec, block, i, oldValue );
    }
    ++fault_count;
  }
  print_fault_rate( fault_count, vec.size() );

  return 0;
}
