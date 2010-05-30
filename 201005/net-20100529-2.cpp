//////////////////////////////
// Date: 2010-05-29
// Author: Yishi Guo
// About: Network Exercise
///////////////////////////////
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// RIP item structure
struct rip_item {
  string netName;  // Network name
  int length;      // Network Distance
  string nextName; // Next destination
};

// Route table structure
struct route_table {
  vector<rip_item> items; // route table items
  string routeName;       // Name of route
};

// Print title of items table
void print_items_title( void ) {
  cout << "NET"  << "\t"
       << "LEN"  << "\t"
       << "NEXT" << endl;
  return;
}

// Print RIP item
void print_item( const rip_item item ) {
  cout << item.netName << "\t"
       << item.length << "\t"
       << item.nextName << endl;
  return;
}

// Print RIP items
template <typename T>
void print_items( const vector<T> items ) {
  print_items_title();
  for ( int i = 0; i < items.size(); ++i ) {
    print_item( items[i] );
  }
  return;
}

// Print RIP table
void print_table( const route_table table ) {
  cout << "Route Name: " << table.routeName << endl;
  print_items( table.items );
}

// Get new RIP item
template <typename T>
T get_new_item( void ) {
  T item;
  cout << "Network Name:";
  cin >> item.netName;
  cout << "Length:";
  cin >> item.length;
  cout << "Next Jump Name:";
  cin >> item.nextName;

  return item;
}

// Judge as the item can be insert
template <typename T>
bool is_right_item( const vector<T> items, const T item ) {
  for ( int i = 0; i < items.size(); ++i ) {
    /* TEST for netName
    cout << "TEST!" << endl;
    cout << "items[" << i << "].netName=" << items[i].netName << endl;
    cout << "item.netName=" << item.netName << endl;
    */
    if ( items[i].netName == item.netName ) {
      return false;
    }
  }

  return true;
}

// Set new route items
template <typename T>
void set_new_items( vector<T>& items, int count ) {
  for ( int i = 0; i < count; ++i ) {
    T item = get_new_item<T>();
    if ( is_right_item( items, item ) ) {  // Network name exist?
      items.push_back( item );             // Add item to items
    } else {
      cout << "WRONG INPUT!" << endl;
      --i;
      continue;
    }
  }
  return;
}

// Set new RIP table
void set_new_table( route_table& table ) {
  cout << "Input route name:";
  cin >> table.routeName;
  cout << "Input count of items:";
  int count= 0;
  cin >> count;
  set_new_items( table.items, count );     // Set items

  return;
}

// Judge as have same Network Name
template <typename T>
int have_item( const vector<T> items, T item ) {
  int pos = 0;
  for ( pos = 0; pos < items.size(); ++pos ) {
    if ( items[pos].netName == item.netName ) { // Same network name
      return pos;
    }
  }

  return pos;
}

// Refresh the table
void refresh_table( const route_table srcTable, route_table& dstTable ) {
  vector<rip_item> items = srcTable.items;
  int i = 0;
  for ( i = 0; i < items.size(); ++i ) {
    items[i].length++;                      // Distance + 1
    items[i].nextName = srcTable.routeName; // Set name of route
  } 

  for ( i = 0; i < items.size(); ++i ) {    // Judge every items
    int pos = have_item( dstTable.items, items[i] );
    if ( pos >= dstTable.items.size() ) {   // No this network
      dstTable.items.push_back( items[i] ); // Add it
    } else {
      if ( dstTable.items[pos].nextName == items[i].nextName ) { // Same next destination
        dstTable.items[pos].length = items[i].length; // set the distance
      } else if ( dstTable.items[pos].length > items[i].length ) { // New distance is short then old
        dstTable.items[pos].nextName = items[i].nextName; // Set the next distination
      }
    }
  }
}

// Main function
int main( int argc, char** argv ) {
  cout << "Initialization:" << endl;
  route_table myTable;
  set_new_table( myTable );
  print_table( myTable );
  cout << "Input test count:";
  int testCount = 0;
  cin >> testCount;            // Get count of test
  int i = 0;
  for ( i = 0; i < testCount; ++i ) {
    cout << "#" << (i+1) << ":" << endl;
    route_table testTable;
    set_new_table( testTable ); // Set test table
    refresh_table( testTable, myTable ); // Refresh route table
    print_table( myTable );
  }

  return 0;
}
