#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <sstream>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 501;

struct Edge{
  int dst, cost;
  Edge(int d, int c) : dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

bool operator < (const Edge &a, const Edge &b)
{
  if(a.cost != b.cost)return a.cost > b.cost;
  return a.dst < b.dst;
}

int mssp(const Graph &G, const vector<int> &fire, const set<int> S)
{
  const int size = G.size(), INF = 1 << 20;
  static int weight[NODE];
  static bool visited[NODE];
  int n = 0, m = INF;  
  for(int add=0; add<size; ++add){
    priority_queue<Edge> Q;
    fill(weight, weight + size, INF);
    fill(visited, visited + size, false);
    bool flg = true;
    FOR(i, fire){
      if(*i == add){
	flg = false;
	break;
      }
      weight[*i] = 0;
      Q.push(Edge(*i, 0));
    }
    if(!flg)continue;
    weight[add] = 0;
    Q.push(Edge(add, 0));
    for(; !Q.empty(); ){
      Edge n = Q.top();
      Q.pop();
      if(visited[n.dst])continue;
      visited[n.dst] = true;
      FOR(e, G[n.dst]){
	if(weight[e->dst] > n.cost + e->cost){
	  weight[e->dst] = n.cost + e->cost;
	  Q.push(Edge(e->dst, weight[e->dst]));
	}
      }
    }
    int tmp = -1;
    for(int i=0; i<size; ++i){
      tmp = max(weight[i], tmp);
    }
    //cout << tmp << endl;
    if(tmp < m){
      m = tmp;
      n = add;
    }
  }
  return n;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    set<int> S;
    vector<int> fire;
    int fs, edge, node;
    cin >> fs >> node;
    REP(i, fs){
      int n;
      cin >> n;
      fire.push_back(n - 1);
    }
    Graph G(node);
    cin.ignore();
    while(true){
      string s;
      getline(cin, s);
      if(s.size() == 0)break;      
      istringstream iss(s);
      int src, dst, cost;
      iss >> src >> dst >> cost;
      --src; --dst;
      G[src].push_back(Edge(dst, cost));
      G[dst].push_back(Edge(src, cost));
    }
    cout << mssp(G, fire, S) + 1 << endl;
    if(tc)cout << endl;
  }
  return 0;
}
