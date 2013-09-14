#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)
#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

const int NODE = 500 * 2 + 1;

struct Edge{
 int src, dst, cost;
 Edge(int s, int d, int c)
   : src(s), dst(d), cost(c) {};
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct State{
 int node, cost, cnt;
 State(int n, int co, int cn)
   : node(n), cost(co), cnt(cn) {}
};

bool operator < (State a, State b)
{
 return a.cost > b.cost;
}

int sssp(const Graph &graph, int src, int dst)
{
 static bool visited[2][NODE];
 priority_queue<State> q;
 fill(&visited[0][0], &visited[1][NODE], false);
 for(q.push(State(src, 0, 0)); !q.empty(); ){
   State s = q.top();
   q.pop();
   if(visited[s.cnt][s.node])continue;
   if(s.node == dst && s.cnt == 0){
     return s.cost;
   }
   visited[s.cnt][s.node] = true;
   int t = (s.cnt + 1) % 2;
   FOR(e, graph[s.node]){
     if(!visited[t][e->dst]){
       q.push(State(e->dst, s.cost + e->cost, t));
     }
   }
 }

 return -1;
}
int main(void)
{
 int tc = 0;
 for(int node, edge; cin >> node >> edge; ){
   Graph graph(node);
   REP(i, edge){
     int src, dst, cost;
     cin >> src >> dst >> cost;
     graph[src].push_back(Edge(src, dst, cost));
     graph[dst].push_back(Edge(dst, src, cost));
   }
   cout << "Set #" << ++tc << endl;
   int result = sssp(graph, 0, node-1);
   if(result == -1)cout << "?" << endl;
   else cout << result << endl;
 }
 return 0;
}
