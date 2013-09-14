#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long int lli;

const int MOD = 10000;
const lli N = 1000 + 1;
const lli M = 100000 + 1;

set<lli> s[M];
lli    sum[M];
lli      x[M];
lli a, b, c, m, n;

lli rec(lli n)
{
  if(x[n] != -1)return x[n];
  lli tmp = (rec(n-1) * b + c) % m + 1;
  return x[n] = tmp;
}

int main(void)
{
  int tc, cnt = 0;
  for(cin >> tc; tc--; ){
    cin >> a >> b >> c >> m >> n;
    fill(x, x + N, -1);

    x[0] = a;
    rec(n);
    
    for(int i=0; i<n; ++i)cout << x[i] << ", ";cout << endl;

    int r = 0;

    fill(s, s + N, set<lli>());
    
    sum[0] = x[0];
    s[0].insert(0);
    for(int i=1; i<n; ++i){
      sum[i] = x[i] + sum[i-1];
      s[i] = s[i-1];
      s[i].insert(sum[i - 1]);
    }

    for(int i=0; i<n; ++i)cout << sum[i] << ", ";cout << endl;

    for(int i=0; i<n; ++i){
      lli tmp = sum[i] % m;
      cout << sum[i] << " ; " << tmp << endl;
      if(s[i].count(tmp)){
        cout << "!?" << endl;
        ++r;
      }
    }
    
    cout << "Case " << ++cnt << ": " << r << endl;
  }
  return 0;
}
