#include <stdio.h>
void main(void)
{
	int a[11]={0,32323,2,33433,4,6323,452,63,82,0,7};
	int *p,*p2,*p3;
	int i;
	double b[12]={12,33,44,4};
	double *q=b;
	p=a+1;
	p=&a[1];
	p2=&a[5];
	p3=&a[10];

	for(i=0;i<11;i++)
		printf("&a[%d]=%x\t*&a[%d]=%x\n",i,&a[i],i,*&a[i]);


	printf("a[0]=%d,a[1]=%d,a[2]=%d,p=%X,*p=%d\n",a[0],a[1],a[2],p,*p);
	printf("p2=%x,p3=%x,*p2=%X,*p3=%x,\np3-p2=%d,*p3-*p2=%d\n",p2,p3,*p2,*p3,p3-p2,*p3-*p2);
	printf("*a=%d,&a[3]=%x,a[6]=%x,&*a=%d\n",*a,&a[3],a[6],&*a);
	printf("&*p2=%x,&p2=%x\n",&*p2,&p2);

	printf("sizeof(&a[3]=%d)\tsizeof(a[3]=%d)\n",sizeof(&a[3]),sizeof(a[3]));
	printf("q=%x,*q=%d,&q=%x\n",q,*q,&q);
	printf("sizeof(q)=%d\tsizeof(*q)=%d\tsizeof(&q)=%d\n",sizeof(q),sizeof(*q),sizeof(&q));

}