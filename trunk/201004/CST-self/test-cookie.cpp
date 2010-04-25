#include <iostream>
#include <curl/curl.h>
using namespace std;

const char* post_url = "http://self.cust.edu.cn/selfservice/login.jsf";
const char* get_url = "http://self.cust.edu.cn/selfservice/code.jsp";
const char* cookie_file_name = "./self_cookie.txt";
const char* content = "cmdForm%3Ausername=youandme&cmdForm%3Apassword=0000&cmdForm%3Acode=AAAA&cmdForm%3Ausertype=1&cmdForm%3A_idJsp34=%E7%99%BB%E5%BD%95&cmdForm_SUBMIT=1&jsf_sequence=1&cmdForm%3A_link_hidden_=";


int main() {
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
    
    return 0;
}
    
    
    

