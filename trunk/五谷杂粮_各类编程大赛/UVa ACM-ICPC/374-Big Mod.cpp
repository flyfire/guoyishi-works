#include<iostream>

using namespace std;

long square(long n)
{
     return n*n;
}

long bigMod(long b, long p, long m) {
        if(p == 0)
                return 1;
        else if(p%2 == 0)
                return square(bigMod(b, p/2, m)) %m;
        else
                return ((b%m) * bigMod(b, p-1, m)) % m; 
        
}

long b, p, m;

int main() {
   while(cin >> b >> p >> m) {
      //cout << b << " " << p << " " << m << endl;
      cout << bigMod(b, p, m) << endl;
   }
   return 0;
}
