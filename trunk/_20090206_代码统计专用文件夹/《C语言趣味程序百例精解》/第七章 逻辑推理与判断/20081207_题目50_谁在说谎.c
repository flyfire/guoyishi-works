#include <stdio.h>
int main()
{
	int a,b,c;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				if((a&&!b)||(!a&&b))
					if((b&&!c)||(!b&&c))
						if((c&&!a&&!b)||(!c&&a+b!=0))
						{
							printf("Zhang San told a %s.\n",a?"truth":"lie");
							printf("Li Si told a %s.\n",b?"truth":"lie");
							printf("Wang Wu told a %s.\n",c?"truth":"lie");
						}

}