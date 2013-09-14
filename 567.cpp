#include <iostream>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 20 + 1, INF = 1 << 20;

struct Edge{
  int dst;
  Edge(int d) : dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

inline
int bfs(const Graph &G, int src, int dst)
{
  static int weight[NODE];
  queue<int> Q;
  fill(weight, weight + NODE, INF);
  for(Q.push(src), weight[src] = 0; !Q.empty() && weight[dst] == INF; Q.pop()){
    int n = Q.front();
    FOR(e, G[n]){
      if(weight[e->dst] != INF)continue;
      Q.push(e->dst);
      //cout << n << " -> " << e->dst << endl;
      weight[e->dst] = weight[n] + 1;
    }    
  }
  return weight[dst];
}

int main(void)
{
  bool path[NODE][NODE];
  int tc = 0;
  while(true){
    fill(&path[0][0], &path[NODE-1][NODE], false);
    Graph G(NODE);
    REP(i, 20-1){
      int e, src = i + 1;
      if(!(cin >> e))return 0;
      REP(j, e){
	int dst;
	cin >> dst;
	if(path[src][dst])continue;
	path[src][dst] = true;
	path[dst][src] = true;
	G[src].push_back(Edge(dst));
	G[dst].push_back(Edge(src));
      }
    }
    int q;
    cin >> q;
    cout << "Test Set #" << ++tc << endl;
    REP(i, q){
      int src, dst;
      cin >> src >> dst;
      printf("%2d to %2d: %d\n", src, dst, bfs(G, src, dst));
    }
    cout << endl;
  }
  return 0;
}
