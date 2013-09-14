#include <iostream>

using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b)
{
  return a%b? gcd(b, a%b) : b;
}

int main(void)
{
  lli tc;
  cin >> tc;
  while(tc--){
    lli a, b;
    cin >> a >> b;
    lli g = (a < b)? gcd(b, a) : gcd(a, b);
    lli l = a * b / g;
    if(a == (a * b / l))
      cout << g << ' ' << l << endl;
    else cout << -1 << endl;
  }
  return 0;
}
