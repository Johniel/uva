#include <iostream>
#include <algorithm>
#include <vector>

#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

struct Edge{
  int src, dst; 
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int NODE = 10000 + 1;

void rec(const Graph &graph, int node, int &cnt, bool visited[])
{
  visited[node] = true;
  ++cnt;
  FOR(e, graph[node]){
    if(visited[e->dst])continue;
    rec(graph, e->dst, cnt, visited);
  }
  return ;
}

int main(void)
{
  int tc;
  bool visited[NODE];
  for(cin >> tc; tc--; ){
    int node, edge, knock, src, dst, total = 0;
    cin >> node >> edge >> knock;
    Graph graph(node);
    fill(visited, visited + node, false);
    for(int i=0; i<edge; ++i){
      cin >> src >> dst;
      --src;
      --dst;
      graph[src].push_back(Edge(src, dst));
    }
    for(int i=0; i<knock; ++i){
      int tar, cnt = 0;
      cin >> tar;
      --tar;
      if(visited[tar])continue;
      rec(graph, tar, cnt, visited);
      total += cnt;
    }
    cout << total << endl;
  }
  return 0;
}
