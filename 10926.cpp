#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int NODE = 100 + 1;

int solve(const Graph &g)
{
  const int size = g.size();
  static bool visited[NODE];
  int dep = -1;
  int result;
  REP(i, size){
    fill(visited, visited + size, false);
    stack<int> s;
    int cnt = 0;
    for(s.push(i); !s.empty(); ){
      int n = s.top();
      s.pop();
      ++cnt;
      FOR(e, g[n]){
	if(visited[e->dst])continue;
	s.push(e->dst);
	visited[e->dst] = true;
      }
    }
    if(dep < cnt){
      dep = cnt;
      result = i;
    }
  }
  return result;
}


int main(void)
{
  for(int n; cin >> n && n; ){
    Graph g(n);
    REP(i, n){
      int edge, src, dst;
      cin >> edge;
      REP(j, edge){
	cin >> dst;
	g[i].push_back(Edge(i, dst - 1));
      }
    }
    cout << solve(g) + 1 << endl;
  }
  return 0;
}
