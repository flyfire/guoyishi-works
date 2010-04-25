// Reference: curl-library/msg00983.html
//            http://curl.haxx.se/libcurl/c/lurl_easy_escape.html
#include <curl/curl.h>
#include <iostream>
using namespace std;

int main() {
    CURL *curl;
    CURLcode res;
    const char* url = "cmdForm:username=en0201101&cmdForm:password=0000&cmdForm:code=CUST";
    
    curl = curl_easy_init();
    if ( curl ) {
        char* urlencode = curl_easy_escape( curl, url, 0 );
        
        cout << "URL: " << url << endl;
        cout << "URLencode: " << urlencode << endl;
    }
    
    return 0;
}
