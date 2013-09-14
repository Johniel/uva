#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; i++)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i != (c).end(); ++i)

using namespace std;

typedef struct{
  int no, cost;
}Edge;

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
 
static const int CLOSED = 1;
static const int VISITED = 2;

bool visit(const Graph &G, int i, vector<int> &order, vector<int> &color)
{
  color[i] = CLOSED;
  FOR(j, G[i]){
    if(color[j->no] == VISITED)continue;
    if(color[j->no] == CLOSED)return false;
    if(!visit(G, j->no, order, color))return false;
  }
  order.push_back(i);
  color[i] = VISITED;
  return true;
}

bool ToporogicalSort(const Graph &G, vector<int> &order)
{
  int size = G.size();
  vector<int> color(size, 0);
  REP(i, size)if(!color[i] && !visit(G, i, order, color))
    return false;
  reverse(ALL(order));
  return true;
}

int main(void)
{
  while(true){
    int node, edge, to, from;
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    Graph G;
    G.resize(node);
    REP(i, edge){
      cin >> from >> to;
      //cin >> to >> from;
      from--; to--;
      Edge e = {to, 1};
      G[from].push_back(e);
    }
    vector<int> order;
    ToporogicalSort(G, order);
    REP(i, node){
      cout << order[i]+1;
      if(i + 1 < node)cout << ' ';
      else cout << endl;
    }
  }
  return 0;
}
