#include <stdio.h>
void main()
{
	int i,sign,n;
	float deno,sum; /*�����ø�����*/
	printf("Please Type In The N !\n"); 
	scanf("%d",&n); /*�õ�n��ֵ*/
	for(i=2,sum=1,sign=1;i<=n;i++)
	{
		sign=(-1)*sign;/*���ӣ����������*/
		deno=(float)sign/i; /*��*/
		sum=deno+sum;/*���*/
	}
	printf("The N Is %d\nThe Sum Is %f\n",n,sum); /*������*/

}
/*2008.10.13 14:37���Գɹ�*/