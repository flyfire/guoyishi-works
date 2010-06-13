/////////////////////////////
// Date: 2010-06-10
//       2010-06-12
//       2010-06-13
// Author: Yishi Guo
// About: OS Expriment
/////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Convert string to int
int string2int( string str ) {
  int value;
  stringstream( str ) >> value;
  return value;
}

// Set vector by string
// and separator by ',' or something
void set_vector_by_string( vector<int>& vec, string str, string separator = "," ) {
  int found;
  found = str.find_first_of( separator );
  while ( found != string::npos ) {
    if ( found > 0 ) {
      vec.push_back( string2int( str.substr( 0, found ) ) );
    }
    str = str.substr( found + 1 );
    found = str.find_first_of( separator );
  }
  if ( str.length() > 0 ) {
    vec.push_back( string2int( str ) );
  }
}

// Set the value of block size
void set_block_size( int& set_size, const int size ) {
  set_size = size;
}

// Set the vector by test values
void set_test_vector( vector<int>& vec, int count = 20 ) {
  vec.push_back( 7 ); vec.push_back( 0 ); vec.push_back( 1 );
  vec.push_back( 2 ); vec.push_back( 0 ); vec.push_back( 3 );
  vec.push_back( 0 ); vec.push_back( 4 ); vec.push_back( 2 );
  vec.push_back( 3 ); vec.push_back( 0 ); vec.push_back( 3 );
  vec.push_back( 2 ); vec.push_back( 1 ); vec.push_back( 2 );
  vec.push_back( 0 ); vec.push_back( 1 ); vec.push_back( 7 );
  vec.push_back( 0 ); vec.push_back( 1 );
}

// Print a line
void print_line( void ) {
  cout << "------------------";
  cout << endl;
}

// Print a vector
void print_vector( vector<int> vec ) {
  for ( int i = 0; i < vec.size(); ++i ) {
    cout << vec[i] << " ";
  }
}

// Print the point position
void print_point_position( vector<int> vec, int pos, int white_length) {
  for ( int i = 0; i < white_length; ++i ) {
    cout << " ";
  }
  for ( int i = 0; i < vec.size(); ++i ) {
    if ( i == pos ) {
      cout << "^";
      break;
    } else {
      cout << " ";
    }
    cout << " ";
  }
}

// Print replace information
void print_replace_info( int oldValue, int newValue ) {
  cout << "REPLACE " << oldValue
       << " WITH " << newValue
       << endl;
}

// Print page
void print_page( vector<int> vec,
                 vector<int> block,
                 int index,
                 int oldValue = -1 ) {
  const string page_info = "PAGES: ";
  const string block_info = "BLOCK: ";
  cout << "#" << index+1 << endl;
  if ( oldValue >= 0 ) {
    print_replace_info( oldValue, vec[index] );
  }
  cout << page_info;
  print_vector( vec );
  cout << endl;
  print_point_position( vec, index, page_info.size() );
  cout << endl;
  cout << block_info;
  print_vector( block );
  cout << endl;
  print_line();
}

// Print fault rate information
void print_fault_rate( int fault_count, int all_count ) {
  cout << "FAULT RATE: " << fault_count / ( all_count * 1.0 ) << endl;
}

// get the position of value in block
int pos_block( vector<int> vec, int value ) {
  int i;
  for ( i = 0; i < vec.size(); ++i ) {
    if ( vec[i] == value ) {
      return i;
    }
  }
  return i;
}
