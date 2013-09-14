#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int src, dst, cost;
  Edge(int s, int d, int c) 
    : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int NODE = 100000;
const int INF = 1 << 20;
const int STORE = 10 + 1;

int tsp(int src, int adj[STORE][STORE], int node)
{
  const int T = 1 << STORE;
  static int t[STORE][T];

  fill(&t[0][0], &t[STORE-1][T], INF);
  REP(i, node)t[i][1 << i] = adj[src][i];

  for(int s=1; s<(1 << node); ++s){
    REP(i, node){
      if(!(s & (1 << i)))continue;
      REP(j, node){
	if(s & (1 << j))continue;
	int tmp = t[i][s] + adj[i][j];
	if(tmp < t[j][s | (1 << j)]){
	  t[j][s | (1 << j)] = tmp;
	}
      }
    }
  }
  return t[src][(1 << node) - 1];
}

struct State{
  int node, cost;
  State(int n, int c) : node(n), cost(c) {}
};
bool operator < (const State &a, const State &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.node < b.node;
}

void sssp(int src, int dist[], const Graph &g)
{
  const int size = g.size();
  priority_queue<State> q;
  static bool visited[NODE];
  fill(dist, dist + size, INF);
  fill(visited, visited + size, false);
  for(q.push(State(src, 0)); !q.empty(); ){
    State s = q.top();
    q.pop();
    if(visited[s.node])continue;
    visited[s.node] = true;
    FOR(e, g[s.node]){
      if(visited[e->dst])continue;
      int tmp = e->cost + s.cost;
      if(tmp < dist[e->dst]){
	dist[e->dst] = tmp;
	q.push(State(e->dst, tmp));
      }
    }
  }
  return ;
}

int main(void)
{
  int tc;
  int store[STORE], dist[NODE];
  int adj[STORE][STORE];
  for(cin >> tc; tc--; ){
    int node, edge;
    cin >> node >> edge;
    Graph g(node);
    REP(i, edge){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      g[src].push_back(Edge(src, dst, cost));
      g[dst].push_back(Edge(dst, src, cost));
    }
    int s;
    cin >> s;
    REP(i, s){
      cin >> store[i];
    }
    store[s++] = 0;
    REP(i, s){
      sssp(store[i], dist, g);
      REP(j, s){
	adj[i][j] = adj[j][i] = 
	  (i == j) ? INF : dist[store[j]];
      }
    }
    cout << tsp(s-1, adj, s) << endl;
  }
  return 0;
}
