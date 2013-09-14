//uva 10054
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int NODE = 50 + 1;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

#include <stack>
inline
bool isConnectedGraph(const Graph &graph)
{
  const int size = graph.size();
  static bool visited[NODE];
  fill(visited, visited + size, false);
  REP(i, NODE){
    visited[i] = graph.size() != 0;
  }
  stack<int> s;
  visited[0] = true;
  for(s.push(0); !s.empty(); ){
    int node = s.top();
    s.pop();
    FOR(e, graph[node]){
      if(visited[e->dst])continue;
      visited[e->dst] = true;
      s.push(e->dst);
    }
  }
  return count(visited, visited + size, true) == size;
}

typedef vector< pair<int, int> > Path;
int adj[NODE][NODE];

inline
Path buildPath(const Graph &graph, int node)
{
  vector<Path> path;
  REP(i, graph[node].size()){
    Edge e = graph[node][i];
    if(adj[e.src][e.dst] && adj[e.dst][e.src]){      
      --adj[e.src][e.dst];
      --adj[e.dst][e.src]; 
      Path tmp = buildPath(graph, e.dst);
      tmp.insert(tmp.begin(), make_pair(e.src+ 1, e.dst+ 1));
      path.push_back(tmp);
    }
  }
  Path re; 
  for(int i=1; i<path.size(); ++i){
    FOR(p, path[i]){
      re.push_back(*p);
    }
  }
  if(path.size()){
    FOR(p, path[0]){
      re.push_back(*p);
    }
  }
  return re;
}

int main(void)
{
  int tc, cnt = 0;
  for(scanf("%d", &tc); tc--; ){
    int edge, c = 0, src, dst, start;
    Graph graph(NODE);
    fill(&adj[0][0], &adj[NODE-1][NODE], 0);
    scanf("%d\n", &edge);
    REP(i, edge){
      scanf("%d %d\n", &src, &dst);
      --src; --dst;
      ++adj[src][dst];
      ++adj[dst][src];
      graph[src].push_back(Edge(src, dst));
      graph[dst].push_back(Edge(dst, src));
      start = src;
    }
    cout << "Case #" << ++cnt << endl;
    if(isConnectedGraph(graph)){
      bool flg = true;
      REP(i, NODE){
	int degree = (int)graph[i].size() - adj[i][i];
	if(degree % 2){	  
	  flg = false;
	  break;
	}
      }
      if(flg){
	Path path = buildPath(graph, src);
	REP(i, path.size()){
	  printf("%d %d\n", path[i].first, path[i].second);
	}
      }
      else puts("some beads may be lost");
    }
    else puts("some beads may be lost");
    if(tc)cout << endl;
  }
  return 0;
}
