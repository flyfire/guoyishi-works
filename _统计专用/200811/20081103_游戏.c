#include <stdio.h>
void main()
{
	int a,b,c,d;
	int x,y,z,w;
	int i=0,j=0;
	int t=0,m=0;		//t����ʾ�Ƿ��ǵ�һ����
	printf("������������ĸ�����:\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a+=23132;
	b+=43415;
	c+=23213;
	d+=31474;
	a%=10;
	b%=10;
	c%=10;
	d%=10;
start:
	if(t==0)
		printf("������������,�Ѿ�����õ�һ����λ��,������!\n\n");
	else
		printf("���Ѿ�������%d��,�벻Ҫ����,�ٽ�����,��������,����!\n\n",m);
	scanf("%d%d%d%d",&x,&y,&z,&w);
	if(a==x&&b==y&&c==z&&d==w)
	{
		printf("\n\n��ϲ���¶���!!��̫ţB��!!\n\n");
		printf("��ȷ�����:%d%d%d%d",a,b,c,d);
		goto end;
	}
	i=0;
	j=0;
	if(a==x)
		i++;
	if(b==y)
		i++;
	if(c==z)
		i++;
	if(d==w)
		i++;
	if(a==x||a==y||a==z||a==w)
		j++;
	if(b==x||b==y||b==z||b==w)
		j++;	
	if(c==x||c==y||c==z||c==w)
		j++;
	if(d==x||d==y||d==z||d==w)
		j++;
	t++;
	m++;
	printf("�������������һ������%d��,����˳����ȫ��ȷ����%d��\n\n",j,i);
	goto start;
end:
	printf("�ټ�!");

	
}