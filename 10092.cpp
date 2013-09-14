//uva 11138
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

using namespace std;

static const int NODE = 20 + 1000 + 2;// MAX_NODE
static const int INF = 1 << 20;

struct Edge{
  int src, dst, cap;
  Edge(int s, int d, int c) : 
    src(s), dst(d), cap(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int flow[NODE][NODE];
int cap[NODE][NODE];
int layer[NODE];
int path[NODE];

namespace Queue{
  const int Q = NODE * 10;
  int h = 0, t = 0;
  pair<int, int> q[Q];
  inline
  void push(pair<int, int > n){
    q[h] = n;
    h = (h + 1) % Q;
  }
  inline
  pair<int, int> front(void){
    return q[t];
  }
  inline
  void pop(void){
    t = (t + 1) % Q;
  }
  inline
  bool empty(void){
    return t == h;
  }
  inline
  void construct(void){
    h = t = 0;
  }
};

inline 
int residue(int src, int dst)
{
  return cap[src][dst] - flow[src][dst];
}

inline
bool makeLayer(const Edges G[], int src, int sink, int size)
{
  //queue< pair<int, int> > Q;// (node, cost)
  Queue::construct();
  fill(layer, layer + size, INF);
  for(Queue::push(make_pair(src, 0)); 
      !Queue::empty() && layer[sink] == INF; 
      Queue::pop()){
    int node = Queue::front().first;
    int cost = Queue::front().second;
    if(cost < layer[node]){
      layer[node] = cost;
      FOR(e, G[node])if(residue(e->src, e->dst))
	Queue::push(make_pair(e->dst, cost + 1));
    }
  }
  return layer[sink] < INF;
}

inline
int DFS(const Edges G[], int node, int sink, int depth)
{
  if(depth == -1)return 0;
  path[depth] = node;
  if(node == sink)return INF;
  FOR(e, G[node]){
    int res = residue(e->src, e->dst);
    if(!res)continue;
    int mf = DFS(G, e->dst, sink, depth-1);
    if(mf)return min(mf, res);
  }
  return 0;
}

inline
int Dinic(const Edges G[], int source, int sink, const int size)
{
  //const int size = G.size();
  REP(i, size){
    FOR(e, G[i]){
      cap[e->src][e->dst] = e->cap;// no parallel edge
    //flow[e->src][e->dst] = 0;
    }
    REP(j, size){
      flow[i][j] = 0;
    }
  }
  
  int total = 0;
  path[0] = sink;
  while(makeLayer(G, source, sink, size)){
    for(int mf; mf = DFS(G, source, sink, layer[sink]); total+=mf){
      REP(i, layer[sink]){
	flow[path[i + 1]][path[i]] += mf;
	flow[path[i]][path[i + 1]] -= mf;
      }
    }
  }
  return total;
}

#include <cstdio>
int main(void)
{
  while(true){
    int c, p;
    //cin >> c >> p;
    scanf("%d %d", &c, &p);
    if(c == 0 && p == 0)break;
    const int sink = c + p, source = c + p + 1;
    //Graph graph(c + p + 2);
    Edges graph[c + p + 2];
    int sum = 0;
    REP(i, c){
      int n;
      //cin >> n;
      scanf("%d", &n);
      sum += n;

      graph[i].push_back(Edge(i, sink, n));
    }
    REP(i, p){
      int n, m;
      //cin >> n;
      scanf("%d", &n);
      REP(j, n){
	//cin >> m;
	scanf("%d ", &m);
	graph[c + i].push_back(Edge(c + i, m - 1, 1));
	graph[m - 1].push_back(Edge(m - 1, c + i, 0));

	graph[source].push_back(Edge(source, c + i, 1));
      }
    }    

    int s = c + p + 2;
    //REP(i, s){ REP(j, s) printf("%2d ", flow[i][j]); puts(""); }  puts("");

    if(sum == Dinic(graph, source, sink, c + p + 2)){
      //cout << 1 << endl;
      puts("1");
      REP(j, c){
	bool flg = true;
	REP(i, p){
	  if(flow[i + c][j]){
	    if(flg)flg = false;
	    else printf(" ");
	    printf("%d", i + 1);
	  }
	}
	puts("");
      }
    }
    else puts("0");
  }  
  return 0;
}

