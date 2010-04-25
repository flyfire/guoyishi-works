/////////////////////
// IMAGES DOWNLOAD //
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <curl/curl.h>

using namespace std;

const char* image_url = "http://self.cust.edu.cn/selfservice/code.jsp";

string i2s( int i ) {
    stringstream ss;
    ss << i;
    return ss.str();
}

int c2i ( const char* str ) {
    int value = 0;
    stringstream ss;
    ss << str;
    ss >> value;
    return value;
}

string get_time() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer, 80, "%Y-%m-%d-%H-%M-%S", timeinfo );
    
    return string( buffer );
}

string get_file_name( int i, string path = "", string extension_name = ".jpg" ) {

    string file_name = "";
    
    if ( !path.empty() ) {
        file_name.append( path );
    }    

    file_name.append( get_time() );
    file_name.append( "-" );
    file_name.append( i2s(i) );
    file_name.append( extension_name );
    
    return file_name;
}

void have_error( int errno ) {
    static int error_count = 0;
    ++error_count;
    if ( error_count > 10 ) {  // have many error exit the programe
        exit( 1 );
    }
}

int main( int argc, char** argv ) {
    time_t start, end;
    time( &start );
    const char* dir_name = "./";
    int times = 1000;
    if ( argc >= 2 ) {
        dir_name = argv[1];
    }
    if ( argc >= 3 ) {
        // printf( "argc >= 3\n" );
        times = c2i( argv[2] );
    }
    
    CURL* curl;
    CURLcode res;
    FILE* fp;
    
    curl = curl_easy_init();
    
    if ( !curl ) {
        cout << "cURL init error!" << endl;
        return ( -1 );
    }
    
    for ( int i = 0; i < times; ++i ) {
        const char* file_name = get_file_name( i, dir_name ).c_str();
        
        // FOR DEBUG
        // cout << "==== FILE NAME ====" << endl;
        // cout << file_name << endl;
        
        fp = fopen( file_name, "wb" );
        if ( !fp ) {
            cout << "File can't be opened!" << endl;
            have_error( 1 );
        }
        
        // FOR DEBUG
        // cout << "#1" << endl;
        
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, NULL );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
        curl_easy_setopt( curl, CURLOPT_URL, image_url );
        
        res = curl_easy_perform( curl );
        if ( res ) {
            cout << "Can't grab the image!" << endl;
            have_error( 2 );
        }
        fclose( fp );
    }
    curl_easy_cleanup( curl );
    
    time( &end );
    
    double dif;
    dif = difftime( end, start );
    printf( "COUNT: %d\n", times );
    printf( "TIME: %.2lf seconds\n", dif );
    
    return 0;
}
