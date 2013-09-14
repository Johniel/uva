//uva 10299, 10179
#include <iostream>

using namespace std;

int eulerPhi(int n)
{
  //if(n == 1)return 0;
  if(n == 0)return 0;
  int re = n;
  for(int m = 2; m * m <= n; ++m){
    if(n % m)continue;
    re -= re / m;
    while(n % m == 0)
      n /= m;    
  }
  return (n > 1)? re - re / n : re;
}

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    if(n == 1)cout << 0 << endl;
    else 
      cout << ( 0<n? eulerPhi(n) : eulerPhi(-n)) << endl;
  }
  return 0;
}
