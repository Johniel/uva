//uva 10179
#include <iostream>

using namespace std;

int eulerPhi(int n)
{
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
    cout << eulerPhi(n) << endl;
  }
  return 0;
}
