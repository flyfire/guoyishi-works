#include <stdio.h>
int main()
{
	int a,b,c,d,e;
	for(a=1;a>=0;a--)
		for(b=1;b>=0;b--)
			for(c=1;c>=0;c--)
				for(d=1;d>=0;d--)
					for(e=1;e>=0;e--)
						if((a==1&&b==1)||a==0)
							if(d!=e)
								if(b!=c)
									if(c==d)
										if((e==1&&a==1&&d==1)||e==0)
											printf("%d--%d--%d--%d--%d\n",a,b,c,d,e);

}// I have no answer ,so the above is "right" ? WHY NOT?