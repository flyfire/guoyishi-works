// Reference:  http://curl.haxx.se/libcurl/c/http-post.html
//             guoyishi-works/Learning OpenCV/Exercise-4-8.cpp

#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <curl/curl.h>

using namespace std;

const char* post_url  =  "http://self.cust.edu.cn/selfservice/login.jsf";
const char* cookie    =  "";
const char* username  =  "en0201101";
const char* password  =  "0000";
const char* code      =  "";
const char* usertype  =  "1";

string post_data =  "";

bool is_debug = false;

char* i2c( int i ) {
    stringstream str;
    str << i;
    return (char*)str.str().data();
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

const char* get_cookie_opt() {
    string cookie_opt = "";
    cookie_opt += "JSESSIONID=";
    cookie_opt += cookie;
    cout << "\tCOOKIE: \t" << cookie << endl;
    cookie_opt += "";
    
    return cookie_opt.data();
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
    cout << "Usege: post --cookie=<cookie>\n"
         << "\t--code=<code>\n"
         << "\t[--post-url=<post url>]\n"
         << "\t[--username=<username>]\n"
         << "\t[--password=<password>]\n"
         << "\t[--usertype=<usertype>]\n"
         << "\t[--debug]\n"
         << endl;
    return;
}

void debug_show() {
    cout << "==== DEBUG INFO ====" << endl;
    cout << "post-url : " << post_url << "\n"
            "cookie   : " << cookie   << "\n"
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

int main( int argc, char** argv ) {
    CURL *curl;
    CURLcode res;
    
    // Check for the options:
    const char* post_url_opt = "--post-url=";
    int post_url_opt_len     = (int)strlen( post_url_opt );
    const char* cookie_opt   = "--cookie=";
    int cookie_opt_len       = (int)strlen( cookie_opt );
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
    
    // Get the options:
    for ( int i = 0; i < argc; ++i ) {
        if ( strncmp( argv[i], post_url_opt, post_url_opt_len ) == 0 ) {
            post_url = argv[i] + post_url_opt_len;
        } else if ( strncmp( argv[i], cookie_opt, cookie_opt_len ) == 0 ) {
            cookie = argv[i] + cookie_opt_len;
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
        }
    }
    
    if ( strcmp( cookie, "" ) == 0 ) {
        cout << "Error cookie!" << endl;
        help_info();
        return ( -1 );
    } else if ( strcmp( code, "" ) == 0 ) {
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
        post_data_show( post_data );
    }
    
    curl = curl_easy_init();
    if ( !curl ) {
        cout << "Could not init the curl!" << endl;
        return ( -2 );
    } else {
        const char* content = string(post_data).data();
        cout << content << endl;
        struct curl_slist *chunk = NULL;
        
        chunk = curl_slist_append( chunk, "Connection: keep-alive" );
        chunk = curl_slist_append( chunk, "User-Agent: Mozilla/5.0(2010-04-24)" );
        chunk = curl_slist_append( chunk, "Accept: application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5" );
        chunk = curl_slist_append( chunk, "Referer: http://self.cust.edu.cn/selfservice/login.jsf" );
        chunk = curl_slist_append( chunk, "Accept-Encoding: gzip,deflate,sdch" );
        chunk = curl_slist_append( chunk, "Accept-Language: en-US,en;q=0.8" );
        chunk = curl_slist_append( chunk, "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.3" );
        // chunk = curl_slist_append( chunk, get_content_length_opt( post_data ) );
        chunk = curl_slist_append( chunk, "Cache-Control: max-age=0" );
        chunk = curl_slist_append( chunk, "Origin: http://self.cust.edu.cn" );
        chunk = curl_slist_append( chunk, "Content-Type: application/x-www-form-urlencoded" );
        // chunk = curl_slist_append( chunk, get_cookie_opt() );
        
        curl_easy_setopt( curl, CURLOPT_URL, post_url );
        res = curl_easy_setopt( curl, CURLOPT_HTTPHEADER, chunk );
    cout << "==== COOKIE: ====" << endl;
    cout << get_cookie_opt() << endl;
        curl_easy_setopt( curl, CURLOPT_COOKIE, get_cookie_opt() );
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, content );
        curl_easy_setopt( curl, CURLOPT_POSTFIELDSIZE, (long)strlen(content) );
    cout << "#5.5" << endl;
    cout << "Length: " << (long)strlen(content) << endl;
        res = curl_easy_perform( curl );
    cout << "#6" << endl;
        
        curl_easy_cleanup( curl );
    }
    
    
    return 0;
}
