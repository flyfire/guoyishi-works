#include <stdio.h>
#include <math.h>
void main(void)
{
	int i8,i5,i3,i2,i1;
	int k1,k2,k3,k5,k8;
	float sum=0,temp;
	printf("===怎样存钱收益最大===\n");
	for(i8=0;i8<=2;i8++)
		for(i5=0;i5<=(20-i8*8)/5;i5++)
			for(i3=0;i3<=(20-i8*8-i5*5)/3;i3++)
				for(i2=0;i2<=(20-i8*8-i5*5-i3*3)/2;i2++)
				{
					i1=20-i8*8-i5*5-i3*3-i2*2;
					temp=2000*pow(1+8*0.0084*12,i8)
						*pow(1+5*0.0075*12,i5)
						*pow(1+3*0.0069*12,i3)
						*pow(1+2*0.0066*12,i2)
						*pow(1+1*0.0063*12,i1);
					if(temp>sum)	//比较该值与sum值的大小
					{
						sum=temp;
						k8=i8;
						k5=i5;
						k3=i3;
						k2=i2;
						k1=i1;
					}	//当有一个比原先的sum大的值,截取该值的参数
				}
	printf("存入八年期限为%d次\n",k8);
	printf("存入五年期限为%d次\n",k5);
	printf("存入三年期限为%d次\n",k3);
	printf("存入两年期限为%d次\n",k2);
	printf("存入一年期限为%d次\n",k1);
	printf("20年后的最大收益为%.2f元\n",sum);
	printf("\n\n谢谢您的使用!\n\n");
}