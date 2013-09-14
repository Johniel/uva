//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = (400 + 1) * (79800 + 1);
static const int FAIL = -1;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
  Edge(int s, int d, int c) : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost < b.cost;
  if(a.src != b.src)return a.src < b.src;
  return a.dst < b.dst;
}

class DisjointSet{
public: 
  vector<int> rank, p;
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
    REP(i, size){
      p[i] = i;
      rank[i] = 0;
    }
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
void kruskal(Edges E, int node)
{
  DisjointSet ds(node);
  int idx[node];
  int result = 0, cnt = 0, tmp = 0;
  sort(ALL(E));
  FOR(e, E){    
    if(!ds.isSameSet(e->src, e->dst)){
      ds.join(e->src, e->dst);
      result += e->cost;
      idx[cnt++] = tmp;
    }
    ++tmp;
  }
  cout << result << ' ';
  result = INF;
  REP(i, cnt){
    DisjointSet ds2(node);
    Edges F = E;
    F.erase(F.begin() + idx[i]);
    int size = 0;
    tmp = 0;
    FOR(e, F){    
      if(!ds2.isSameSet(e->src, e->dst)){
	ds2.join(e->src, e->dst);
	tmp += e->cost;
	++size;
      }
    }
    if(node - 1 == size)
      result = min(result, tmp);
  }
  cout << result << endl;
  return ;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    Edges E;
    int node, edge, src, dst, cost;
    cin >> node >> edge;
    for(int i=0; i<edge; ++i){
      cin >> src >> dst >> cost;
      E.push_back(Edge(src - 1, dst - 1, cost));
    }
    kruskal(E, node);
  }
  return 0;
}
