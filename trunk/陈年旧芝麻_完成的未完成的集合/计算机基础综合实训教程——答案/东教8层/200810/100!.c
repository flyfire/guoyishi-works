#include <stdio.h>
void main()
{
	int n,i;  /*n��������i�����i��*/
	float d=1;  /*���d*/
	printf("��n�Ľ׳ˣ�������\n����n��");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		d=d*i;
	}
	printf("%d�Ľ׳˽���ǣ�%-9.2f\n",n,d);
}