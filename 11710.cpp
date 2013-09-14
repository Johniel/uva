//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int inf = (400 + 1) * (79800 + 1);
const int fail = -1;

struct Edge {
  int src, dst, cost;
  Edge() : src(fail), dst(fail), cost(inf) {}
  Edge(int s, int d, int c) : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost < b.cost;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

class UnionFind {
public:
  vector<int> rank, p;
  UnionFind(int size)
  {
    rank.resize(size, -inf);
    p.resize(size, -inf);
  }
  void make(int a)
  {
    rank[a] = 0;
    p[a] = a;
  }
  void unite(int a, int b)
  {
    link(find(a), find(b));
  }
  int find(int a)
  {
    return (a == p[a]) ? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b)
  {
    return find(a) == find(b);
  }
  void link (int a, int b)
  {
    if (rank[a] > rank[b]) {
      p[b] = a;
    } else {
      p[a] = b;
      if(rank[a] == rank[b]) rank[b]++;
    }
  }
};

Edges kruskal(const Graph &G)
{
  const int size = G.size();
  Edges E, R;
  UnionFind ds(size);
  REP(i, size){
    FOR(j, G[i])
      E.push_back(*j);
    ds.make(i);
  }
  sort(ALL(E));
  FOR(e, E){
    if(!ds.isSameSet(e->src, e->dst)){
      ds.unite(e->src, e->dst);
      R.push_back(*e);
      if (R.size() == size-1) break;
    }
  }
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
    map<string, int> sta;
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    Graph G(node);
    REP(i, node){
      string s;
      cin >> s;
      sta[s] = cnt++;
    }
    REP(i, edge){
      string src, dst;
      int cost;
      cin >> src >> dst >> cost;
      G[sta[src]].push_back(Edge(sta[src], sta[dst], cost));
      G[sta[dst]].push_back(Edge(sta[dst], sta[src], cost));
    }
    string tmp;
    cin >> tmp;
    if(isConnectedGraph(G)){
      Edges mst = kruskal(G);
      int sum = 0;
      FOR(e, mst) sum += e->cost;
      cout << sum << endl;
    }
    else cout << "Impossible" << endl;
  }
  return 0;
}
