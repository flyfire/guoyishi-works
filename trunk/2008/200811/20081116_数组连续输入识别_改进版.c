//插入排序 
void InsertionSort(int a[], int n) 
{ 
//从第二个数开始，依次插入 
for(int i=1; i<n; ++i) 
{ 
int j; 
//将a[i]插入到a[0,i-1] 
int value=a[i]; 
//在a[0,i-1]中寻找可以插入的位置 
for(j=i-1; j>=0; --j) 
{ 
if(value<a[j]) a[j+1]=a[j]; 
else break; 
} 
//完成循环后，a[j]<value 
//value在它后面插入即可 
a[j+1]=value; //插入 
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
//输出结果 
............ 
return 0; 
}