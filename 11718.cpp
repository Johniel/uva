#include <iostream>

using namespace std;

typedef unsigned long long int lli;

lli mod;

inline
lli pwr(lli n, lli p)
{
  if(p == 0)return 1;
  if(p == 1)return n;
  lli m = pwr(n, p/2);
  m = m * m % mod;
  return p%2? m * n % mod : m;
}

int main(void)
{
  int tc, cnt = 0, A[1000 + 1];
  cin >> tc;
  while(tc--){
    lli n, k, sum = 0;
    cin >> n >> k >> mod;
    for(int i=0; i<n; ++i){
      cin >> A[i];
    }
    lli p = pwr(n, k-1) * k % mod;
    for(int i=0; i<n; ++i){
      sum = (sum + (A[i] * p) % mod) % mod;
    }
    cout << "Case " << ++cnt << ": " << sum << endl;
  }
  return 0;
}
