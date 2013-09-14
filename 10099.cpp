#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int N = 100 + 1;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int sssp(const Graph &G, int source, int sink, set<int> &S)
{
  const int size = G.size();
  static bool visited[N];
  set<int>::iterator itr;
  int l = 0, r = (int)S.size() - 1, c, re;
  for(; l+1 < r; ){
    c = (l + r) / 2;
    itr = S.begin();
    for(int i=0; i<c; ++i)++itr;
    queue<int> Q;
    fill(visited, visited + size, false);
    for(Q.push(source); !Q.empty() && !visited[sink]; Q.pop()){
      int n = Q.front();    
      FOR(e, G[n]){
	if(visited[e->dst] || e->cost < *itr)continue;
	visited[e->dst] = true;
	Q.push(e->dst);
      }
    }
    if(visited[sink]){
      re = *itr;
      l = c;
    }
    else r = c;
  }
  return re;
}

int main(void)
{
  int d[N][N];
  int tc = 0, src, dst, cost, req, result;
  for(int node, edge; ; ){
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    
    fill(&d[0][0], &d[N-1][N], -1);
    
    for(int i=0; i<edge; ++i){
      cin >> src >> dst >> cost;
      --src; --dst;
      d[src][dst] = d[dst][src] = cost;
    }

    REP(k, node){
      REP(i, node){
	REP(j, node){	
	  d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
	}
      }
    }
    
    cin >> src >> dst >> req;
    --src; --dst;
    //cout << d[src][dst] << endl;

    result = req / (d[src][dst] - 1);
    if(req % (d[src][dst] - 1))++result;

    /*

    Graph G(node);
    set<int> S;
    for(int i=0; i<edge; ++i){
      cin >> src >> dst >> cost;
      --src; --dst;
      G[src].push_back(Edge(dst, cost));
      G[dst].push_back(Edge(src, cost));
      S.insert(cost);
    }
    cin >> src >> dst >> req;
    if(src != dst){
      int r = sssp(G, src - 1, dst - 1, S) - 1;
      result = req / r;
      if(req % r)++result;
    }
    else result = 1;
     */
    cout << "Scenario #" << ++tc << endl;
    cout << "Minimum Number of Trips = " << result << endl << endl;
  }
  return 0;
}
