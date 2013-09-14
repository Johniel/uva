#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = INT_MAX;
static const int FAIL = -1;
static const int NODE = 200000 + 1;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
  Edge(int s, int d, int c) 
  : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost < b.cost;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

class DisjointSet{
public: 
  int rank[NODE], p[NODE];
  DisjointSet(){}
  void make(int a){
    rank[a] = 0;
    p[a] = a;
  }
  void join(int a, int b){
    link(find(a), find(b));
  }
  int find(int a){
    return (a == p[a])? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b){
    return find(a) == find(b);
  }
  void link (int a, int b){
    if(rank[a] > rank[b])
      p[b] = a;
    else{
      p[a] = b;
      if(rank[a] == rank[b])
	rank[b]++;
    }
  }
};

inline
int kruskal(Edge E[], const int size)
{
  static DisjointSet ds;
  int cnt = 0, sum = 0;
  REP(i, size){
    ds.make(i);
  }
  sort(E, E + size);
  REP(i, size){
    if(!ds.isSameSet(E[i].src, E[i].dst)){
      ds.join(E[i].src, E[i].dst);
      sum += E[i].cost;
      if(++cnt == size-1)break;
    }
  }
  return sum;
}

int main(void)
{  
  static Edge E[NODE];
  while(true){
    int node, edge, sum = 0;
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    Graph G(node);
    REP(i, edge){
      cin >> E[i].src >> E[i].dst >> E[i].cost;
      sum += E[i].cost;
    }
    cout << sum - kruskal(E, edge) << endl;
  }  
  return 0;
}
