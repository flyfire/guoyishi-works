#include<math.h>
#include<stdio.h>
void main()
{
long i,n,temp;
printf("%d ", 2);
for(n=3; n<=10000000; n+=2)
{
temp=sqrt(n);
for(i=3; i<=temp; i+=2)//改成+2
if(n %i == 0)
break;
printf("%d ",n);//之前的判断去掉
printf("\n");
}
}