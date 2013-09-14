#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int lli;

lli gcd(lli a, lli b)
{
  return b? gcd(b, a%b) : a;
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    lli a, b;
    cin >> a >> b;    
    cout << "Case " << ++cnt << ": " << (a + b) / gcd(max(a, b), min(a, b)) << endl;
  }
  return 0;
}
