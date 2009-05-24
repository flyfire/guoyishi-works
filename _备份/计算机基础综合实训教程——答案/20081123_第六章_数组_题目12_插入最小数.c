#include <stdio.h>
void main(void)
{
	int str[10];
	int temp,i,k;
	printf("put your ten number:\n");
	for(i=0;i<10;i++)		//get your array
	{
		printf("put No.%d: ",i+1);
		scanf("%d",&str[i]);
	}
	for(i=1,temp=str[0];i<10;i++)		//get the smallest number
	{
		if(str[i]<temp)
		{
			temp=str[i];
			k=i;
		}
	}
	printf("The smallest is str[%d]=%d\n",k,str[k]);
	for(;k>0;k--)			//change
	{
		str[k]=str[k-1];
	}
	str[0]=temp;			//put the smallest to the No.0
	for(i=0;i<10;i++)		//print the array
		printf("  %d",str[i]);
	printf("\n");			//put enter
}