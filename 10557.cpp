#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

using namespace std;

struct Edge{
  int src, dst, cost;
  Edge(int s, int d, int c) 
    : src(s), dst(d), cost(c) {} 
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

static const int INF = 1 << 20;

const int NODE = 100 + 1;

int dist[NODE];
int path[NODE][NODE]; 
bool adj[NODE][NODE];

bool BellmanFord(const Graph &G, int src, int dst)
{
  const int size = G.size();

  fill(dist, dist + size, INF);
  fill(&path[0][0], &path[size-1][size], -1);
  fill(&adj[0][0], &adj[size-1][size], false);

  dist[src] = 0;  

  REP(k, size-1)REP(v, size)FOR(e, G[v]){
    int tmp = dist[e->src] + e->cost;
    adj[e->src][e->dst] = true;
    if(dist[e->src] + e->cost < dist[e->dst]){
      if(100 <= dist[e->src] + e->cost)continue;
      dist[e->dst] = dist[e->src] + e->cost;
      path[e->src][e->dst] = k;
    }
  }

  REP(k, size)REP(i, size)REP(j, size){
    adj[i][j] |= adj[i][k] & adj[k][j];
  }
  
  if(dist[dst] < 100)return true;

  REP(v, size)FOR(e, G[v]){
    if(dist[e->dst] > dist[e->src] + e->cost){
      if(dist[e->dst] < 100 && adj[src][e->dst] && adj[e->dst][dst]){
	return true;
      }
    }
  }
  return false;
}

int main(void)
{
  for(int node, edge, dst, cost; ; ){
    cin >> node;
    if(node == -1)break;
    Graph G(node), H(node);
    int cost[node];    
    REP(i, node){
      cin >> cost[i] >> edge;
      REP(j, edge){
	cin >> dst;
	G[i].push_back(Edge(i, dst-1, 0));
      }
    }
    REP(src, node){
      FOR(e, G[src]){
	e->cost = -cost[e->dst];
      }      
    }
    bool flg = BellmanFord(G, 0, node-1);
    cout << (flg? "winnable" : "hopeless") << endl;
  }
  return 0;
}
