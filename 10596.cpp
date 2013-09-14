#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 200 + 1;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool adj[NODE][NODE], visited[NODE];
int degree[NODE], src, dst, node, edge;

bool rec(const Graph &G, int node)
{
  visited[node] = true;
  if(count(visited, visited + G.size(), true) == G.size())
    return true;
  FOR(e, G[node]){
    if(!visited[e->dst]){
      if(rec(G, e->dst)){
	visited[node] = false;
	return true;
      }
    }
  }
  return visited[node] = false;
}

bool euler(const Graph &G)
{
  const int size = G.size();
  int odd = 0, s[2], start = -1;
  for(int i=0; i<size; ++i){
    if(degree[i] % 2)s[odd++] = i;
    visited[i] = (G[i].size() == 0);
    if(degree[i])start = i;
  }
  if(start == -1)return false;
  return (odd == 0 && rec(G, start));// || (odd == 2 && rec(G, s[0]) && rec(G, s[1]));
}

int main(void)
{
  for(; scanf("%d%d", &node, &edge) == 2; ){
    fill(degree, degree + node, 0);
    fill(&adj[0][0], &adj[node-1][node], false);
    Graph G(node);
    REP(i, edge){
      scanf("%d%d", &src, &dst);
      ++degree[src];
      ++degree[dst];
      adj[src][dst] = true; G[src].push_back(Edge(src, dst));
      adj[dst][src] = true; G[dst].push_back(Edge(dst, src));
    }
    if(!euler(G))cout << "Not " ;
    cout << "Possible" << endl;
  }  
  return 0;
}
