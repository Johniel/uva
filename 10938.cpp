#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long int lli;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

const int NODE = 5000 + 1;

bool visited[NODE];
int path[NODE], size = 0;

bool rec(Edges g[], int node, int lim)
{
  if(node == lim){
    path[size++] = node;
    return true;
  }
  visited[node] = true;
  FOR(e, g[node]){
    if(visited[e->dst])continue;
    if(rec(g, e->dst, lim)){
      path[size++] = node;
      return true;
    }
  }
  return false;
}

int main(void)
{
  for(int node; scanf("%d", &node) && node; ){
    int src, dst;
    int q, a, b;
    int edge = node - 1;
    Edges g[node];
    REP(i, edge){
      scanf("%d%d", &src, &dst);    
      --src;
      --dst;
      g[src].push_back(Edge(src, dst));
      g[dst].push_back(Edge(dst, src));
    }
    scanf("%d", &q);
    REP(i, q){
      scanf("%d%d", &a, &b);    
      --a;
      --b;
      size = 0;
      fill(visited, visited + node, false);
      fill(path, path + node, -1);

      rec(g, a, b);
      
      //REP(i, size)cout << path[i] + 1 << ' ' ; cout << endl;

      if(size % 2){
	printf("The fleas meet at %d.\n", path[size / 2] + 1);
      }
      else{
	int n = min(path[size / 2], path[size / 2 - 1]) + 1;
	int m = max(path[size / 2], path[size / 2 - 1]) + 1;	
	printf("The fleas jump forever between %d and %d.\n", n, m);
      }
    }
  }
  return 0;
}
