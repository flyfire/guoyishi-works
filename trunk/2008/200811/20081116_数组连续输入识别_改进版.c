//�������� 
void InsertionSort(int a[], int n) 
{ 
//�ӵڶ�������ʼ�����β��� 
for(int i=1; i<n; ++i) 
{ 
int j; 
//��a[i]���뵽a[0,i-1] 
int value=a[i]; 
//��a[0,i-1]��Ѱ�ҿ��Բ����λ�� 
for(j=i-1; j>=0; --j) 
{ 
if(value<a[j]) a[j+1]=a[j]; 
else break; 
} 
//���ѭ����a[j]<value 
//value����������뼴�� 
a[j+1]=value; //���� 
} 
} 

int main() 
{ 
int arr[100]; 
int n; 
cin >> n; 
for(int i = 0; i < n; i++) 
{ 
cin >> a[i]; 
} 
InsertionSort(a, n); 
//������ 
............ 
return 0; 
}