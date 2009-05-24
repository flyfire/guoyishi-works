#include <stdio.h>
int main()
{
	int i,str[6];
	char ch;
	for(str[0]=0;str[0]<=1;str[0]++)
		for(str[1]=0;str[1]<=1;str[1]++)
			for(str[2]=0;str[2]<=1;str[2]++)
				for(str[3]=0;str[3]<=1;str[3]++)
					for(str[4]=0;str[4]<=1;str[4]++)
						for(str[5]=0;str[5]<=1;str[5]++)
							if(str[0]+str[1]>=1)
								if(str[0]!=str[3])
									if(str[0]+str[4]+str[5]>=2)
										if(str[1]==str[2])
											if(str[2]!=str[3])
												if(str[3]==1||(str[3]==0&&str[4]==0))
													for(i=0,ch='a';i<6;i++,ch++)
														if(str[i])
															printf("%c go\n",ch);
														else
															printf("%c not go\n",ch);
}// "1" go  "0" not go!
