#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int dst, src, cost, type;
  Edge(int s, int d, int c, int t) : 
    dst(d), src(s), cost(c), type(t) {}
};

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst < b.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

static const int INF = 1 << 30;
static const int EX = 0;
static const int CX = 1;

pair< int, vector<int> > Dijkstra(const Graph &G, const int &start, const int &target)
{
  const int size = G.size();
  int dist[size];
  bool visited[size];
  vector<int> path(size);
  fill(ALL(path), -1);
  fill(dist, dist + size, INF);
  fill(visited, visited + size, false);
  priority_queue<Edge> Q; 
  for(Q.push(Edge(start, start, 0, -1)), dist[start] = 0; !Q.empty() && !visited[target];){
    Edge next = Q.top(); Q.pop();
    if(visited[next.dst])continue;
    visited[next.dst] = true;
    path[next.dst] = next.src;
    FOR(e, G[next.dst])if(e->cost + dist[next.dst] < dist[e->dst]){
      dist[e->dst] = e->cost + dist[next.dst];
      Q.push(Edge(next.dst, e->dst, dist[e->dst], e->type));
    }
  }
  return make_pair(dist[target], path);
}

void makePath(const vector<int> &path, vector<int> &out, int i, const int &end)
{
  if(path[i] != i){
    out.push_back(path[i] + 1);
    makePath(path, out, path[i], end);
  }
  return ;
}

int main(void)
{
  int node, start, target, route, cx, tc = 0;
  while(cin >> node >> start >> target){
    if(tc++)cout << endl;
    Graph G, H;
    G.resize(node); H.resize(node);
    cin >> route;
    REP(i, route){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      src--; dst--;
      G[src].push_back(Edge(src, dst, cost, EX));
      G[dst].push_back(Edge(dst, src, cost, EX));
    }
    cin >> cx;
    REP(i, cx){
      int src, dst, cost;
      cin >> src >> dst >> cost;
      src--; dst--;
      H[src].push_back(Edge(src, dst, cost, CX));
      H[dst].push_back(Edge(dst, src, cost, CX));
    }

    start--; target--;
    
    pair< int, vector<int> > result = Dijkstra(G, start, target);
    int cost = result.first, ticket = -1;
    vector<int> path = result.second, outpath;
    
    REP(i, H.size()){
      REP(j, H[i].size()){
	G[i].push_back(H[i][j]);
	result = Dijkstra(G, start, target);
	G[i].erase(G[i].end() - 1);
	if(result.first < cost){
	  ticket = i;
	  cost = result.first;
	  path = result.second;
	}
      }
    }
    //REP(i, path.size())cout << path[i] << ' ' ;cout << endl;
    outpath.push_back(target + 1);
    makePath(path, outpath, target, target);
    reverse(ALL(outpath));
    REP(i, outpath.size())
      if((int)outpath.size() - i - 1)cout << outpath[i] << ' ';
      else cout << outpath[i] << endl;
    if(ticket != -1)cout << ticket+1 << endl; 
    else cout << "Ticket Not Used" << endl;
    cout << cost << endl;
  }
  return 0;
}
