#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main( int argc, char** argv ) {
    DIR *dp;
    struct dirent *ep;
    const char* dir_name = "";
    
    if ( argc >= 2 ) {
        dir_name = argv[1];
    } else {
        dir_name = "/home/e10101/Programming/201004/";
    }
    
    dp = opendir( dir_name );
    if ( dp != NULL ) {
        while ( ep = readdir( dp ) ) {
            puts( ep->d_name );
        }
        (void) closedir( dp );
    } else {
        perror( "Couldn't open the directory!" );
    }
    
    return 0;
}
