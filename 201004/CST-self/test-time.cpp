// Reference: http://cplusplus.com/reference/clibrary/ctime/strftime/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <time.h>

using namespace std;

string i2s( int i ) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string get_file_name( int i ) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    string file_name;
    
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer, 80, "%Y-%m-%d-%M-%S", timeinfo );
    file_name.append( buffer );
    file_name.append( "-" );
    file_name.append( i2s( i ) );
    file_name.append( ".jpg" );
    
    return file_name;
}

int main() {
    for ( int i = 0; i < 1000; ++i ) {
        string file_name = get_file_name( i );
        
        printf( "%s\n", file_name.c_str() );
    }
    
    return 0;
}
