//uva 10806, 
/*
  undirected graph : {
  edge(s, d, capacoty, cost)
  Rev.edge(d, s, 0, -cost)
  edge(n1, n2, INF, 0)
  edge(n2, n1, INF, 0)
  }
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i != (c).end();++i)

using namespace std;

#define S e->src
#define D e->dst

//typedef double weight;
//static const weight INF = 1e256;
//static const double EPS = 1e-6;

typedef int weight;
static const weight INF = 1 << 20;

static const int NODE = 2 * (100 + 1) + 2;

struct Edge{
  int src, dst, cap;
  weight cost;
  Edge(int s, int d, int a, weight o) :
    src(s), dst(d), cap(a), cost(o){}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.cap != b.cap)return a.cap < b.cap;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

int cap[NODE][NODE], flow[NODE][NODE], p[NODE], H[NODE];
weight cost[NODE][NODE], dist[NODE];

inline int residue(int src, int dst)
{
  return cap[src][dst] - flow[src][dst];
}

bool rDijkstra(const Graph &G, int source, int sink)
{    
  const int size = G.size();
  fill(p, p + size, -1);
  fill(dist, dist + size, INF);
  priority_queue<Edge> Q;
  for(Q.push(Edge(source, source, 0, 0)), dist[source] = 0; !Q.empty();){
    Edge next = Q.top(); 
    Q.pop();
    if(p[next.dst] != -1)
      continue;
    p[next.dst] = next.src;
    if(next.dst == sink)
      break;
    FOR(e, G[next.dst]){
      if(residue(S, D) <= 0)
	continue;
      int rcost = cost[S][D] + H[S] - H[D];
      if(dist[D] > dist[S] + rcost){
	dist[D] = rcost + dist[S];
	Q.push(Edge(S, D, 0, dist[D]));
      }
    }
  }
  return p[sink] != -1;
}

pair<weight, int> minCostFlow(const Graph &G, int source, int sink, int required)
{
  const int size = G.size();
  pair<weight, int> result = make_pair(0, 0);// (cost, flow)
  fill(H, H + size, 0);
  REP(i, size)FOR(e, G[i]){
    cap[S][D] = e->cap;
    cost[S][D] = e->cost;
    flow[S][D] = 0;
  }
  while(0 < required && rDijkstra(G, source, sink)){
    int mf = required;
    REP(i, size)
      H[i] += dist[i];
    for(int i=sink; i != p[i]; i=p[i])
      mf = min(mf, cap[p[i]][i] - flow[p[i]][i]);
    for(int i=sink; i != p[i]; i=p[i]){
      result.first += mf * cost[p[i]][i];
      flow[p[i]][i] += mf;
      flow[i][p[i]] -= mf;
    }
    required -= mf;
    result.second += mf;
  }

  //cout << result.first << ' ' << result.second << endl;

  return result;
}

int main(void)
{
  int node, route, src, dst,  cost, produce, c; 
  while(scanf("%d%d", &node, &route) != EOF && node){
    Graph G;
    G.resize(node*2);
    REP(i, route){
      scanf("%d%d%d", &src, &dst, &cost);

      --src; --dst;
      G[src].push_back(Edge(src, dst, 1,  cost));
      G[dst].push_back(Edge(dst, src, 0, -cost));

      src += node; dst += node;
      G[src].push_back(Edge(src, dst, 0, -cost));
      G[dst].push_back(Edge(dst, src, 1,  cost));
    }
    REP(i, node){
      G[i].push_back(Edge(i, i + node, INF, 0));
      G[i + node].push_back(Edge(i + node, i, INF, 0));
    }
    pair<int, int> result = minCostFlow(G, 0, node-1, 2);
    if(2 == result.second)cout << result.first << endl;
    else cout << "Back to jail" << endl;
  }
  return 0;
}

/*
int main(void)
{
  int bank, police;
  while(true){
    cin >> bank >> police;
    if(police == 0 && bank == 0)
      break;
    Graph G(police + bank + 2);
    const int source = G.size() - 1;
    const int sink = G.size() - 2;
    REP(b, bank){
      REP(j, police){
	int p = j + bank;
	weight cost;
	cin >> cost;
	G[b].push_back(Edge(b, p, 1,  cost));
	G[p].push_back(Edge(p, b, 0, -cost));
      }
    }
    REP(i, bank)
      G[source].push_back(Edge(source, i, 1, 0));
    REP(i, police)
      G[i + bank].push_back(Edge(i + bank, sink, 1, 0));
    printf("%.2lf\n", (minCostFlow(G, source, sink, bank).first+0.05+EPS)/(double)bank);
  }
  return 0;
}
*/
