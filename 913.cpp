#include <iostream>

using namespace std;

typedef long long int lli;

lli f(lli n)
{
  lli a1 = 1;
  lli an = 2 * n + 1;
  return (a1 + an) / 2 * (n + 1);
}

int main(void)
{
  lli n;
  while(cin >> n){    
    lli a =  f((n-1L)/2L);
    lli b = 2L * (a - 1L) + 1L;
    cout << b - 4L + b - 2L + b << endl;
  }
  return 0;
}
