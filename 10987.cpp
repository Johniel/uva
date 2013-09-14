#include <iostream>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int N = 100 + 1, INF = 1 << 25;

struct Edge{
  int src, dst, cost;
  Edge(int s, int d, int c) : src(s), dst(d), cost(c) {}
};

struct Cable{
  int src, dst;
  Cable(int s, int d) : src(s), dst(d) {}
};

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.src != b.src)return a.src > b.src;
  return a.dst > b.dst;
}

bool operator < (const Cable &a, const Cable &b)
{  
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

bool check(int size, int G[N][N], int tmp[N][N])
{  
  REP(i, size)REP(j, size){
    if(tmp[i][j] != INF){
      if(tmp[i][j] != G[i][j])return false;      
    }
  }
  return true;
}

int main(void)
{ 
  bool visited[N];
  int G[N][N], tmp[N][N], tc, cnt = 0, n, path[N][N];
  for(cin >> tc; tc--; ){
    cin >> n;
    
    fill(&G[0][0], &G[N-1][N], INF);
    fill(&tmp[0][0], &tmp[N-1][N], INF);
    fill(&path[0][0], &path[N-1][N], -1);
    
    for(int i=1; i<n; ++i){      
      for(int j=0; j<i; ++j){
	cin >> G[i][j];
	G[j][i] = tmp[i][j] = tmp[j][i] = G[i][j];
      }
    }
    
    REP(k, n)REP(i, n)REP(j, n){
      if(i == j || i == k || j == k)continue;
      if(G[i][j] > G[i][k] + G[k][j]){
	G[i][j] = G[i][k] + G[k][j];
	path[i][j] = k;
      }
    }
    
    cout << "Case #" << ++cnt << ":" << endl;
    if(check(n, G, tmp)){           
      set<Cable> S;
      REP(k, n)REP(i, n)REP(j, n){
	if(i == j || i == k || j == k)continue;
	if(G[i][j] == G[i][k] + G[k][j])
	  G[i][j] = INF;
      }
      REP(i, n)REP(j, i){
	if(G[i][j] != INF && tmp[i][j] != INF){
	  S.insert(Cable(j, i));
	}
      }
      cout << S.size() << endl;
      FOR(e, S){
	if(tmp[e->src][e->dst] != INF)
	  cout << e->src + 1<< ' ' << e->dst + 1 << ' ' << G[e->src][e->dst] << endl;
      }
    }
    else cout << "Need better measurements." << endl;
    cout << endl;
  }
  return 0;
}
