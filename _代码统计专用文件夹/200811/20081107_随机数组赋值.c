#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void main()
{
	int h,i=0,j,k=0,p,d;
	int str[10],str2[10],strc[10];
	printf("===����������ֵ===\n");
	printf("������������,��������һ��10λ����:\n");
	for(i=0;i<10;i++)
		strc[i]=21;
	i=0;
qq:
		printf("���������%d������:",i+1);
		scanf("%d",&str[i]);

	//	printf("�Ѿ�����qq\n");
	
	//	printf("str[%d]=%d\n",i,str[i]);//����!
		srand(time(NULL));
		p=rand();
		p+=123;
		p*=str[i];
		p%=10;
	//	printf("p���ڵ�ֵΪ:%d\n\n",p); //����!
	//	scanf("%d",&d);			//����!
			strc[i]=p;
			printf("�ж�p�Ƿ��ظ�strc[%d]=%d  p=%d  k=%d\n",i,strc[j],p,k);
			for(h=0;h<10;h++)
			{
			//	printf("h���ڵ�ֵ��:%d\n",h);
				if(j==h)
					continue;
				else if(p==strc[h])
				{
					printf("��Ҫ����qq��!\n");
					goto qq;
				}
			}
			i++;
			if(i>=10)
				goto end;
			goto qq;
		str2[p]=str[i];
		printf("\nstr[%d]=str[%d]:%d\n",p,i,str[i]);
end:
	printf("\n������ĵ�һ������Ϊ:\n");
	for(i=0;i<10;i++)
	{
		printf("  %d",str[i]);
	}
	printf("\n����������Ѿ������������ֵ,���str2:\n");
	for(i=0;i<10;i++)
	{
		printf("  %d",str2[i]);
	}
	printf("\n\nлл����ʹ��!\n\n");
	scanf("%d",&d);

}
