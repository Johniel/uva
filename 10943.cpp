#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

const lli MOD = 1000000;
const int T = 100 + 2;

inline
lli dp(lli n, lli m)
{
  static lli t[T][T];
  fill(&t[0][0], &t[T-1][T], 0);

  for(int i=0; i<n; ++i){
    t[0][i] = 1;
  }
  
  for(int i=0; i<m; ++i){
    for(int j=0; j<n; ++j){
      if(!t[i][j])continue;
      for(int k=0; k<n; ++k){
	if(n <= j + k)continue;
	t[i + 1][j + k] += t[i][j];	
	t[i + 1][j + k] %= MOD;
      }
    }
  }
  
  return t[m-1][n-1];
}

int main(void)
{
  for(lli n, m; ; ){
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    cout << dp(n+1, m) << endl;
  }
  return 0;
}
