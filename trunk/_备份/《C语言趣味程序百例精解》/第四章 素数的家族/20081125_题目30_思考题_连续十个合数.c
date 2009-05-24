#include <stdio.h>
#include <math.h>
void main(void)
{
	int i,j,k,f1,f2,m;
	for(i=1;;i++)
	{
		for(j=2,f1=0;j<=sqrt(i);j++)	//judge if the "i" is not a prime number
			if(i%j==0)
			{
				f1=1;					//f1: prime or not
				break;
			}
		if(f1)							//if "i" is
		{
			k++;						//k++:sum number plus one
			if(f2)						//f2:new or not
			{
				m=i;					//put the first address to "m"
				
			}
			f2=0;						//tell it is not a prime number
		}
		else
			if(k)						//clear
			{
				k=0;
				f2=1;
			}
		if(k>=10)						//break when we get it
			break;

	}
		for(i=m;i<m+10;i++)				//print the result
			printf("%5d",i);
		printf("\n");					//we get it!
}
