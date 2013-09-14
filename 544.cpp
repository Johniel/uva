//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int INF = (400 + 1) * (79800 + 1);
static const int FAIL = -1;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(-1) {}
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
  vector<int> rank, p;
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
  }
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

Edges kruskal(const Graph &G, int src, int dst)
{
  const int size = G.size();
  Edges E, R;
  DisjointSet ds(size);
  priority_queue<Edge> Q[size];
  REP(i, size){
    FOR(j, G[i])
      Q[j->dst].push(*j);
    ds.make(i);
  }
  while(!Q[dst].empty()){
    Edge e = Q[dst].top();
    Q[dst].pop();
    //cout << "edge : " << e.src << ' ' << e.dst << ' '<< e.cost << endl;
    if(!ds.isSameSet(e.src, e.dst)){      
      ds.join(e.src, e.dst);
      while(!Q[e.src].empty()){
	Q[dst].push(Q[e.src].top());
	Q[e.src].pop();
      }
      R.push_back(e);
      if(ds.isSameSet(src, dst))break;
    }
  }
  return R;
}

bool isConnectedGraph(const Graph &G)
{
  const int size = G.size();
  stack<int> S;
  bool visited[size];
  fill(visited, visited + size, false);
  for(S.push(0); !S.empty();){
    int n = S.top();
    S.pop();
    if(visited[n])continue;
    visited[n] = true;
    FOR(e, G[n]){
      if(!visited[e->dst])
	S.push(e->dst);
    }
  }
  return count(visited, visited + size, true) == size;
}

int dfs(Edge R[], int n, int dst)
{
  //cout << n << endl;
  return (R[n].cost == -1)? INF : min(dfs(R, R[n].src, dst), R[n].cost);
}

int main(void)
{
  int tc = 0;
  while(true){
    int node, edge, cnt = 0;
    string src, dst;
    map<string, int> M;
    cin >> node >> edge;
    if(node == 0 && edge == 0)break;
    Graph G(node + 1);
    REP(i, edge){
      int cost;
      cin >> src >> dst >> cost;
      if(M[src] == 0)M[src] = ++cnt;
      if(M[dst] == 0)M[dst] = ++cnt;
      int s = M[src], d = M[dst];
      //cout << s << ' ' << d << ' ' << cost << endl;
      G[s].push_back(Edge(s, d, cost));
      G[d].push_back(Edge(d, s, cost));
    }
    cin >> src >> dst;
    Edges mst = kruskal(G, M[src], M[dst]);
    Edge R[node + 1];
    //cout << M[src] << " -> " << M[dst] << endl;
    int re = -1;
    FOR(e, mst){
      re = max(e->cost, re);
      //cout << e->src << ' ' << e->dst << ' '<< e->cost << endl;
      R[e->dst] = *e;
    }
    cout << "Scenario #" << ++tc << endl;
    cout << dfs(R, M[dst], M[src]) << " tons" << endl << endl;    
    //cout << re << " tons" << endl << endl;    
  }  
  return 0;
}
