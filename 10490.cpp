#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

lli power(lli n, lli p)
{
  if(p == 0)return 1ll;
  if(p == 1)return n;
  lli tmp = power(n, p/2);
  lli m = tmp * tmp;
  return p % 2ll ? m * n : m;
}

lli f(int n)
{
  return power(2, n-1) * (power(2, n) - 1ll);
}

#include <cmath>
#include <vector>

int main(void)
{
  cout << power(2, 31) - 1ll << endl;
  while(true){
    int n;
    cin >> n;
    if(n == 0)break;
    lli m = f(n);
    
  }
  return 0;
}
