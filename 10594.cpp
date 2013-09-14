#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <cstdlib>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i != (c).end();++i)

using namespace std;

typedef long long lli;

static const int MAX = 21 + 21 + 2;
static const lli LIM = 1000000000000000ll;
static const lli INF = 1ll << 55;

struct Edge{
  lli src, dst, capacity, cost;
  bool forward;
  Edge(lli f, lli t, lli ca, lli co) :
    src(f), dst(t), capacity(ca), cost(co){}
};
  
bool operator < (const Edge &a, const Edge &b){
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.capacity != b.capacity)return a.capacity < b.capacity;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

pair<lli, lli> minCostFlow(const Graph &G, const lli &source, const lli &sink, lli required)
{
  pair<lli, lli> result = make_pair(0, 0);//cost, flow
  const int size = G.size();
  lli capacity[size][size], cost[size][size], flow[size][size], p[size], dist[size], rsd[size];
  fill(rsd, rsd + size, 0);
  REP(i, size)FOR(e, G[i]){
    capacity[e->src][e->dst] = e->capacity;
    cost[e->src][e->dst] = e->cost;
    flow[e->src][e->dst] = 0;
  }
  for(;0ll < required;){
    fill(p, p + size, -1);
    fill(dist, dist + size, INF);
    priority_queue<Edge> Q;
    for(Q.push(Edge(source, source, INF, 0)), dist[source] = 0; !Q.empty();){
      Edge next = Q.top(); Q.pop();
      if(p[next.dst] != -1)continue;
      p[next.dst] = next.src;
      FOR(e, G[next.dst])if(0 < capacity[e->src][e->dst] - flow[e->src][e->dst]){
	lli rcost = cost[e->src][e->dst] + rsd[e->src] - rsd[e->dst];
	if(dist[e->src] + rcost < dist[e->dst]){
	  dist[e->dst] = rcost + dist[e->src];
	  Q.push(Edge(e->src, e->dst, 0, dist[e->dst]));
	}
      }
    }
    if(p[sink] == -1)break;
    REP(i, size)rsd[i] += dist[i];
    lli minflow = required;
    for(int i=sink; i != p[i]; i=p[i])
      minflow = min(minflow, capacity[p[i]][i] - flow[p[i]][i]);
    for(int i=sink; i != p[i]; i=p[i]){
      result.first += minflow * cost[p[i]][i];
      flow[p[i]][i] += minflow;
      flow[i][p[i]] -= minflow;
    }
    required -= minflow;
    result.second += minflow;
  }
  return result;
}

int main(void)
{
  lli node, route, src, dst,  cost, produce, c; 
  while(scanf("%lld%lld", &node, &route) != EOF){
    Graph G;
    G.resize(node*2);
    REP(i, route){
      scanf("%lld%lld%lld", &src, &dst, &cost);

      --src; --dst;
      G[src].push_back(Edge(src, dst, 1, cost));//adge(s, d, capacoty, cost)
      G[dst].push_back(Edge(dst, src, 0, -cost));//have to add rev.edge(d, s, 0, -cost)

      src += node; dst += node;//when given graph is undirected
      G[src].push_back(Edge(src, dst, 0, -cost));
      G[dst].push_back(Edge(dst, src, 1, cost));
    }
    scanf("%lld%lld", &produce, &c);
    REP(i, G.size())REP(j, G[i].size())G[i][j].capacity *= c;
    REP(i, node){
      G[i].push_back(Edge(i, i + node, INF, 0));
      G[i + node].push_back(Edge(i + node, i, INF, 0));
    }
    pair<lli, lli> result = minCostFlow(G, 0, node-1, produce);
    if(produce == result.second)cout << result.first << endl;
    else cout << "Impossible." << endl;
  }
  return 0;
}
