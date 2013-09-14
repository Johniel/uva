#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int lli;

int main(void)
{
  int n, k, m;
  while( cin >> n >> k >> m ){
    const int N = 50 + 1;
    const int K = 50 + 1;
    const int M = 50 + 1;
    lli t[N][K][M], curr;
    fill(&t[0][0][0], &t[N-1][K-1][M], 0);
    t[1][1][1] = 1;
    for(int sum = 0; sum < n; ++sum){
      for(int unit = 0; unit <= k; ++unit){
        for(int chain = 0; chain <= m; ++chain){
          curr = t[sum][unit][chain];
          if( curr == 0 )continue;
          if(chain < m){
            t[sum + 1][unit][chain + 1] += curr;
          }
          t[sum + 1][unit + 1][1] += curr;
        }
      }
    }
    lli ans = 0;
    for(int i=0; i<=m; ++i){
      ans += t[n][k][i];
    }
    cout << ans << endl;
  }
  return 0;
}

