#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = 1 << 20;
static const int FAIL = -1, NODE = 10000, EDGE = 100000;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
  Edge(int s, int d, int c) 
  : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost < b.cost;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

class DisjointSet{
public: 
  vector<int> rank, p;
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }
  void make(int a){
    rank[a] = 0;
    p[a] = a;
  }
  void join(int a, int b){
    link(find(a), find(b));
  }
  int find(int a){
    return (a == p[a])? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b){
    return find(a) == find(b);
  }
  void link (int a, int b){
    if(rank[a] > rank[b])
      p[b] = a;
    else{
      p[a] = b;
      if(rank[a] == rank[b])
	rank[b]++;
    }
  }
};

Edges kruskal(const Graph &G, int a)
{
  const int size = G.size();
  Edges E, R;
  DisjointSet ds(size);
  int cost = 0;
  REP(i, size){
    FOR(j, G[i])
      E.push_back(*j);
    ds.make(i);
  }
  sort(ALL(E));
  FOR(e, E){
    if(!ds.isSameSet(e->src, e->dst)){
      ds.join(e->src, e->dst);
      R.push_back(*e);
      cost += e->cost;
      if(R.size() == size-1)break;
    }
  }
  static int tc = 0;
  int cnt = 0;
  REP(i, size)
    if(ds.find(i) == i)++cnt;   
  printf("Case #%d: %d %d\n", ++tc, cost + cnt * a, cnt);
  return R;
}

int main(void)
{
  int tc, node, edge, air_port, src, dst, cost;
  for(scanf("%d", &tc); tc--; ){
    scanf("%d%d%d", &node, &edge, &air_port);
    Graph G(node);
    REP(i, edge){
      scanf("%d%d%d", &src, &dst, &cost);
      --src; --dst;
      if(air_port <= cost)continue;
      G[src].push_back(Edge(src, dst, cost));
      G[dst].push_back(Edge(dst, src, cost));
    }
    kruskal(G, air_port);
  }  
  return 0;
}
