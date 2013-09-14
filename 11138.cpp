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

static const int MACHINE = 10;
static const int TASK = 26;
static const int NODE = MACHINE + TASK + 2;// MAX_NODE
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

inline int residue(int src, int dst)
{
  return cap[src][dst] - flow[src][dst];
}

bool makeLayer(const Graph &G, int src, int sink)
{
  queue< pair<int, int> > Q;// (node, cost)
  fill(layer, layer + G.size(), INF);
  for(Q.push(make_pair(src, 0)); !Q.empty(); Q.pop()){
    int node = Q.front().first, cost = Q.front().second;
    if(cost < layer[node]){
      layer[node] = cost;
      FOR(e, G[node])if(residue(e->src, e->dst))
	Q.push(make_pair(e->dst, cost + 1));
    }
  }
  return layer[sink] < INF;
}

int DFS(const Graph &G, int node, int sink, int depth)
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

int Dinic(const Graph &G, int source, int sink)
{
  const int size = G.size();
  REP(i, size)FOR(e, G[i]){
    cap[e->src][e->dst] = e->cap;// no parallel edge
    flow[e->src][e->dst] = 0;
  }
  int total = 0;
  path[0] = sink;
  while(makeLayer(G, source, sink)){
    for(int mf; mf = DFS(G, source, sink, layer[sink]); total+=mf){
      REP(i, layer[sink]){
	flow[path[i + 1]][path[i]] += mf;
	flow[path[i]][path[i + 1]] -= mf;
      }
    }
  }
  return total;
}

void output(const Graph &G, int sum, int total)
{
  if(total != sum){
    cout << '!' << endl;
    return ;
  }
  REP(i, MACHINE){
    bool flg = true;
    FOR(e, G[i + TASK]){
      if(e->cap == 0 && flow[e->dst][e->src]){
	cout << (char)(e->dst + 'A');
	flg = false;
	break;
      }
    }
    if(flg)cout << '_';
  }
  cout << endl;
  return ;
}

int main(void)
{
  while(true){
    string tmp;
    vector<string> command;
    while(getline(cin, tmp) && tmp.size())
      command.push_back(tmp);
    if(command.size() == 0)
      break;
    const int source = NODE - 2, sink = NODE - 1;
    int sum = 0;
    Graph G(NODE);
    REP(i, command.size()){
      istringstream iss(command[i]);
      char name, no, task;
      iss >> task >> no;
      task -= 'A';
      sum += (no - '0');
      G[source].push_back(Edge(source, task, no-'0'));
      // if Graph is bydirection, don't forget Rev. edge
      while(iss >> name && name != ';'){
	name += (TASK - '0');
	G[task].push_back(Edge(task, name, 1));
	G[name].push_back(Edge(name, task, 0));
      }
    }
    REP(i, MACHINE){
      int j = i + TASK;
      G[j].push_back(Edge(j, sink, 1));
      G[sink].push_back(Edge(sink, j, 0));
    }
    output(G, sum, Dinic(G, source, sink));
  }
  return 0;
}

