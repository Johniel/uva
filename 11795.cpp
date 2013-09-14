#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int R = 17, T = 1 << R;

bool alive(int s, int n)
{
  return s & (1 << n);
}

int kill(int s, int n)
{
  return s ^ (1 << n);
}

lli rec(int s, lli t[], int r[], int size, int w)
{
  if(t[s])return t[s];
  lli sum = 0;
  for(int i=0; i<size; ++i){
    if(!alive(s, i))continue;
    if(!alive(w, i))continue;
    sum += rec(kill(s, i), t, r, size, w | r[i]);
  }
  return t[s] = sum;
}

lli solve(int r[], int size, int w)
{
  static lli t[T];
  int ini = (1 << size) - 1;
  fill(t, t + T, 0ll);
  t[0] = 1;
  return rec(ini, t, r, size, w);
}

int b2n(string s)
{
  int sum = 0;
  for(int i=0; i<s.size(); ++i){
    if(s[i] == '1')sum += 1 << i;
  }
  return sum;
}

int main(void)
{
  int tc, cnt = 0, r[16], n;
  for(cin >> tc; tc--; ){
    string s, t;
    cin >> n >> t;
    for(int i=0; i<n; ++i){
      cin >> s;
      r[i] = b2n(s);
    }
    cout << "Case " << ++cnt << ": " << solve(r, n, b2n(t)) << endl;
  }
  return 0;
}
