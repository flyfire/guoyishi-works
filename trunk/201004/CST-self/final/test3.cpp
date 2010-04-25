//////////////////////////////////////
// !!!!!! COPY !!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <curl/curl.h>

using namespace std;

const char* post_url             =  "http://self.cust.edu.cn/selfservice/login.jsf";
const char* get_url              =  "http://self.cust.edu.cn/selfservice/code.jsp";
const char* cookie_file_name     =  "./self_cookie.txt";
const char* username             =  "en0201101";
const char* password             =  "0000";
const char* code                 =  "";
const char* usertype             =  "1";
const char* content              = "cmdForm%3Ausername=youandme&cmdForm%3Apassword=0000&cmdForm%3Acode=AAAA&cmdForm%3Ausertype=1&cmdForm%3A_idJsp34=%E7%99%BB%E5%BD%95&cmdForm_SUBMIT=1&jsf_sequence=1&cmdForm%3A_link_hidden_=";

long times                       =  5L;

bool is_debug = false;




////////////////////////////
// X2X /////////////////////
string i2s( int i ) {
    stringstream ss;
    ss << i;
    return ss.str();
}

string l2s( long l ) {
    stringstream ss;
    ss << l;
    return ss.str();
}

char* i2c( int i ) {
    stringstream str;
    str << i;
    return (char*)str.str().data();
}

long c2l( const char* ca ) {
    long value;
    stringstream str;
    str << ca;
    str >> value;
    return value;
}

long s2l( string str ) {
    long value;
    stringstream ss;
    ss << str;
    ss >> value;
    return value;
}

////////////////////////////////
// TIME ////////////////////////
string get_time( bool is_dir = false ) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    if ( is_dir ) {
        strftime( buffer, 80, "%Y%m%d", timeinfo );
    } else {
        strftime( buffer, 80, "%Y-%m-%d-%H-%M-%S", timeinfo );
    }
    
    return string( buffer );
}

string get_file_name( long i, string path = "", string extension_name = ".jpg" ) {

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

string get_dir_name( ) {
    string dir_name = "";
    dir_name += get_time( true );
    dir_name += "/";
    return dir_name;
}
    


///////////////////////////////////////
// MAIN ///////////////////////////////
int main( int argc, char** argv ) {
    // Check for the options:
    const char* post_url_opt = "--post-url=";
    int post_url_opt_len     = (int)strlen( post_url_opt );
    const char* username_opt = "--username=";
    int username_opt_len     = (int)strlen( username_opt );
    const char* password_opt = "--password=";
    int password_opt_len     = (int)strlen( password_opt );
    const char* code_opt     = "--code=";
    int code_opt_len         = (int)strlen( code_opt );
    const char* usertype_opt = "--usertype=";
    int usertype_opt_len     = (int)strlen( usertype_opt );
    const char* is_debug_opt = "--debug";
    int is_debug_opt_len     = (int)strlen( is_debug_opt );
    const char* times_opt    = "--times=";
    int times_opt_len        = (int)strlen( times_opt );
    
    // Get the options:
    for ( int i = 0; i < argc; ++i ) {
        if ( strncmp( argv[i], post_url_opt, post_url_opt_len ) == 0 ) {
            post_url = argv[i] + post_url_opt_len;
        } else if ( strncmp( argv[i], username_opt, username_opt_len ) == 0 ) {
            username = argv[i] + username_opt_len;
        } else if ( strncmp( argv[i], password_opt, password_opt_len ) == 0 ) {
            password = argv[i] + password_opt_len;
        } else if ( strncmp( argv[i], code_opt, code_opt_len ) == 0 ) {
            code = argv[i] + code_opt_len;
        } else if ( strncmp( argv[i], usertype_opt, usertype_opt_len ) == 0 ) {
            usertype = argv[i] + usertype_opt_len;
        } else if ( strncmp( argv[i], is_debug_opt, is_debug_opt_len ) == 0 ) {
            is_debug = true;
        } else if ( strncmp( argv[i], times_opt, times_opt_len ) == 0 ) {
            times = c2l( argv[i] + times_opt_len );
        }
    }
    
    struct curl_slist *chunk = NULL, *postchunk = NULL;
        
    chunk = curl_slist_append( chunk, "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.9) Gecko/20100401 Ubuntu/9.10 (karmic) Firefox/3.5.9" );
    chunk = curl_slist_append( chunk, "Accept: image/png,image/*;q=0.8,*/*;q=0.5" );
    chunk = curl_slist_append( chunk, "Accept-Language: en-us,en;q=0.5" );
    chunk = curl_slist_append( chunk, "Accept-Encoding: gzip,deflate" );
    chunk = curl_slist_append( chunk, "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7" );
    chunk = curl_slist_append( chunk, "Keep-Alive: 300" );
    chunk = curl_slist_append( chunk, "Connection: keep-alive" );
    chunk = curl_slist_append( chunk, "Referer: http://self.cust.edu.cn/selfservice/login.jsf" );
    
    postchunk = curl_slist_append( postchunk, "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.9) Gecko/20100401 Ubuntu/9.10 (karmic) Firefox/3.5.9" );
    postchunk = curl_slist_append( postchunk, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8" );
    postchunk = curl_slist_append( postchunk, "Accept-Language: en-us,en;q=0.5" );
    postchunk = curl_slist_append( postchunk, "Accept-Encoding: gzip,deflate" );
    postchunk = curl_slist_append( postchunk, "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7" );
    postchunk = curl_slist_append( postchunk, "Keep-Alive: 300" );
    postchunk = curl_slist_append( postchunk, "Connection: keep-alive" );
    postchunk = curl_slist_append( postchunk, "Referer: http://self.cust.edu.cn/selfservice/login.jsf" );
    postchunk = curl_slist_append( postchunk, "Content-Type: application/x-www-form-urlencoded" );
    
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if ( !curl ) {
        cout << "cURL init error!" << endl;
        return ( -1 );
    }
    
    for ( long i = 0; i < times; ++i ) {
        const char* file_name = get_file_name( i ).c_str();
        
        FILE *fp;
        fp = fopen( file_name, "wb" );
        if ( !fp ) {
            cout << "File: [" << file_name << "] can't be opened!" << endl;
            exit( EXIT_FAILURE );
        }
        
        // FIRST: get login.jsf
        if ( i == 0 ) {  // get the first cookie
            curl_easy_setopt( curl, CURLOPT_URL, post_url );
            curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
            curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
            curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );
            
            res = curl_easy_perform( curl );
        }
        
        // SECOND: get code.jsp
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, NULL );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
        curl_easy_setopt( curl, CURLOPT_URL, get_url );
        
        res = curl_easy_perform( curl );
        
        // reset the curl for not download login.jsf page
        curl_easy_reset( curl );
        
        // THIRD: post login.jsf
        curl_easy_setopt( curl, CURLOPT_URL, post_url );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );    
        
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, content );
        
        res = curl_easy_perform( curl );
        
        // reset curl for not post code.jsp
        curl_easy_reset( curl );
    }
    curl_easy_cleanup( curl );
    
    return 0;
}
