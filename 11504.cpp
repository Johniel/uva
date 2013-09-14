//uva 247, 11709
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <cstdio>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;


const int NODE = 100000 + 1;

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
  static bool visited[NODE];
  static int order[NODE], scc[NODE];
  int time, prev = size - 1;
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


int main(void)
{
  int tc, income[NODE], cnt[NODE], color[NODE];
  for(cin >> tc; tc--; ){
    int node, edge;
    scanf("%d %d", &node, &edge);
    Graph G(node);
    fill(income, income + node, 0);
    fill(cnt, cnt + node, 0);
    REP(i, edge){
      int src, dst;
      scanf("%d %d", &src, &dst);
      --src, --dst;
      ++income[dst];
      G[src].push_back(Edge(src, dst));
    }    
    int ele = 0;
    vector< vector<int> > scc;
    if(edge)scc= detectSCC(G);
    REP(i, scc.size()){
      FOR(v, scc[i]){
	++ele;
	color[*v] = i;
      }
    }
    REP(i, node){
      FOR(e, G[i]){
	if(color[e->src] != color[e->dst]){
	  ++cnt[color[e->dst]];
	}
      }
    }
    cout << count(cnt, cnt + scc.size(), 0) + node - ele << endl;
  }
  return 0;
}
