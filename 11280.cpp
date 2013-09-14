//uva 558
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i!=(c).end(); ++i)

using namespace std;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b){
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst > b.dst;
}

const int INF = 1 << 24;
const int NODE = 100 + 1;

inline
bool BellmanFord(const Graph &G, int src, int dst, int lim)
{
  const int size = G.size();
  static int dist[NODE], buff[NODE];
  fill(dist, dist + size, INF);
  fill(buff, buff + size, INF);
  dist[src] = 0;
  ++lim;
  while(lim--){
    REP(i, size){
      if(dist[i] == INF)continue;
      FOR(e, G[i]){
	buff[e->dst] = min(buff[e->dst], dist[i] + e->cost);
      }
    }
    //copy(buff, buff + size, dist);
    REP(i, size){
      dist[i] = min(dist[i], buff[i]);
    }
    fill(buff, buff + size, INF);
  }
  
  if(dist[dst] < INF){
    cout << "Total cost of flight(s) is $" << dist[dst] << endl;
  }
  else{
    cout << "No satisfactory flights" << endl;
  }
  
  return true;//no neg cycle  
}

int main(void)
{
  int tc, num = 0;
  cin >> tc;
  while(tc--){
    int node, edge, q;
    cin >> node;
    map<string, int> name;
    int cnt = 0;
    for(int i=0; i<node; ++i){
      string s;
      cin >> s;
      name[s] = cnt++;
    }
    cin >> edge;
    Graph g(node);
    for(int i=0; i<edge; ++i){
      string src, dst;
      int cost;
      cin >> src >> dst >> cost;
      int a = name[src], b = name[dst];
      g[a].push_back(Edge(b, cost));
    }
    cin >> q;
    cout << "Scenario #" << ++num << endl;    
    int src = name["Calgary"], dst = name["Fredericton"];
    while(q--){
      int stop;
      cin >> stop;
      BellmanFord(g, src, dst, stop);      
    }
    if(tc)cout << endl;
  }
  return 0;
}

