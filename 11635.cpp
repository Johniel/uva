#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)

using namespace std;

static const int NODE = 10000;
static const int INF = 1 << 30;
static const int HOTEL = 100 + 1;

struct Edge{
  int src, dst, cost;
  Edge(int s, int d, int c) : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct State{
  int dst, cost, day;
  State(int ds, int c, int da) : dst(ds), cost(c), day(da) {}
};

inline
bool operator < (const State &a, const State &b)
{
  if(a.day != b.day)return a.day > b.day;
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst > b.dst;
}

static const int lim = 60 * 10;

inline
int sssp(const Graph &G, bool hotel[], int h)
{
  const int size = G.size();
  static int weight[NODE][HOTEL];
  static bool visited[NODE][HOTEL];
  priority_queue<State> Q;
  int src = 0, dst = size-1;
  REP(i, size){
    REP(j, h + 1){
      weight[i][j] = INF;
      visited[i][j] = false;
    }
  }
  weight[src][0] = 0;
  for(Q.push(State(src, 0, 0)); !Q.empty();){
    State n = Q.top();
    Q.pop();
    if(n.dst == dst)return n.day;
    if(visited[n.dst][n.day])continue;
    visited[n.dst][n.day] = true;
    FOR(e, G[n.dst]){
      if(!(lim < n.cost + e->cost || visited[e->dst][n.day])){
	if(n.cost + e->cost < weight[e->dst][n.day]){
	  Q.push(State(e->dst, n.cost + e->cost, n.day));
	  weight[e->dst][n.day] = n.cost + e->cost;
	}
      }
      if(!hotel[n.dst] || visited[e->dst][n.day + 1])continue;
      Q.push(State(e->dst, e->cost, n.day + 1));
      weight[e->dst][n.day + 1] = 0;
    }
  }
  return -1;
}

int main(void)
{
  bool hotel[NODE];
  while(true){
    int node, edge, h;
    scanf("%d", &node);
    if(node == 0)break;
    Graph G(node);
    fill(hotel, hotel + node, false);
    scanf("%d", &h);
    REP(i, h){
      int name;
      scanf("%d", &name);
      --name;
      hotel[name] = true;
    }
    scanf("%d", &edge);
    REP(i, edge){
      int src, dst, cost;
      scanf("%d%d%d", &src, &dst, &cost);
      if(lim < cost)continue;
      --src; --dst;
      G[src].push_back(Edge(src, dst, cost));
      G[dst].push_back(Edge(dst, src, cost));
    }
    printf("%d\n", sssp(G, hotel, h));
  }
  return 0;
}
