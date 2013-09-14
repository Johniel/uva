#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

lli f(lli n)
{
  return n/5 + (n%5 == 0);
}

lli l(lli n)
{
  lli r = 0;
  while(n){
    n /= 2;
    ++r;
  }
  return r;
}

int main(void)
{
  for(int  n; cin >> n; ){        
    cout << (n - 1) + (int)(log(n-1) / log(2.0)) << endl;
    continue;
    cout << l(n) + n - l(n/2 + n%2) << endl;
    continue;
    cout << (n - 1) + f(n) << endl;
  }
  return 0;
}
