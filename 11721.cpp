//uva 558
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

static const int INF = 1 << 20, NODE = 1000 + 1;

void rec(const Graph &H, int node, bool visited[])
{
  visited[node] = true;
  FOR(e, H[node]){
    if(!visited[e->dst]){
      rec(H, e->dst, visited);
    }
  }
  return ;
}

void BellmanFord(const Graph &G, const int &start)
{
  const int size = G.size();
  static int dist[NODE], path[NODE];
  static bool visited[NODE], cycle[NODE];
  Graph H(size);

  fill(dist, dist + size, INF);
  fill(path, path + size, -1);
  fill(visited, visited + size, false);
  fill(cycle, cycle + size, false);

  REP(i, size){
    FOR(e, G[i]){
      H[e->dst].push_back(Edge(i, 0));
    }
  }

  dist[start] = 0;
  REP(k, size-1)REP(v, size)FOR(e, G[v]){
    dist[e->dst] = min(dist[e->dst], dist[v] + e->cost);
    continue;
    if(dist[e->dst > dist[v] + e->cost]){
      dist[e->dst] = dist[v] + e->cost;
      //path[e->dst] = v;
    }
  }

  REP(v, size)FOR(e, G[v]){
    if(dist[e->dst] > dist[v] + e->cost){
      //cycle[e->dst] = cycle[v] = true;
      if(!visited[e->dst]){
	rec(G, e->dst, visited);
	//rec(H, e->dst, visited);
      }
    }
  }

  bool flg = true;
  REP(i, size){
    if(visited[i]){
      if(flg)flg = false;
      cout << ' ' << i;
    }
  }
  if(flg)cout << " impossible" ;
  return ;
}

int main(void)
{
  int tc, node, edge, cnt = 0, src, dst, cost;
  cin >> tc;
  while(tc--){
    cin >> node >> edge;
    Graph G(node);
    REP(i, edge){
      cin >> src >> dst >> cost;
      //G[src].push_back(Edge(dst, cost));
      G[dst].push_back(Edge(src, cost));
    }
    cout << "Case " << ++cnt << ":";
    BellmanFord(G, 0);
    cout << endl;
  }  
  return 0;
}
