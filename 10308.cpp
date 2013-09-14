#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <utility>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int NODE = 10001;

int compute(const Graph &G)
{
  const int size = G.size();
  pair<int, int> result = make_pair(1, -1);
  for(int i=2; i--; ){
    stack< pair<int, int> > S;// node, cost
    static bool visited[NODE];
    fill(visited, visited + size, false);
    visited[result.first] = true;
    for(S.push(make_pair(result.first, 0)); !S.empty(); ){
      pair<int, int> n = S.top();
      S.pop();
      if(result.second < n.second)
	result = n;
      FOR(e, G[n.first]){
	if(visited[e->dst])continue;
	visited[e->dst] = true;
	S.push(make_pair(e->dst, e->cost + n.second));
      }
    }
  }
  return result.second;
}

int main(void)
{
  while(true){
    string s;
    Graph G(NODE);
    while(getline(cin, s)){ 
      if(s.size() == 0)break;
      istringstream iss(s);
      int src, dst, cost;
      iss >> src >> dst >> cost;
      G[src].push_back(Edge(dst, cost));
      G[dst].push_back(Edge(src, cost));
    }
    cout << compute(G) << endl;
    if(cin.eof())break;
  }
  return 0;
}
