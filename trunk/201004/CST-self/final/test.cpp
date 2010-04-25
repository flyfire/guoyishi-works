//////////////////////////////////////
// !!!!!! COPY !!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <curl/curl.h>
#include "CST-self-ocr.hpp"

using namespace std;

const char* post_url             =  "http://self.cust.edu.cn/selfservice/login.jsf";
const char* get_url              =  "http://self.cust.edu.cn/selfservice/code.jsp";
const char* cookie_file_name     =  "./self_cookie.txt";
const char* username             =  "en0201101";
const char* password             =  "0000";
const char* code                 =  "";
const char* usertype             =  "1";

long times = 5L;

string post_data =  "";

bool is_debug = false;

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

char* urlencode( string url ) {
    return curl_easy_escape( NULL, url.c_str(), 0 );
}

char* urlencode_option( string key, string value, bool is_first = false ) {
    string encode = "";
    if ( !is_first ) {
        encode += "&";
    }
    encode += urlencode( key );
    encode += "=";
    encode += urlencode( value );
    
    return (char*)encode.data();
}


string get_post_data() {
    string str_post_data = "";
    str_post_data += urlencode_option( "cmdForm:username", username, true );
    str_post_data += urlencode_option( "cmdForm:password", password );
    str_post_data += urlencode_option( "cmdForm:code", code );
    str_post_data += urlencode_option( "cmdForm:userType", usertype );
    str_post_data.append( "&cmdForm%3A_idJsp34=%E7%99%BB%E5%BD%95&cmdForm_SUBMIT=1&jsf_sequence=1&cmdForm%3A_link_hidden_=" );
    
    return str_post_data;
}

void help_info() {
    cout << "Usege: post --code=<code>\n"
         << "\t[--post-url=<post url>]\n"
         << "\t[--username=<username>]\n"
         << "\t[--password=<password>]\n"
         << "\t[--usertype=<usertype>]\n"
         << "\t[--debug]\n"
         << "\t[--times=<times>]\n"
         << endl;
    return;
}

void debug_show() {
    cout << "==== DEBUG INFO ====" << endl;
    cout << "post-url : " << post_url << "\n"
            "username : " << username << "\n"
            "password : " << password << "\n"
            "code     : " << code     << "\n"
            "usertype : " << usertype << "\n"
            "is-debug : " << ( is_debug ? "true" : "false" ) << endl;
    return;
}

void post_data_show( string post_data ) {
    cout << "==== POST DATA ====" << endl;
    cout << post_data << endl;
    
    return;
}


// Copy from third.cpp

string get_time() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    
    time( &rawtime );
    timeinfo = localtime( &rawtime );
    
    strftime( buffer, 80, "%Y-%m-%d-%H-%M-%S", timeinfo );
    
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

void have_error( int errno ) {
    static int error_count = 0;
    ++error_count;
    if ( error_count > 10 ) {  // have many error exit the programe
        exit( 1 );
    }
}

int main( int argc, char** argv ) {
    FILE *fp;
    
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
    
    if ( strcmp( code, "" ) == 0 ) {
        cout << "Error code!" << endl;
        help_info();
        return ( -2 );
    }
    
    // show debug info:
    if ( is_debug ) {
        debug_show();
    }
    
    post_data = get_post_data();
    
    // test for post data:
    if ( is_debug ) {
        post_data_show( post_data );
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
    
    long pass = s2l( password );
    for ( long i = 0; i < times; ++i ) {       
        const char* file_name = get_file_name( i ).c_str();
        const char* content = string(post_data).data();
        
        fp = fopen( file_name, "wb" );
        if ( !fp ) {
            cout << "File can't be opened!" << endl;
            have_error( 1 );
        }

        fclose( fp );

        CURL *curl;
        CURLcode res;
        
        curl = curl_easy_init();
        if ( !curl ) {
            cout << "cURL init error!" << endl;
            return ( -1 );
        }
        struct curl_slist *chunk = NULL;
        struct curl_slist *postchunk = NULL;
        chunk = curl_slist_append( chunk, "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.9) Gecko/20100401 Ubuntu/9.10 (karmic) Firefox/3.5.9" );
        chunk = curl_slist_append( chunk, "Accept: image/png,image/*;q=0.8,*/*;q=0.5" );
        chunk = curl_slist_append( chunk, "Accept-Language: en-us,en;q=0.5" );
        chunk = curl_slist_append( chunk, "Accept-Encoding: gzip,deflate" );
        chunk = curl_slist_append( chunk, "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7" );
        chunk = curl_slist_append( chunk, "Keep-Alive: 300" );
        chunk = curl_slist_append( chunk, "Connection: keep-alive" );
        chunk = curl_slist_append( chunk, "Referer: http://self.cust.edu.cn/selfservice/login.jsf" );
        
        

        // FIRST: get login.jsf
        curl_easy_setopt( curl, CURLOPT_URL, post_url );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, chunk );
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );
        
        res = curl_easy_perform( curl );
        
        // SECOND: get code.jsp
        curl_easy_setopt( curl, CURLOPT_URL, get_url );
        
        res = curl_easy_perform( curl );
        
        // THIRD: post login.jsf
        postchunk = curl_slist_append( postchunk, "User-Agent: Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.9) Gecko/20100401 Ubuntu/9.10 (karmic) Firefox/3.5.9" );
        postchunk = curl_slist_append( postchunk, "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8" );
        postchunk = curl_slist_append( postchunk, "Accept-Language: en-us,en;q=0.5" );
        postchunk = curl_slist_append( postchunk, "Accept-Encoding: gzip,deflate" );
        postchunk = curl_slist_append( postchunk, "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7" );
        postchunk = curl_slist_append( postchunk, "Keep-Alive: 300" );
        postchunk = curl_slist_append( postchunk, "Connection: keep-alive" );
        postchunk = curl_slist_append( postchunk, "Referer: http://self.cust.edu.cn/selfservice/login.jsf" );
        postchunk = curl_slist_append( postchunk, "Content-Type: application/x-www-form-urlencoded" );
        
        curl_easy_setopt( curl, CURLOPT_POST, 1 );
        curl_easy_setopt( curl, CURLOPT_URL, post_url );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );    
        
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, content );
        
        res = curl_easy_perform( curl );
        
        curl_easy_cleanup( curl );
    }    
    
    return 0;
}













