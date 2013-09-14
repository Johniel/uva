#include <iostream>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef long long int lli;

const int NODE = 80 + 1;
const lli INF = 1ll << 22;

lli adj[NODE][NODE][NODE];
lli p[NODE];

int main(void)
{
  int c, r, q, cnt = 0;
  while(cin >> c >> r >> q && c){
    fill(&adj[0][0][0], &adj[NODE-1][NODE-1][NODE], INF);
    if(cnt)cout << endl;
    for(int i=0; i<c; ++i){
      cin >> p[i];
      for(int j=0; j<c; ++j){
	adj[i][j][j] = 0;
      }
    }
    for(int i=0; i<r; ++i){
      int src, dst;
      lli cost;
      cin >> src >> dst >> cost;
      --src;
      --dst;
      for(int j=0; j<c; ++j){
	if(p[j] < p[src] || p[j] < p[dst])continue;
	adj[j][src][dst] = adj[j][dst][src] = min(adj[j][src][dst], cost);
      }
    }
    
    REP(l, c)REP(k, c)REP(i, c)REP(j, c){
      if(p[l] < p[i] || p[l] < p[j] || p[l] < p[k])continue;
      adj[l][i][j] = min(adj[l][i][j], adj[l][i][k] + adj[l][k][j]);
    }

    cout << "Case #" << ++cnt << endl;    
    for(int i=0; i<q; ++i){
      int src, dst;
      lli mn = INF;
      cin >> src >> dst;
      --src;
      --dst;
      REP(j, c){
	mn = min(mn, adj[j][src][dst] + p[j]);
      }
      if(INF <= mn)cout << -1 << endl;
      else cout << mn << endl;
    }
  }
  return 0;
}
