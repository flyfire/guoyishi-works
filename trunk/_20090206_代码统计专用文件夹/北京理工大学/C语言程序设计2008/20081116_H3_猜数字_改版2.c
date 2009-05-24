#include "stdio.h"
#include "math.h"
main()
{    int i,j,n;
     n=0;
     for(j=1;;)
     {    scanf("%d",&i);
          if(i==0)
          break;
          n+=pow(2,i-1);
     }
     printf("%d\n",n);
} 