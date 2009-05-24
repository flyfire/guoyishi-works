#include <stdio.h>
#include <math.h>

int main()
{
	float eq(float k[],float);
	int i;
	float a,b,s,min;
	float k[4];
	int flag=1;
	printf("[k1]x3+[k2]x2+[k3]x+[k4]=0,[a,b],min?:\n");
	for(i=0;i<4;i++)
	{
		scanf("%f",&k[i]);
	}
	scanf("%f%f%f",&a,&b,&min);
	if(eq(k,a)*eq(k,b)>0)
		printf("Wrong,no result!\n");
	else if(eq(k,a)==0)
		printf("a=%d is result!\n",a);
	else if(eq(k,b)==0)
		printf("b=%d is result!\n",b);
	else
	{
		printf("Right!\n");
		do
		{
			s=(a+b)/2.0;
			if(eq(k,s)==0)
			{
				printf("s=%d is the result!\n",s);
				break;
			}
			else
			{
				(eq(k,s)*eq(k,a)<0)?(b=s):(a=s);
			}
			printf("TEST!a=%f,b=%f,min=%f,b-a=%f\n",a,b,min,b-a);
		}while(b-a>min);
		printf("%f<X<%f\n",a,b);
	}


}

float eq(float k[],float s)
{
	float m;
	m=k[0]*pow(s,3)+k[1]*pow(s,2)+k[2]*s+k[3];
	return (m);
}