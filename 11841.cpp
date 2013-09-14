#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct Node{
  int x, y, z;
  Node(){}
  Node(int _x, int _y, int _z) 
    : x(_x), y(_y), z(_z) {}
};

bool is_connected(const Node &a, const Node &b)
{
  int p = a.x - b.x;
  int q = a.y - b.y;
  int r = a.z - b.z;
  if(p ==  0 && q == +1 && r == -1)return true;
  if(p ==  0 && q == -1 && r == +1)return true;
  if(p == +1 && q ==  0 && r == -1)return true;
  if(p == -1 && q ==  0 && r == +1)return true; 
  if(p == +1 && q == -1 && r ==  0)return true;
  if(p == -1 && q == +1 && r ==  0)return true;
  return false;
}

const int N = 20;
const int M = (N + 2) * (N + 1) / 2 + 1;

bool visited[M];
bool fin[3];
Node node[M];

void dfs(const Graph &g, int v)
{
  visited[v] = true;
  //cout << node[v].x << ' ' << node[v].y << ' ' << node[v].z << endl;
  if(!fin[0])fin[0] = node[v].x == 0;
  if(!fin[1])fin[1] = node[v].y == 0;
  if(!fin[2])fin[2] = node[v].z == 0;
  FOR(e, g[v]){
    if(visited[e->dst])continue;
    dfs(g, e->dst);
  }
  return ;
}

int main(void)
{
  while(true){
    int n, m;
    cin >> n >> m;
    if(n == 0 && m == 0)break;
    int v = (n + 1) * (n + 2) / 2;
    Graph g(v);
    fill(node, node + M, Node(-1, -1, -1));
    for(int i=0; i<m; ++i){
      int x, y, z;
      cin >> x >> y >> z;
      node[i] = Node(x, y, z);
    } 
    if(n == 0){
      cout << (m ? "Benny" : "Willy") << endl;
      continue;
    }
    for(int i=0; i<v; ++i){
      for(int j=i+1; j<m; ++j){
	if(is_connected(node[i], node[j])){
	  g[i].push_back(Edge(i, j));
	  g[j].push_back(Edge(j, i));
	  continue;
	  cout << "(" << node[i].x << ", " << node[i].y << ", " << node[i].z << ") - ";
	  cout << "(" << node[j].x << ", " << node[j].y << ", " << node[j].z << ")";
	  cout << endl;
	}
      }
    }
    fill(visited, visited + M, false);
    bool flg = false;
    for(int i=0; i<v && !flg; ++i){
      if(visited[i])continue;
      fill(fin, fin + 3, false);
      dfs(g, i);
      flg = fin[0] && fin[1] && fin[2];
    }
    cout << (!flg ? "Willy" : "Benny") << endl;
  }
  return 0;
}
