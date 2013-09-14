//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = (400 + 1) * (79800 + 1);
static const int FAIL = -1;

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

int kruskal(const Graph &G)
{
  const int size = G.size();
  Edges E, R;
  DisjointSet ds(size);
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
      if(R.size() == size-1){
	return e->cost;
      }
    }
  }
  return -1;
}

int main(void)
{
  int tc, node, edge, src, dst, cost, cnt = 0;
  for(cin >> tc; tc--; ){
    cin >> node >> edge;
    Graph G(node);
    REP(i, edge){
      cin >> src >> dst >> cost;
      if(src != dst)
	G[src].push_back(Edge(src, dst, -cost));
    }
    cout << "Case #" << ++cnt << ": " << -kruskal(G) << endl;
  }  
  return 0;
}
