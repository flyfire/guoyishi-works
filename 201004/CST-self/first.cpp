// Reference:  http://curl.haxx.se/libcurl/c/httpcustomheader.html

#include <iostream>
#include <curl/curl.h>

const char* image_url = "http://192.168.222.222/selfservice/code.jsp";

int main( int argc, char** argv ) {
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if ( curl ) {
        struct curl_slist *chunk = NULL;
        
        // chunk = curl_slist_append( chunk, "User-Agent: Yishi Guo" );
        // chunk = curl_slist_append( chunk, "Referer: http://meiyou.org" );
        // chunk = curl_slist_append( chunk, "Accept: */*" );
        
        // request with the built-in Accept:
        curl_easy_setopt( curl, CURLOPT_URL, image_url );
        curl_easy_setopt( curl, CURLOPT_VERBOSE, 1L );
        res = curl_easy_perform( curl );
        
        // redo request with our own custom Accept:
        // res = curl_easy_setopt( curl, CURLOPT_HTTPHEADER, chunk );
        // res = curl_easy_perform( curl );
        
        // always cleanup
        curl_easy_cleanup( curl );
        
    }
    
    return 0;
}
