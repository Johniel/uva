#include <iostream>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

int main(void)
{
  const int N = 22 + 1, INF =  1 << 20;
  int G[N][N], cnt = 0; 
  while(true){
    int node, edge, name = 0;
    map<int, string> M;
    cin >> node >> edge;
    if(node == 0 && edge == 0)
      break;
    REP(i, node){
      string s;
      cin >> s;
      M[name++] = s;
      REP(j, node)G[i][j] = INF;
    }
    REP(i, edge){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      --src;
      --dst;
      G[src][dst] = G[dst][src] = min(cost, G[dst][src]);
    }
    REP(k, node)REP(i, node)REP(j, node)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    int r, m = INF;
    REP(i, node){
      int sum = 0;
      REP(j, node){
	if(j != i && G[i][j] != INF)
	  sum += G[i][j];
      }
      if(sum < m){
	m = sum;
	r = i;
      }
    }
    cout << "Case #" << ++cnt << " : " << M[r] << endl;
  }
  return 0;
}
