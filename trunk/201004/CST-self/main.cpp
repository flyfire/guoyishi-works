/////////////////////////////////////
// !!!!!!! COPY !!!!!!!!!!!!!!!!!!!!!!
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include "CST.hpp"

using namespace std;

void configuration( const char* file_name ) {
	int arr[101]={0}; //arr[0] is length (=100) ,from arr[1]~arr[100]
	CharCatalog* test;
	char characters[4] = {'?','?','?','?'};
	int x;
	test = init_char(); 
	IplImage* in;
	
	try {
	    in = cvLoadImage( file_name );
	} catch (cv::Exception) {
	    cerr << "Couldn't load image!" << endl;
	    return;
	}
	IplImage* out = cvCreateImage(
						cvGetSize(in),
						IPL_DEPTH_8U,
						1);

	// cvNamedWindow("CST_CAPUTER",CV_WINDOW_AUTOSIZE);

	cvCvtColor(in,out,CV_RGB2GRAY); 

	point2image(out);

	// cvShowImage("CST_CAPUTER",out);

	// printPixel(out);

	accumulatePoint(out,arr);


	//data_process
	recognize_char(test,arr,characters);
	// printf("length:%d\n",arr[0]);
	// for(x = 1; x <= arr[0];x++){
	//     printf("arr[%d]:%d ",x,arr[x]);
	// }
	// printf("\n");
	printf( "%s\t: %c%c%c%c\n", file_name, characters[0],characters[1],characters[2],characters[3]);

	// cvWaitKey(0); //wait
	//clear
	cvReleaseImage(&in);
	cvReleaseImage(&out);
	// cvDestroyWindow("CST_CAPUTER");
}

bool is_pic( const char* file_name ) {
    int len = strlen( file_name );
    if ( len < 4 ) {
        return false;
    }
    
    return true;
}

int run( const char* dir_name = "./" ) {
    int count = 0;
    DIR *dp;
    struct dirent *ep;
    
    dp = opendir( dir_name );
    if ( dp != NULL ) {
        while ( ep = readdir( dp ) ) {
            // cout << "==== d_name ====" << endl;
            // cout << ep->d_name << endl;
            if ( is_pic( ep->d_name ) ) {
                string file_name = "";
                file_name += dir_name;
                file_name += ep->d_name;
                
                // cout << "==== FILE NAME ====" << endl;
                // cout << file_name << endl;
                
                configuration( file_name.c_str() );
                ++count;
            } else {
                continue;
            }
        }
        (void)closedir( dp );
    } else {
        perror( "Couldn't open the directory!" );
    }
    
    return count;
}
            

int main(int argc,char** argv)
{
    time_t start, end;
    time( &start );
    int count = 0;
    if ( argc >= 2 ) {
        count = run( argv[1] );
    } else {
        count = run();
    }
    time( &end );
    
    double dif;
    dif = difftime( end, start );
    printf( "COUNT: %d\n", count );
    printf( "TIME: %.2lf seconds\n", dif );

	return 0;
}
