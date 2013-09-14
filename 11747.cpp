#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>

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
    REP(i, size){
      p[i] = i;
      rank[i] = 0;
    }
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

#include <set>
Edges kruskal(const Graph &G)
{
  const int size = G.size();
  Edges E, R;
  DisjointSet ds(size);
  FOR(i, G){
    FOR(j, *i)
      E.push_back(*j);
  }
  sort(ALL(E));
  set< pair<int, int> > S;
  FOR(e, E){
    if(!ds.isSameSet(e->src, e->dst)){
      ds.join(e->src, e->dst);
      S.insert(make_pair(e->src, e->dst));
      S.insert(make_pair(e->dst, e->src));
    }
    else if(S.count(make_pair(e->src, e->dst)) == 0){
      R.push_back(*e);
      S.insert(make_pair(e->src, e->dst));
      S.insert(make_pair(e->dst, e->src));
    }
  }
  sort(ALL(R));
  FOR(e, R){
    if(e != R.begin())cout << ' ';
    cout << e->cost;
  }
  if(R.size() == 0)cout << "forest";
  cout << endl;
  return R;
}

bool isConnectedGraph(const Graph &G)
{
  const int size = G.size();
  stack<int> S;
  bool visited[size];
  fill(visited, visited + size, false);
  for(S.push(0); !S.empty();){
    int n = S.top();
    S.pop();
    if(visited[n])continue;
    visited[n] = true;
    FOR(e, G[n]){
      if(!visited[e->dst])
	S.push(e->dst);
    }
  }
  return count(visited, visited + size, true) == size;
}

int main(void)
{
  while(true){
    int node, edge, cnt = 0;
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    Graph G(node);
    REP(i, edge){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      G[src].push_back(Edge(src, dst, cost));
      G[dst].push_back(Edge(dst, src, cost));
    }
    kruskal(G);
  }  
  return 0;
}
