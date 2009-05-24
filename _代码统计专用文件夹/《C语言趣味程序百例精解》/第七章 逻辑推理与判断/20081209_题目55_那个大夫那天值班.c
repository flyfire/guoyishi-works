#include <stdio.h>
int main()
{
	int a,b,c,d,e,f,g;
	for(a=1;a<=7;a++)
		for(b=1;b<=7;b++)
			for(c=1;c<=7;c++)
				for(d=1;d<=7;d++)
					for(e=1;e<=7;e++)
						for(f=1;f<=7;f++)
							for(g=1;g<=7;g++)
								if(a-c==1&&d-e==2&&g-b==3&&f==4&&((b<f&&f<c)||(f<b&&c<f)))
									if(a!=b&&a!=c&&a!=d&&a!=e&&a!=f&&a!=g)
										if(b!=c&&b!=d&&b!=e&&b!=f&&b!=g)
											if(c!=d&&c!=e&&c!=f&&c!=g)
												if(d!=e&&d!=f&&d!=g)
													if(e!=f&&e!=g)
														if(f!=g)
															{
																printf("a--b--c--d--e--f--g\n");
																printf("%d--%d--%d--%d--%d--%d--%d\n\n",a,b,c,d,e,f,g);
															}
}