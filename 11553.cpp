#include <iostream>
#include <algorithm>

using namespace std;

const int G = 8 + 1;
const int INF = 1 << 22;

int g[G][G];

int dp(int size)
{
  const int T = 1 << G;
  static int t[G][T];		  
  fill(&t[0][0], &t[G-1][T], INF);
  t[0][0] = 0; 
  for(int i=0; i<size; ++i){
    for(int j=0; j<T; ++j){
      if(t[i][j] == INF)continue;
      for(int k=0; k<size; ++k){
	int b = 1 << k; 
	if(j & b)continue;
	t[i + 1][j | b] = min(t[i + 1][j | b], t[i][j] + g[i][k]);
      }
    }
  }
  return t[size][(1 << size) - 1];
}

int main(void)
{
  int tc;
  cin >> tc;
  for(int n; tc--; cout << dp(n) << endl){
    cin >> n;
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cin >> g[i][j];
      }
    }
  }
  return 0;
}
