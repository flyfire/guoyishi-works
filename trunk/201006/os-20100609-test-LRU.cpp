///////////////////////////////////////////
// Date:   2010-06-12 / Create this file
//         2010-06-13 / Add comments
// Author: Yishi Guo
// About:  OS Expriment
//         Least Recently Used
///////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include "os-20100609-header.hpp"

using namespace std;

int block_size = 3;

// Set times block vector
void set_times_vector( vector<int>& vec, int index ) {
  for ( int i = 0; i < vec.size(); ++i ) {
    vec[i]++;
  }
  vec[index] = 0;
}

// Get the LRU position
int pos_LRU( vector<int> times_block ) {
  int max_value = 0, max_value_index;
  for ( int i = 0; i < times_block.size(); ++i ) {
    if ( times_block[i] > max_value ) {
      max_value = times_block[i];
      max_value_index = i;
    }
  }
  return max_value_index;
}

// Main functions
int main( int argc, char** argv ) {
  vector<int> vec, block, times_block;
  set_test_vector( vec );
  int fault_count = 0;
  for ( int i = 0; i < vec.size(); ++i ) {
    int pos, oldValue;
    if ( i < block_size ) {
      block.push_back( vec[i] );
      times_block.push_back( 0 );  // Add "0" to times_block
      set_times_vector( times_block, i );  // values++ in times_block
                                           // and set the last value to "0"
      print_page( vec, block, i );
    } else {
      if ( ( pos = pos_block( block, vec[i] ) ) < block_size ) {
        set_times_vector( times_block, pos );  // values++ and last to "0"
        print_page( vec, block, i );
        continue;
      } else {
        pos = pos_LRU( times_block );  // Get the LRU position
        oldValue = block[pos];         // Set the old value
        block[pos] = vec[i];           // Set the new value
        set_times_vector( times_block, pos );  // values++ and last to "0"
      }
      print_page( vec, block, i, oldValue );
    }
    ++fault_count;
  }
  print_fault_rate( fault_count, vec.size() );

  return 0;
}
