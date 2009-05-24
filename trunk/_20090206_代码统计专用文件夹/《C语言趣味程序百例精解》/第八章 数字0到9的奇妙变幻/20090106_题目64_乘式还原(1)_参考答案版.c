#include <stdio.h>

int main()
{
	int judge(long q,char *pflag);
	void print(a,b,s1,s2,s3);
	long i,j,k,l,m,n,term,t1,t2,t3;
	int flag;
	for(i=0;i<=4;i++)
		for(j=5;j<=9;j++)
			for(k=0;k<=4;k++)
			{
				term=100*i+10*j+k;
				for(flag=0,n=0;n<4&&!flag;)
					flag=judge((t3=++n*100*term)/100,"001");

				if(flag)
				{
					for(flag=0,m=0;m<4&&!flag;)
						flag=judge((t2=++m*10*term)/10,"1100");

					if(flag)
					{
						for(flag=0,l=5;l<9&&!flag;)
							flag=judge(t1=++l*term,"0000");

						if(flag&&judge(t1+t2+t3,"00101"))
							print(term,n*100+m*10+l,t1,t2,t3);
					}
				}
			}
}

int judge(long q,char *pflag)
{
	while(q!=0&&*pflag!=NULL)
		if(*pflag-'0'!=(q%10>=5?1:0))
			return 0;
		else 
		{
			q/=10;
			++pflag;
		}
		if(q==0&&*pflag==NULL)
			return 1;
		else return 0;
}

void print(a,b,s1,s2,s3)
long a,b,s1,s2,s3;
{
	printf("\n        %ld\n",a);
	printf("*)      %ld\n",b);
	printf("------------\n");
	printf("       %ld\n      %ld\n      %ld\n",s1,s2/10,s3/100);
	printf("------------\n");
	printf("      %ld\n",a*b);
}