#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 20 + 1, INF = 1 << 20;

struct Edge{
  int dst;
  Edge(int d) : dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool isConnectedGraph(const Graph &G, int src)
{
  const int size = G.size();
  stack<int> S;
  bool visited[size];
  fill(visited, visited + size, false);
  visited[0] = true;
  for(S.push(src); !S.empty();){
    int n = S.top();
    S.pop();
    visited[n] = true;
    FOR(e, G[n]){
      if(visited[e->dst])return false;
      S.push(e->dst);
    }
  }
  return count(visited, visited + size, true) == size;
}

bool isTree(const Graph &G)
{
  const int size = G.size();
  REP(i, size){
    if(isConnectedGraph(G, i))
      return true;
  }
  return false;
}

int main(void)
{
  int tc = 0;
  while(true){
    int cnt = 0;
    map<int, int> M;
    map< pair<int, int>, bool > S;
    Graph G(500);
    bool flg = true;
    REP(i, INF){
      int src, dst;
      cin >> src >> dst;
      if(src == 0 && dst == 0)break;
      if(src < 0 && dst < 0)return 0;
      if(M[src] == 0)M[src] = ++cnt;
      if(M[dst] == 0)M[dst] = ++cnt;  
      flg = flg && !S[make_pair(M[src], M[dst])];
      S[make_pair(M[src], M[dst])] = true;
      G[M[src]].push_back(Edge(M[dst]));
    }
    G.resize(cnt+1);
    cout << "Case " << ++tc << " is " 
	 << (flg && isTree(G)? "" : "not ") << "a tree." << endl;
  }
  return 0;
}
