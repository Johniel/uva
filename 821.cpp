#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int N = 101;

int G[N][N];

int main(void)
{
  int tc = 0;
  while(true){
    int cnt = 0, src, dst, sum = 0;    
    fill(&G[0][0], &G[N-1][N], (1 << 20));
    for(;; ++cnt){
      cin >> src >> dst;
      if(src == dst && dst == 0)break;
      G[src][dst] = 1;
    }
    if(cnt == 0)break;
    REP(k, N)REP(i, N)REP(j, N)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    cnt = 0;
    REP(i, N){
      REP(j, N){
	if(i != j && G[i][j] < (1 << 20)){
	  sum += G[i][j];
	  ++cnt;
	}
      }
    }
    printf("Case %d: average length between pages = %.3lf clicks\n", 
	   ++tc, (double)sum/(double)cnt);
  }
  return 0;
}
