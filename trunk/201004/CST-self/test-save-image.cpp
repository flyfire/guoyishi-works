#include <iostream>
#include <curl/curl.h>

using namespace std;

const char* image_url = "http://self.cust.edu.cn/selfservice/code.jsp";
const char* file_name = "image.jpg";

size_t writer( void* ptr, size_t size, size_t nmemb, void* stream ) {
}

int main() {
    CURL* curl;
    CURLcode res;
    FILE* fp;
    
    curl = curl_easy_init();
    if ( !curl ) {
        cout << "cURL init error!" << endl;
        return( -1 );
    }
    fp = fopen( file_name, "wb" );
    if ( !fp ) {
        cout << "File can't be opened!" << endl;
        return( -1 );
    }
    
    curl_easy_setopt( curl, CURLOPT_WRITEFUNCTION, NULL );
    curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
    curl_easy_setopt( curl, CURLOPT_URL, image_url );
    
    res = curl_easy_perform( curl );
    if ( res ) {
        cout << "Can't grab the image!" << endl;
    }
    
    curl_easy_cleanup( curl );
    fclose( fp );
    
    return 0;
}
