 //uva 10986
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

using namespace std;

struct Edge{
  int src, dst, cost;
  Edge(int s, int d, int c) 
    : src(s), dst(d), cost(c) {}
};
bool operator < (Edge a, Edge b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int INF = 1 << 30;

int sssp(const Graph &graph, int src, int dst)
{
  const int size = graph.size();
  priority_queue<Edge> q; 
  bool visited[size];
  int cost[size];
  fill(visited, visited + size, false);
  fill(cost, cost + size, INF);
  cost[src] = 0;
  for(q.push(Edge(src, src, 0)); !q.empty(); ){
    Edge n = q.top();
    q.pop();
    if(visited[n.dst])continue;
    if(n.dst == dst)return n.cost;
    visited[n.dst] = true;
    FOR(e, graph[n.dst]){
      if(cost[e->dst] > e->cost + cost[e->src]){
	cost[e->dst] = e->cost + cost[e->src];
	q.push(Edge(e->src, e->dst, cost[e->dst]));
      }
    }
  }
  return INF;
}

int main(void)
{
  int tc = 0, n;
  for(cin >> n; n--; ){
    int node, route, start, target;
    cin >> node >> route >> start >> target;
    Graph graph(node);
    REP(i, route){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      graph[src].push_back(Edge(src, dst, cost));
      graph[dst].push_back(Edge(dst, src, cost));
    }
    int result = sssp(graph, start, target);
    cout << "Case #" << ++tc << ": ";
    if(result != INF)cout << result << endl;
    else cout << "unreachable" << endl;
  }
  return 0;
}
