#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 12 + 1;
const int T = (1 << N) + 1;

int t[T][N][N];
set<int> e[N];

void dp(int size, int K)
{
  int bit = 1 << size;
  fill(&t[0][0][0], &t[T-1][N-1][N], 0);
  //t[0][0][0] = 1;
  for(int i=0; i<size; ++i){
    t[1 << i][0][i] = 1;
  }
  for(int i=0; i<bit; ++i){
    for(int j=0; j<size; ++j){
      for(int k=0; k<size; ++k){
        if(t[i][j][k] == 0)continue;
        for(int l=0; l<size; ++l){
          if(i & (1 << l))continue;
          if(e[l].count(k) && K) t[i | (1 << l)][j+1][l] += t[i][j][k];
          else                   t[i | (1 << l)][j+0][l] += t[i][j][k];
        }
      }
    }
  }
  return ;
}

int solve(int size, int K, int lim)
{
  int bit = 1 << size;
  int sum = 0;
  for(int i=0; i*K<=lim && i<size; ++i){
    for(int j=0; j<size; ++j){
      //cout << bit-1 << ' ' << i << ' ' << j << " : " << t[bit-1][i][j] << endl;
      sum += t[bit-1][i][j];
    }
  }
  return sum;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    int n, k, q, r;
    cin >> n >> k >> q;
    for(int i=0; i<n; ++i){
      int t, j;
      cin >> t;
      e[i].clear();
      while(t--){
        cin >> j;
        e[i].insert(j-1);
      }
    }
    dp(n, k);
    cout << "Case " << ++cnt << ":" << endl;
    while(q--){
      cin >> r;
      cout << solve(n, k, r) << endl;
    }
  }
  return 0;
}
