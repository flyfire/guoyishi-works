#include <stdio.h>

int count=0;

int main()
{
	int fun(int *p);
	int i;
	int a[]={1,2,3,4,5,6};
	for(a[1]=a[0]+1;a[1]<=5;++a[1])
		for(a[2]=a[1]+1;a[2]<=5;++a[2])
			for(a[3]=a[0]+1;a[3]<=5;++a[3])
				for(a[4]=a[3]+1;a[4]<=5;++a[4])
					if(a[1]<a[4]&&a[2]<a[5]&&fun(a))
					{
						++count;
						for(i=0;i<=5;i++)
							printf((i==5||i==2)?"%d\n":"%d",a[i]);
						printf("\n");
					}
	printf("The count is %d.\n",count);

}

int fun(int a[])
{
	int i,j;
	for(i=0;i<5;i++)
		for(j=1;j<6;j++)
		{
			if(i!=j&&a[i]==a[j])
				return (0);
		}
	return (1);
}