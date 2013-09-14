//uva11183 Edmond's algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int INF = 1 << 20;
const int FAIL = -1;
const int NODE = 1000;

struct Edge{
  int src, dst, cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
  Edge(int s, int d, int c) : 
    src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

// we should not use most effective DisjointSet 
class PseudoSet{
public:
  int *p, size;
  PseudoSet(int s){
    size = s;
    p = new int[size];
    REP(i, size)p[i] = i;
  }
  ~PseudoSet(){
    delete p;
  }
  int find(int a){
    return (a == p[a])? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b){
    return find(a) == find(b);
  }
  void join(int a, int b){
    p[find(b)] = find(a);
  }
  vector<int> getRepresentative(void){
    vector<int> r;
    REP(i, size){
      if(p[i] == i)
	r.push_back(i);
    }
    return r;
  }
  operator = (PseudoSet ps){
    REP(i, size)p[i] = ps[i];
  }
};

bool operator == (const Edge &a, const Edge &b)
{
  return (a.cost == b.cost) && (a.src == b.src) && (a.dst == b.dst); 
}

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.src != b.src)return a.src > b.src;
  return a.dst > b.dst; 
}

inline
Edges expandNode(Edges E, Edges income, Edge arc, Edge c, 
		 PseudoSet P, const int &size)
{
  Edges R(size);
  for(Edge f = arc; f.cost != INF; f = income[P.find(f.src)]){
    int dst = P.find(f.dst);
    if(R[dst].cost != INF)continue;
    R[dst] = f; 
  } 
  FOR(e, E){
    if(e->cost == INF)continue;
    R[P.find(e->dst)] = *e;
  }
  return R;
}

inline 
void transferEdge(priority_queue<Edge> &A, priority_queue<Edge> &B, int mdf)// B to A
{
  const int size = B.size();
  Edge modify[size];
  REP(i, size){
    modify[i] = B.top();
    B.pop();
  }
  REP(i, size){
    if(modify[i].cost != INF)
      modify[i].cost -= mdf;
    A.push(modify[i]);    
  }
  return ;
}

Edges mergeCycle(priority_queue<Edge> Q[], PseudoSet S, PseudoSet W, 
		 stack<int> &roots, Edges income, const int &size)
{
  PseudoSet prev(S.size);
  prev = S;
  int n, val = INF;
  Edge e, valid;
  while(true){   
    if(roots.empty()){ 
      Edges E(size);
      vector<int> re = S.getRepresentative();
      FOR(i, re)E[*i] = income[*i];
      return E;
    }
    n = roots.top();
    e = Q[n].top();
    Q[n].pop();
    roots.pop();
    if(e.cost == INF)continue;
    valid = e;
    if(S.isSameSet(e.src, n))
      roots.push(n);
    else{
      if(W.isSameSet(e.src, e.dst))break;
      W.join(e.src, e.dst);
      income[n] = e;
    }
  }
  for(Edge f = e; f.cost != INF; f = income[S.find(f.src)]){
    if(val > f.cost)
      val = f.cost;
  }
  transferEdge(Q[n], Q[n], e.cost - val);
  for(Edge f = e; f.cost != INF; f = income[S.find(f.src)]){
    int s = S.find(f.dst);
    if(s == n)continue;
    transferEdge(Q[n], Q[s], income[s].cost - val);
    S.join(n, s);
  }
  e = Q[n].top();
  roots.push(n);
  return expandNode(mergeCycle(Q, S, W, roots, income, size), income, valid, e, prev, size);
}

Graph buildMST(Edges E, int adj[NODE][NODE])
{
  Graph G(E.size());
  FOR(e, E){
    if(e->cost == INF)continue;
    e->cost = adj[e->src][e->dst];
    G[e->src].push_back(*e);
  }
  return G;
}

Graph directedMST(const Graph &G, int root)
{
  const int size = G.size();
  static int adj[NODE][NODE];
  priority_queue<Edge> Q[size];
  PseudoSet S(size), W(size);
  stack<int> roots;
  fill(&adj[0][0], &adj[size-1][size], INF);
  REP(i, size){
    FOR(e, G[i]){
      Q[e->dst].push(*e);
      adj[e->src][e->dst] = min(e->cost, adj[e->src][e->dst]);
    }
    Q[i].push(Edge());
    roots.push(i);
  }
  while(Q[root].top().cost != INF)
    Q[root].pop();
  return buildMST(mergeCycle(Q, S, W, roots, Edges(size), size), adj);
}

bool isConnectedGraph(const Graph &G, int root)
{
  const int size = G.size();
  static bool visited[NODE];
  stack<int> S;
  fill(visited, visited + size, false);
  for(S.push(root); !S.empty();){
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

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;
  while(tc--){
    const int root = 0;
    int node, edge;
    cin >> node >> edge;
    Graph G(node);
    REP(i, edge){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      G[src].push_back(Edge(src, dst, cost));
    }
    int sum = -1;
    if(node == 0)
      sum = 0;
    else if(isConnectedGraph(G, root)){
      ++sum;
      Graph MST = directedMST(G, root);
      REP(i, node){
	FOR(e, MST[i])
	  sum += e->cost;
      }
    }
    cout << "Case #" << ++cnt << ": ";
    if(sum < 0)cout << "Possums!" << endl;
    else  cout << sum << endl;
  }
  return 0;
}
