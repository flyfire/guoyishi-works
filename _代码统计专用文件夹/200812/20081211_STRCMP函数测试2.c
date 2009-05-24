#include <string.h> 
#include <stdio.h> 

int main(void) 
 { 
    char *buf1,*buf2,*buf3; 
    int ptr; 
	
	scanf("%s",buf1);
	scanf("%s",buf2);
	scanf("%s",buf3);

    ptr = strcmp(buf2, buf1); 
    if (ptr > 0) 
       printf("buffer 2 is greater than buffer 1\n"); 
    else 
       printf("buffer 2 is less than buffer 1\n"); 

    ptr = strcmp(buf2, buf3); 
    if (ptr > 0) 
       printf("buffer 2 is greater than buffer 3\n"); 
    else 
       printf("buffer 2 is less than buffer 3\n"); 

    return 0; 
 } 
