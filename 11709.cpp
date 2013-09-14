#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 1000;
static const int INF = 1 << 20;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(const Graph &G, int n, int order[], int &time, bool visited[])
{
  visited[n] = true;
  FOR(e, G[n]){
    if(!visited[e->dst])
      visit(G, e->dst, order, time, visited);
  }
  order[--time] = n;
  return ;
}

void detectSCC(const Graph &G)
{
  const int size = G.size();
  static bool visited[NODE];
  static int order[NODE], scc[NODE];
  int time, prev = size - 1;
  Graph H(size);
  fill(order, order + size, -1);
  fill(scc, scc + size, -1);
  REP(i, size){
    FOR(e, G[i])
      H[e->dst].push_back(Edge(e->dst, e->src));
  }
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[i])
      visit(G, i, order, time, visited);
  }
  int cnt = 0;
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[order[i]]){
      visit(H, order[i], scc, time, visited);
      cnt++;
    }
  }
  cout << cnt << endl;
  return ;
}

int main(void)
{
  int tc = 0;
  while(true){    
    int node, edge, cnt = 0;
    Graph G;
    map<string, int> M;
    cin >> node >> edge;
    cin.ignore();
    if(node == 0 && edge == 0)
      break;    
    if(tc)cout << endl;
    G.resize(node);
    REP(i, node){
      string name;
      getline(cin, name);
      M[name] = i;
    }
    REP(i, edge){
      string src, dst;
      getline(cin, src);
      getline(cin, dst);
      int s = M[src], d = M[dst];
      G[s].push_back(Edge(s, d));
    }    
    detectSCC(G);
  }
  return 0;
}
