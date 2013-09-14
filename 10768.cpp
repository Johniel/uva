#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 20;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool isK33(int node, int degree[])
{
  int t = 0, z = 0;
  REP(i, node){
    if(degree[i] == 3)++t;
    else if(degree[i] == 0)++z;
    else return false;
  }
  return t == 6 && t + z == node;
}

bool isK5(int node, int degree[])
{
  int f = 0, z = 0;
  REP(i, node){
    if(degree[i] == 4)++f;
    else if(degree[i] == 0)++z;
    else return false;
  }
  return f == 5 && f + z == node;
}

// it judge a given graph is Homeomorphic with K33 or K5
bool isHomeomorphic(bool adj[NODE][NODE], const int node)
{
  while(true){
    int cnt = 0;
    REP(i, node){
      vector<Edge> v;
      REP(j, node && v.size() < 3){
	if(adj[i][j] && i != j){
	  v.push_back(Edge(i, j));
	}
      }
      if(v.size() == 1){
	adj[i][v[0].dst] = adj[v[0].dst][i] = false;
      }
      else if(v.size() == 2){
	adj[i][v[0].dst] = adj[v[0].dst][i] = false;
	adj[i][v[1].dst] = adj[v[1].dst][i] = false;
	adj[v[0].dst][v[1].dst] = adj[v[1].dst][v[0].dst] = true;
	++cnt;
      }
    }
    if(cnt == 0)break;
  }
  static int degree[NODE];
  fill(degree, degree + node, 0);
  REP(i, node){
    for(int j=i+1; j<node; ++j){
      if(!adj[i][j])continue;
      ++degree[i];
      ++degree[j];
    }
  }
  return  !(isK33(node, degree) || isK5(node, degree));
}

int main(void)
{
  bool adj[NODE][NODE];
  for(int node, edge; cin >> node >> edge; ){
    fill(&adj[0][0], &adj[NODE-1][NODE], false);
    REP(i, edge){
      int src, dst;
      cin >> src >> dst;
      --src;
      --dst;
      adj[src][dst] = adj[dst][src] = true;
    }
    cout << (isHomeomorphic(adj, node)? "YES" : "NO") << endl;
  }
  return 0;
}
