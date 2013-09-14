#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i!=(c).end(); ++i)

using namespace std;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b){
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst > b.dst;
}

static const int INF = 1 << 20;

bool BellmanFord(const Graph &G, const int &start)
{
  const int size = G.size();
  int dist[size];
  fill(dist, dist + size, INF);
  dist[start] = 0;
  REP(k, size-1)REP(v, size)FOR(e, G[v])
    dist[e->dst] = min(dist[e->dst], dist[v] + e->cost);
  REP(v, size)FOR(e, G[v])
    if(dist[e->dst] > dist[v] + e->cost)return false;
  return true;//no neg cycle
}

int main(void)
{
  int tc, node, route;
  cin >> tc;
  while(tc--){
    cin >> node >> route;
    Graph G(node);
    REP(i, route){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      G[src].push_back(Edge(dst, cost));
    }
    if(!BellmanFord(G, 0))cout << "possible" << endl;
    else cout << "not possible" << endl;
  }
  return 0;
}
