#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

struct Edge{
  int dst;
  Edge(int d) : dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
 
static const int NODE = 1000000;

static const int CLOSED = 1;
static const int VISITED = 2;

int result[NODE], cnt = 0;

bool visit(const Graph &G, int n, int color[])
{
  color[n] = CLOSED;
  FOR(e, G[n]){
    if(color[e->dst] == VISITED)continue;
    if(color[e->dst] == CLOSED)return false;
    if(!visit(G, e->dst, color))return false;
  }
  result[cnt++] = n;
  color[n] = VISITED;
  return true;
}

inline 
bool toporogicalSort(const Graph &G)
{
  const int size = G.size();
  static int color[NODE];
  fill(color, color + size, 0);
  REP(i, size){
    if(!color[i] && !visit(G, i, color))
      return false;
  }
  //reverse(ALL(order));
  return true;
}

int main(void)
{
  while(true){
    int node, edge;
    //cin >> node >> edge;
    scanf("%d%d", &node, &edge);
    if(node == 0 && edge == 0)
      break;
    Graph G(node);
    cnt = 0;
    REP(i, edge){
      int src, dst;
      //cin >> src >> dst;
      scanf("%d%d", &src, &dst);
      --src; --dst;
      G[src].push_back(Edge(dst));
    }
    if(toporogicalSort(G)){
      for(int i=cnt-1; i>=0; --i){
	printf("%d\n", result[i] + 1);
      }
    }
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}
