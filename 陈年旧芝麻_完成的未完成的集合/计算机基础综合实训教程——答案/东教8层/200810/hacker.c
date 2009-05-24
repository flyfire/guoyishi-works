#include <stdio.h>
main()
{
	char g;
	int a,b,c,d;
	a=0;b=0;c=0;d=0;
	printf("Please Type!\n");
	while((g=getchar())!='\n')
	{
		if((g>=65&&g<=90)||(g>=97&&g<=122))
			a++;
		if(g==32)
			b++;
		if(g>=48&&g<=57)
			c++;
		else
			d++;
	}
	printf("English=%d\nSpace=%d\nNumber=%d\nOther=%d\n",a,b,c,d);
}