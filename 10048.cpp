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

const int INF = (400 + 1) * (79800 + 1);
const int FAIL = -1;
const int NODE = 100 + 1;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
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

Edges kruskal(const Graph &G)
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
      if(R.size() == size-1)break;
    }
  }
  return R;
}

#include <queue>
int bfs(const Graph &graph, int src, int dst)
{
  const int size = graph.size();
  static bool visited[NODE];
  fill(visited, visited + size, false);
  queue< pair<int, int> > q;
  visited[src] = true;
  for(q.push(make_pair(src, 0)); !q.empty(); q.pop()){
    pair<int, int> p = q.front();
    if(p.first == dst)return p.second;
    FOR(e, graph[p.first]){
      if(visited[e->dst])continue;
      //cout << e->src << ' ' << e->dst << endl;
      visited[e->dst] = true;
      q.push(make_pair(e->dst, max(p.second, e->cost)));
    }
  }
  return -1;
}

int main(void)
{
  bool flg = true;
  int tc = 0;
  for(int node, edge, query; ; ){
    cin >> node >> edge >> query;
    if(node == 0 && edge == 0 && query == 0)break;
    if(flg)flg = false;
    else cout << endl;
    Graph graph(node), mst(node);
    int src, dst, cost;
    for(int i=0; i<edge; ++i){
      cin >> src >> dst >> cost;
      //cout << src << ' ' << dst << ' ' << cost << endl;
      --src; --dst;    
      graph[src].push_back(Edge(src, dst, cost));
      graph[dst].push_back(Edge(dst, src, cost));
    }
    Edges tmp = kruskal(graph);
    FOR(e, tmp){
      //cout << e->src << ' ' << e->dst << ' ' << e->cost << endl;
      mst[e->src].push_back(Edge(e->src, e->dst, e->cost));
      mst[e->dst].push_back(Edge(e->dst, e->src, e->cost));
    }
    cout << "Case #" << ++tc << endl;
    for(int i=0; i<query; ++i){
      cin >> src >> dst;
      --src; --dst;
      int result =  bfs(mst, src, dst);
      if(result < 0)cout << "no path" << endl;
      else cout << result << endl;
    }
  }
  return 0;
}
