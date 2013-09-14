#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int T = 10000 + 2, C = 21;
const int INF = 1 << 30;

int t[T][C];

int rec(const Graph &g, int n, int p)
{
  int result = INF;
  if(t[n][1] != INF){
    REP(i, C){
      if(i != p){
	result = min(result, t[n][i]);
      }
    }
    return result;
  }
  REP(i, C){
    if(i)t[n][i] = i;
  }
  FOR(e, g[n]){
    REP(i, C){
      if(i)t[n][i] += rec(g, e->dst, i);
    }
  }
  REP(i, C){
    if(i && i != p){
      result = min(result, t[n][i]);
    }
  }
  return result;
}

int main(void)
{
  int income[T], outgo[T];
  while(true){
    int node;
    cin >> node;
    if(node == 0)break;
    Graph g(node);
    int src, dst, root;
    char c;
    fill(income, income + node, 0);
    fill(outgo, outgo + node, 0);
    fill(&t[0][0], &t[T-1][C], INF);
    REP(i, node){
      cin >> src >> c;
      while(cin.get(c) && c != '\n'){
	cin >> dst;
	g[src].push_back(Edge(src, dst));
	++income[dst];
	++outgo[src];
      }
    }
    REP(i, node){
      if(!income[i] && outgo[i]){
	root = i;
      }
      if(income[i] && !outgo[i]){
	REP(j, C){
	  if(j)t[i][j] = j;
	}
      }
    }
    int result = INF;
    REP(i, C){
      if(i)result = min(result, rec(g, root, i));
    }
    cout << result << endl;
  }
  return 0;
}
