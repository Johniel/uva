#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cstdio>

#define REP(i,n) for(int i=0; i<(int)n; ++i)
#define FOR(i,c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

using namespace std;

static const int INF = 1 << 20;
static const int NODE = 4000 + 3;
static const int INI = 'z' + 1;

struct Edge{
  int dst, cost;
  char ini;
  Edge(int d, int c, char i) : dst(d), cost(c), ini(i) {}
};

inline
bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  if(a.ini != b.ini)return a.ini < b.ini;
  return a.dst < b.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

inline
int sssp(const Graph &G, const int &start, const int &target)
{
  const int size = G.size();
  static int dist[NODE][INI];
  static bool visited[NODE][INI];
  priority_queue<Edge> Q;

  for(char c = 'a'; c <= '{'; ++c){
    REP(i, size){
      visited[i][c] = false;
      dist[i][c] = INF;
    }
  }
  for(Q.push(Edge(start, 0, '{')), dist[start]['{'] = 0; !Q.empty();){
    Edge n = Q.top(); Q.pop();
    if(visited[n.dst][n.ini])continue;
    if(n.dst == target)return dist[target][n.ini];
    visited[n.dst][n.ini] = true;
    FOR(e, G[n.dst]){
      if(n.ini == e->ini)continue;
      if(dist[n.dst][n.ini] + e->cost < dist[e->dst][e->ini]){
	dist[e->dst][e->ini] = dist[n.dst][n.ini] + e->cost;
	Q.push(Edge(e->dst, dist[e->dst][e->ini], e->ini));
      }
    }
  }
  return INF;
}

int main(void)
{  
  string s, d, c, start, target;
  while(true){
    int node, name = 0;
    scanf("%d", &node);
    if(node == 0)break;
    //scanf("%s%s", start.c_str(), target.c_str());
    //fgets((char*)start.c_str(), INF, stdin);
    //fgets((char*)target.c_str(), INF, stdin);
    cin >> start >> target;
    map<string, int> M;
    Graph G(NODE);
    M[start] = ++name;
    M[target] = ++name;
    REP(i, node){
      //scanf("%s%s%s", s.c_str(), d.c_str(), c.c_str());
      //fgets((char*)s.c_str(), INF, stdin);
      //fgets((char*)d.c_str(), INF, stdin);
      //fgets((char*)c.c_str(), INF, stdin);
      cin >> s >> d >> c;
      if(M[s] == 0)M[s] = ++name;
      if(M[d] == 0)M[d] = ++name;
      int src = M[s], dst = M[d];
      G[src].push_back(Edge(dst, c.size(), c[0]));
      G[dst].push_back(Edge(src, c.size(), c[0]));
    }
    int result = sssp(G, M[start], M[target]);
    //continue;
    if(result < INF)printf("%d\n", result);
    else printf("impossivel\n");
  }
  return 0;
}
