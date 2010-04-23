////////////////////////////////////////////////////////////
// Data:       2010-04-23
// Coder:      Yishi Guo
// Reference:  http://curl.haxx.se/libcurl/c/simple.html
////////////////////////////////////////////////////////////
#include <iostream>
#include <curl/curl.h>
using namespace std;

int main( void ) {
    // test for output info
    // cout << "Hello World!" << endl;
    
    CURL *curl;
    CURLcode res;
    
    curl = curl_easy_init();
    if ( curl ) {
        curl_easy_setopt( curl, CURLOPT_URL, "http://self.cust.edu.cn/selfservice/code.jsp" );
        res = curl_easy_perform( curl );
        
        // always cleanup
        curl_easy_cleanup( curl );
    }
    
    return 0;
}
