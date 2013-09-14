//uva 247, 11709
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 10000 + 1;
static const int INF = 1 << 20;
const int inf = 1 << 20;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(const Graph &G, int n, int order[], int &time, bool visited[])
{
  visited[n] = true;
  FOR(e, G[n]){
    if(!visited[e->dst])
      visit(G, e->dst, order, time, visited);
  }
  order[--time] = n;
  return ;
}

vector< vector<int> > detectSCC(const Graph &G)
{
  const int size = G.size();
  bool visited[size];
  int order[size], scc[size], time, prev = size - 1;
  vector< vector<int> > S;
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
      visit(G, i, order, time, visited);
  }
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[order[i]]){
      visit(H, order[i], scc, time, visited);
      int j = prev;
      vector<int> T;
      for(j=prev; 0 <= j && scc[j] != -1; --j)
        T.push_back(scc[j]);
      prev = j;
      S.push_back(T);
    }
  }
  return S;
}

bool p[NODE];
bool vis[NODE];
int depth[NODE];

void labeling(const Graph &g, int v, int d)
{
  vis[v] = true;
  depth[v] = d;
  FOR(e, g[v]){
    if(vis[e->dst])continue;
    labeling(g, e->dst, d + 1);
  }
  return ;
}

bool rec(const Graph &g, int v)
{
  vis[v] = true;
  p[v] = true;
  
  int cnt = 0;
  FOR(e, g[v]){
    if(!p[e->dst] && depth[e->src] + 1 != depth[e->dst]){
      return false;
    }
    if(p[e->dst] && vis[e->dst]){
      ++cnt;
      if(cnt == 2){
        return false;
      }
    }
    if(depth[e->src] + 1 < depth[e->dst]){
      return false;
    }
    if(vis[e->dst] && depth[e->src] < depth[e->dst]){
      return false;
    }
    if(vis[e->dst])continue;
    bool tmp = rec(g, e->dst);
    if(!tmp)return false;
  }

  p[v] = false;
  return true;
}

bool have_valid_edge(const Graph &g)
{
  const int size = g.size();
  
  fill(p, p + size, false);
  fill(vis, vis + size, false);
  labeling(g, 0, 0);

  fill(vis, vis + size, false);

  bool tmp = rec(g, 0);

  return tmp;
}

inline
bool is_single_SCC(const Graph &g){ return detectSCC(g).size() == 1; }

int in[NODE], out[NODE];

inline
bool is_same_degree(int size)
{
  for(int i=0; i<size; ++i){
    if(in[i] != out[i])return false;
  }
  return true;
}

#include <cstdio>
int main(void)
{
  int tc, node, edge, src, dst;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d%d", &node, &edge);
    Graph g(node);
    fill(in, in + node, 0);
    fill(out, out + node, 0);
    for(int i=0; i<edge; ++i){
      scanf("%d%d", &src, &dst);
      g[src].push_back(Edge(src, dst));
      ++in[dst];
      ++out[src];
    }

    bool flg = true;

    if(flg)flg &= is_same_degree(node);
    if(flg)flg &= is_single_SCC(g);
    if(flg)flg &= have_valid_edge(g);
    
    puts((flg ? "YES" : "NO"));
  }
  return 0;
}
