//uva 247, 11709
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 25;
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

vector< vector<int> > detectSCC(const Graph &G)
{
  const int size = G.size();
  bool visited[size];
  int order[size], scc[size], time, prev = size - 1;
  vector< vector<int> > S;
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
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[order[i]]){
      visit(H, order[i], scc, time, visited);
      int j = prev;
      vector<int> T;
      for(j=prev; 0 <= j && scc[j] != -1; --j)
	T.push_back(scc[j]);
      prev = j;
      S.push_back(T);
    }
  }
  return S;
}

bool cmp(vector<int> a, vector<int> b)
{
  return a[0] < b[0];
}

int main(void)
{
  int tc = 0;
  while(true){    
    int node, edge;
    cin >> node >> edge;
    if(node == 0 && edge == 0){
      break;    
    }
    Graph g(node);
    for(int i=0; i<edge; ++i){
      int src, dst, type;
      cin >> src >> dst >> type;
      --src;
      --dst;
      g[src].push_back(Edge(src, dst));
      if(type == 2){
	g[dst].push_back(Edge(dst, src));
      }
    }
    cout << (int)(detectSCC(g).size() == 1) << endl;
  }
  return 0;
}
