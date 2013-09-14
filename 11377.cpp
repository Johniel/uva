#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)

using namespace std;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {};
};

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst > b.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

static const int INF = 1 << 20;

int Dijkstra(const Graph &G, const int &start, const int &target, bool *E)
{
  const int size = G.size();
  int dist[size];
  bool visited[size];
  int p[size];
  fill(p, p + size, -1);
  fill(dist, dist + size, INF);
  fill(visited, visited + size, false);
  priority_queue<Edge> Q;
  for(Q.push(Edge(start, 0)), dist[start] = 0; !Q.empty() && dist[target] == INF;){
    Edge next = Q.top(); Q.pop();
    if(visited[next.dst])continue;
    visited[next.dst] = true;
    FOR(e, G[next.dst])if(dist[next.dst] + e->cost < dist[e->dst]){
      dist[e->dst] = dist[next.dst] + e->cost;
      Q.push(Edge(e->dst, dist[e->dst]));
      p[e->dst] = next.dst;
    }
  }
  if(dist[target] == INF)return -1;
  int cnt = 0;//(E[target])? 0 : 1;
  for(int i = target; i != -1; i = p[i]){
    if(!E[i]){
      ++cnt;
      //cout << i+1 << " from " << p[i]+1 << endl;
    }
    //cout << i+1 << " from " << p[i]+1 << endl;
  }
  return (start == target)? 0 : cnt;
}

int main(void)
{
  int tc, city, route, air, cnt = 0;
  cin >> tc;
  while(tc--){
    Graph G;//(MAX_CITY);
    cin >> city >> route >> air;
    bool exist[city];
    fill(exist, exist + city, false);
    G.resize(city);
    REP(i, air){
      int name;
      cin >> name;
      name--;
      exist[name] = true;
    }
    REP(i, route){
      int dst, src;
      cin >> src >> dst;
      --src; --dst;
      if(exist[dst])G[src].push_back(Edge(dst, 0));
      else G[src].push_back(Edge(dst, 1));
      if(exist[src])G[dst].push_back(Edge(src, 0));
      else G[dst].push_back(Edge(src, 1));
    }
    int command;
    cin >> command;
    cout << "Case " << ++cnt << ':' << endl;
    REP(i, command){
      int s, d;
      cin >> s >> d;
      --s; --d;
      cout << Dijkstra(G, s, d, exist) << endl;
    }
    cout << endl;
  }
  return 0;
}
