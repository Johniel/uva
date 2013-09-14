#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

int main(void)
{
  const int inf = 1 << 22;
  const int N = 100 + 1;
  int g[N][N];
  for(int n; cin >> n; ){
    for(int i=0; i<n; ++i){
      g[i][i] = inf;
      for(int j=0; j<i; ++j){
        string s;
        cin >> s;
        if(s == "x")g[i][j] = g[j][i] = inf;        
        else g[i][j] = g[j][i] = atoi(s.c_str());
      }
    }
    REP(k, n)REP(i, n)REP(j, n){
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
    int r = inf;
    int mx = -1;
    REP(j, n){
      if(g[0][j] != inf)mx = max(mx, g[0][j]);
    }
    cout << mx << endl;
  }
  return 0;
}
