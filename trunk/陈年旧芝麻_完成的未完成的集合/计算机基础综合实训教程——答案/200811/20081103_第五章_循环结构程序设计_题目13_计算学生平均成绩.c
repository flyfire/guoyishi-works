#include <stdio.h>
void main()
{
	int i,r=0;
	float k,sum=0;
	printf("===����ѧ��ƽ���ɼ�===\n");
	printf("��������ѧ���ɼ���\n\n");
	for(i=1;;i++)
	{
		printf("���������%d���˵ķ���:\n",i);
		scanf("%f",&k);
		sum+=k;
		if(k>=90)
			r++;
		else if(k<0)
			break;

	}
	printf("\n\n%d���˵��ܷ�Ϊ��%0.2f\nƽ����Ϊ��%0.2f\n90�����ϵ���Ϊ��%d��\n",i,sum,sum/i,r);
	printf("\n\n\nлл����ʹ�ã�\n\n\n");


}
