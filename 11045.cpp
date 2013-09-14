//uva 11138
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

static const int NODE = 36 + 360+ 2;// MAX_NODE
static const int INF = 1 << 20;

struct Edge{
  int src, dst, cap;
  Edge(int s, int d, int c) : 
    src(s), dst(d), cap(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int flow[NODE][NODE];
int cap[NODE][NODE];
int layer[NODE];
int path[NODE];

inline int residue(int src, int dst)
{
  return cap[src][dst] - flow[src][dst];
}

bool makeLayer(const Graph &G, int src, int sink)
{
  queue< pair<int, int> > Q;// (node, cost)
  fill(layer, layer + G.size(), INF);
  for(Q.push(make_pair(src, 0)); !Q.empty()/*&& layer[sink] == INF*/; Q.pop()){
    int node = Q.front().first, cost = Q.front().second;
    if(cost < layer[node]){
      layer[node] = cost;
      FOR(e, G[node]){
	if(residue(e->src, e->dst))
	  Q.push(make_pair(e->dst, cost + 1));
      }
    }
  }
  return layer[sink] < INF;
}

int DFS(const Graph &G, int node, int sink, int depth)
{
  if(depth == -1)return 0;
  path[depth] = node;
  if(node == sink)return INF;
  FOR(e, G[node]){
    int res = residue(e->src, e->dst);
    if(!res)continue;
    int mf = DFS(G, e->dst, sink, depth-1);
    if(mf)return min(mf, res);
  }
  return 0;
}

int Dinic(const Graph &G, int source, int sink)
{
  const int size = G.size();
  REP(i, size)FOR(e, G[i]){
    cap[e->src][e->dst] = e->cap;// no parallel edge
    flow[e->src][e->dst] = 0;
  }
  int total = 0;
  path[0] = sink;
  while(makeLayer(G, source, sink)){
    for(int mf; mf = DFS(G, source, sink, layer[sink]); total+=mf){
      REP(i, layer[sink]){
	flow[path[i + 1]][path[i]] += mf;
	flow[path[i]][path[i + 1]] -= mf;
      }
    }
  }
  //cout << total << endl;
  return total;
}

int main(void)
{
  const int SOURCE = 0, SINK = 1;
  map<string, int> M;
  M["XXL"] = 2;
  M["XL"] = 3;
  M["L"] = 4;
  M["M"] = 5;
  M["S"] = 6;
  M["XS"] = 7;
  int tc;
  cin >> tc;
  while(tc--){    
    int s, v;
    cin >> s >> v;
    Graph G(NODE);
    REP(i, 6)
      G[SOURCE].push_back(Edge(SOURCE, i + 2, s/6));
    REP(i, v){
      int dst = i + 8;
      REP(j, 2){
	string t;
	cin >> t;
	int src = M[t];
	G[src].push_back(Edge(src, dst, 1));
	G[dst].push_back(Edge(dst, src, 0));
      }
      G[dst].push_back(Edge(dst, SINK, 1));
    }
    if(Dinic(G, SOURCE, SINK) == v)cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
