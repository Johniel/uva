#include <iostream>
#include <algorithm>

using namespace std;

int dp(int u, int n, int p)
{
  const int T = 70 + 1;
  int m = n - u * p;
  int t[T][T];
  fill(&t[0][0], &t[T-1][T], 0);
  t[0][0] = 1;
  for(int i=0; i<u; ++i){
    for(int j=0; j<=m; ++j){
      if(t[i][j] == 0)continue;
      for(int k=0; k+j<=m; ++k){
        t[i+1][j + k] += t[i][j];
      }
    }
  }
  return t[u][m];
}

int main(void)
{
  int tc, n, t, p;
  cin >> tc;
  while(tc--){
    cin >> n >> t >> p;
    cout << dp(n, t, p) << endl;
  }
  return 0;
}
