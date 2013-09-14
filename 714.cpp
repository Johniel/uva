#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const int N = 1000;
lli v[N];
bool sep[N];

lli solve(int size, lli cap, int m)
{
  int cnt = 0;
  lli sum = 0;
  lli mx = 0;
  for(int i=size-1; 0<=i; --i){
    if( cnt < m-1 && (i < m - cnt - 1 || cap < sum + v[i] ) ){
      ++cnt;
      mx = max(mx, sum);
      sum = 0;
      sep[i] = true;
    }
    sum += v[i];
  }
  return max(mx, sum);
}

int main(void)
{
  int tc;
  cin >> tc;
  while( tc-- ){
    int n, m;    
    lli sum = 0;
    cin >> n >> m;
    for(int i=0; i<n; ++i){
      cin >> v[i];
      sum += v[i];
    }
    lli s = 0, b = sum + 1;
    while(s + 1 < b){
      lli c = (s + b) / 2;
      if( c < solve(n, c, m) )s = c;
      else b = c;
    }
    fill(sep, sep + N, false);
    solve(n, b, m);
    for(int i=0; i<n; ++i){
      if(i)cout << ' ';
      cout << v[i];
      if(sep[i])cout << " /";
    }
    cout << endl;
  }
  return 0;
}
