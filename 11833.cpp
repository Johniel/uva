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
    : src(s), dst(d), cost(c) {
    //cout << src << ' ' << dst << ' ' << cost << endl;
  }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct State{
  int node, cost;
  State(int n, int c) : node(n), cost(c) {}
};
bool operator < (const State &a, const State &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.node < b.node;
}

const int INF = 1 << 22;

int sssp(const Graph &g, int src, int dst)
{
  const int size = g.size();
  priority_queue<State> q;
  int weight[size];
  bool visited[size];
  fill(weight, weight + size, INF);
  fill(visited, visited + size, false);
  q.push(State(src, 0));
  weight[src] = 0;
  while(!q.empty()){
    State s = q.top();
    q.pop();
    if(visited[s.node])continue;
    if(s.node == dst)break;
    visited[s.node] = true;
    FOR(e, g[s.node]){
      if(visited[e->dst])continue;
      if(weight[e->dst] > e->cost + weight[e->src]){
	weight[e->dst] = e->cost + weight[e->src];
	q.push(State(e->dst, weight[e->dst]));
      }
    }
  }
  return weight[dst];
}

void add_edge(Graph &g, int src, int dst, int cost, int c, int k)
{
  if(c <= src && c <= dst){
    g[src].push_back(Edge(src, dst, cost));
  }
  if(src < c && c <= dst);
  else{
    if(src < c && dst < c){
      if(src + 1 == dst){
	g[src].push_back(Edge(src, dst, cost));
      }
    }
    else {
      g[src].push_back(Edge(src, dst, cost));
    }
  }
  return ;
}

int main(void)
{
  while(true){
    int node, edge, c, k;
    cin >> node >> edge >> c >> k;
    if(node + edge + c + k == 0){
      break;
    }
    Graph g(node);
    REP(i, edge){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      add_edge(g, src, dst, cost, c, k);
      add_edge(g, dst, src, cost, c, k);
    }
    cout << sssp(g, k, c-1) << endl;
  }
  return 0;
}
