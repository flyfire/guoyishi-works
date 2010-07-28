////////////////////////////////////
// Date:    2010-07-28
// Author:  Yishi Guo
// For:     CAPTCHA images download
////////////////////////////////////
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>

using namespace std;

string g_image_url = "http://meiyou.org/meiyou.gif";
string g_extension_name = "jpg";
string g_prefix = "";
string g_delimiter = "-";
int    g_times = 423;
bool   g_is_use_time = false;

//////////////////////////////////////
////// X2X Functions /////////////////
template <typename T>
int str2num( T str ) {
  int value;
  stringstream ss;
  ss << str;
  ss >> value;
  return value;
}

template <typename T1, typename T2>
T2 num2str( T1 num ) {
  T2 str;
  stringstream ss;
  ss << num;
  ss >> str;

  return str;
}

//////////////////////////////////////
////// Print Functions ///////////////
void test_variables( void ) {
  cout << "URL: " << g_image_url << endl;
  cout << "EXT: " << g_extension_name << endl;
  cout << "TIM: " << g_times << endl;
  cout << "PRE: " << g_prefix << endl;
  cout << "ISU: " << g_is_use_time << endl;
}

//////////////////////////////////////
////// Get Functions /////////////////
string get_time( string time_format = "%Y-%m-%d-%H-%M-%S" ) {
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];
  time( &rawtime );
  timeinfo = localtime( &rawtime );

  strftime( buffer, 80, time_format.c_str(), timeinfo );

  return string( buffer );
}

string get_file_name( string prefix, bool is_use_time, int n, string extension_name ) {
  string file_name = "";
  if ( !prefix.empty() ) {
    file_name += prefix;
    file_name += g_delimiter;
  }
  if ( is_use_time ) {
    file_name += get_time();
    file_name += g_delimiter;
  }
  file_name += num2str<int,string>( n );
  file_name += ".";
  file_name += extension_name;

  return file_name;
}

//////////////////////////////////////
////// Set Functions /////////////////

void set_options( int argc, char** argv ) {
  // options:
  const char* image_url_opt = "--url=";
  int image_url_opt_len = (int)strlen( image_url_opt );
  const char* extension_name_opt = "--extension=";
  int extension_name_opt_len = (int)strlen( extension_name_opt );
  const char* times_opt = "--times=";
  int times_opt_len = (int)strlen( times_opt );
  const char* prefix_opt = "--prefix=";
  int prefix_opt_len = (int)strlen( prefix_opt );
  const char* is_use_time_opt = "--use-time";
  int is_use_time_opt_len = (int)strlen( is_use_time_opt );

  // Set the options:
  for ( int i = 0; i < argc; ++i ) {
    if ( strncmp( argv[i], image_url_opt, image_url_opt_len ) == 0 ) {
      g_image_url = string(argv[i]+image_url_opt_len );
    } else if ( strncmp( argv[i], extension_name_opt, extension_name_opt_len ) == 0 ) {
      g_extension_name = string( argv[i]+extension_name_opt_len );
    } else if ( strncmp( argv[i], times_opt, times_opt_len ) == 0 ) {
      g_times = str2num( argv[i]+times_opt_len );
    } else if ( strncmp( argv[i], prefix_opt, prefix_opt_len) == 0 ) {
      g_prefix = string( argv[i]+prefix_opt_len );
    } else if ( strncmp( argv[i], is_use_time_opt, is_use_time_opt_len ) == 0 ) {
      g_is_use_time = true;
    }
  }
}

int main( int argc, char** argv ) {
  CURL* curl;
  CURLcode res;
  FILE* fp;

  curl = curl_easy_init();
  if ( !curl ) {
    cerr << "cURL init error!" << endl;
    return ( -1 );
  }

  set_options( argc, argv );

  for ( int i = 0; i < g_times; ++i ) {
    const char* file_name = get_file_name( g_prefix, g_is_use_time, i, g_extension_name ).c_str();  // get the image file's name
    fp = fopen( file_name, "wb" );
    if ( !fp ) {
      cerr << "File: [" << file_name << "] can not be opened!" << endl;
      return ( -1 );
    }
    curl_easy_setopt( curl, CURLOPT_WRITEDATA, fp );
    curl_easy_setopt( curl, CURLOPT_URL, g_image_url.c_str() );

    res = curl_easy_perform( curl );

    fclose( fp );  // close the file point
  }

  curl_easy_cleanup( curl );

  test_variables();

  return 0;
}
