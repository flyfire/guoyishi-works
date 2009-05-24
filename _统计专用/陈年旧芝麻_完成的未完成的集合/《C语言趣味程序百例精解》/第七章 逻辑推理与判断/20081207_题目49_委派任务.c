#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	for(a=0;a<=1;a++)
		for(b=0;b<=1;b++)
			for(c=0;c<=1;c++)
				for(d=0;d<=1;d++)
					for(e=0;e<=1;e++)
						for(f=0;f<=1;f++)
							if(a==1||b==1)
								if(a!=d)
									if(a+e+f>=2)
										if(b==c)
											if(c+d==1)
												if((d==0&&e==0)||d==1)
												{
													printf("%d--%d--%d--%d--%d--%d\n",a,b,c,d,e,f);
												}



}// "1":go "0":not go ,that is easy!