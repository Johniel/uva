#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli gcd(lli a, lli b)
{
  return b ? gcd(b, a%b) : a;
}

lli buff[31];

void bt(lli n, lli p, lli m, int size, int lim)
{
  if(size == lim){
    if(n)return ;
    for(int i=0; i<size; ++i){
      if(i)cout << ' ';
      cout << buff[i];
    }
    cout << endl;
  }
  else{
    for(lli i=p; i<=n; ++i){
      if(gcd(max(m, i), min(m, i)) != 1)continue;
      buff[size] = i;
      bt(n-i, i, m * i, size + 1, lim);
    }
  }
  return ;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    lli n, m;
    cin >> n >> m;
    cout << "Case " << ++cnt << ":" << endl;
    bt(n, 1, 1, 0, m);
  }
  return 0;
}
