#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 10000 + 1, INF = 1 << 20;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};

bool operator < (const Edge &a, const Edge &b)
{
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

inline
void visit(const Graph &G, int n, int order[], int &time, bool visited[], bool flg)
{
  visited[n] = true;
  FOR(e, G[n]){
    if(!visited[e->dst])
      visit(G, e->dst, order, time, visited, flg);
  }
  if(flg)order[--time] = n;
  else order[n] = time;
  return ;
}

inline
int solve(const Graph &G)
{
  const int size = G.size();
  static bool visited[NODE];
  static int order[NODE], scc[NODE];
  int time, prev = size - 1;
  Graph H(size);
  fill(order, order + size, -1);
  fill(scc, scc + size, -1);
  REP(i, size){
    FOR(e, G[i])
      H[e->dst].push_back(Edge(e->dst, e->src));
  }
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[i])
      visit(G, i, order, time, visited, true);
  }
  fill(visited, visited + size, false);
  time = 0;
  REP(i, size){
    if(!visited[order[i]]){
      visit(H, order[i], scc, time, visited, false);
      ++time;
    }
  }
  int cnt = time;
  int *color = scc;
  bool income[cnt];
  set<Edge> edges[cnt];  
  fill(income, income + cnt, false);
  REP(i, size){
    FOR(e, G[i]){
      edges[color[e->src]].insert(Edge(color[e->src], color[e->dst]));
      if(color[e->src] !=  color[e->dst])income[color[e->dst]] = true;
    }
  } 
  return max((int)count(income, income + cnt, false), 1);
}

int main(void)
{
  int tc, cnt = 0, node, edge, src, dst;
  for(cin >> tc; tc--; ){
    cin >> node >> edge;
    Graph G(node);
    for(int i=0; i<edge; ++i){
      cin >> src >> dst;
      --src; --dst;
      G[src].push_back(Edge(src, dst));
    }
    cout << "Case " << ++cnt << ": " << solve(G) << endl;
  }
  return 0;
}
