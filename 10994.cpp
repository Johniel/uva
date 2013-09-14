#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli F(lli n)
{
  if(n%10)return n%10;
  if(n == 0)return 0;
  return F(n/10);
}

lli f(lli n)
{
  lli a, b, m;
  a = b = 0L;
  if(n < 0)return 0;
  while(n){
    m = n % 10L;
    n = n / 10L;
    a += m * (m + 1L) / 2L;
    b += n * 45L;
  }
  return a + b;
}

int main(void)
{
  lli n, m;
  while(cin >> n >> m){
    if(n < 0 || m < 0)break;
    //cout << endl; cout << f(m) << endl; cout << f(n) << endl;
    cout << f(m) - f(n-1) << endl;
  }
  return 0;
}
