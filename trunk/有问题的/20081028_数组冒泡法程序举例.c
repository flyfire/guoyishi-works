#include <stdio.h>
#define SIZE 10
void main()
{
	int i,j,temp,str[SIZE]={0};
	printf("===��ð�ݷ�������===\n������������%d������\n\n",SIZE);
	for(i=0;i<SIZE;i++)
	{
		printf("���������%d������\n",i+1);/*???????Ϊ�ε����������ʱ������ʱ�����ִ��󣿣�������������*/
		scanf("%d",&str[i]);/*???????���������ж��Ƿ�����������ֶ���������������������*/
	}
	printf("\n���������Ϊ��\n");
	for(i=0;i<SIZE;i++)
		printf("  %d",str[i]);
	printf("\n\n����Ϊ��ת����\n");
	printf("1>�������鰴���ɴ�С��˳������Ϊ��\n");
	for(j=SIZE;j>0;j--)
	{
		for(i=0;i<j;i++)
		{
			if(str[i]<str[i+1])
			{
				temp=str[i];
				str[i]=str[i+1];
				str[i+1]=temp;
			}
		}
	}
	for(i=0;i<SIZE;i++)
		printf("  %d",str[i]);
	printf("\n2>�������鰴����С�����˳������Ϊ��\n");
	for(i=SIZE-1;i>=0;i--)
		printf("  %d",str[i]);
	printf("\n\n\n\nPower By iStone \n\n\n\n");
}

