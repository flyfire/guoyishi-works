#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{	
	int str[10],str2[10],strc[10];
	int i,q,j,k,flag;
	printf("===һ�������������һ����===\n");
	for(i=0;i<10;i++)		//���ȸ��洢pֵ�����鸳ֵ
		strc[i]=21;
	for(i=0;i<10;i++)
	{
		printf("�������%d������:",i+1);
		scanf("%d",&str[i]);
		printf("\n");
		srand(time(NULL));	//����ʱ����������
		q=rand();			//�����ֵ��ֵ��q
		j=0; 
		while(j<10)			//����ѡ�񣬵�jΪ11��ʱ��Ҳ��˵��qʹû���ظ��ġ�
		{ 
			q+=1;
			q%=10;
			strc[i]=q;			//��qֵ����strc����
			for(j=0;j<10;j++)	//�ж�qֵ֮ǰ�Ƿ����!
			{
				if(i==j)
					continue;
				if(q==strc[j])
					break; 
			}
		}
		str2[q]=str[i];		//����str����str2
	}
	printf("\n�����һ������Ϊ:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str[i]);
	printf("\n������������Ķ�Ӧ����:\n");
	for(i=0,k=0;i<10;i++)
	{
		printf("%2d--%-4d",i+1,strc[i]+1);
		k++;
		if(k-5==0)			//һ����ʾ5����
			printf("\n");
	}
	printf("\nת����:");
	printf("\n����ڶ�������Ϊ:\n");
	for(i=0;i<10;i++)
		printf("%d  ",str2[i]);
	printf("\n\nлл����ʹ��!\n\n");
		

}