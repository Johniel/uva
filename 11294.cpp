//uva 247, 11709
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

static const int NODE = 25;
static const int INF = 1 << 20;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(const Graph &G, int n, int order[], int &time, bool visited[])
{
  visited[n] = true;
  FOR(e, G[n]){
    if(!visited[e->dst])
      visit(G, e->dst, order, time, visited);
  }
  order[--time] = n;
  return ;
}

vector< vector<int> > detectSCC(const Graph &G)
{
  const int size = G.size();
  bool visited[size];
  int order[size], scc[size], time, prev = size - 1;
  vector< vector<int> > S;
  Graph H(size);
  fill(order, order + size, -1);
  fill(scc, scc + size, -1);
  REP(i, size){
    FOR(e, G[i])
      H[e->dst].push_back(Edge(e->dst, e->src));
  }
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[i])
      visit(G, i, order, time, visited);
  }
  time = size;
  fill(visited, visited + size, false);
  REP(i, size){
    if(!visited[order[i]]){
      visit(H, order[i], scc, time, visited);
      int j = prev;
      vector<int> T;
      for(j=prev; 0 <= j && scc[j] != -1; --j)
	T.push_back(scc[j]);
      prev = j;
      S.push_back(T);
    }
  }
  return S;
}

bool cmp(vector<int> a, vector<int> b)
{
  return a[0] < b[0];
}

void output(vector< vector<int> > S, map<string, int> &M, int node)
{
  string tmp[node];
  FOR(v, S)
    sort(v->begin(), v->end());
  sort(S.begin(), S.end(), cmp);
  FOR(i, M)
    tmp[i->second] = i->first;
  FOR(i, S){
    bool flg = false;
    FOR(j, *i){
      if(j != i->begin())cout << ", ";
      if(tmp[*j].size() == 0)continue;  
      cout << tmp[*j];
      flg = true;
    }
    if(flg)cout << endl;
  }
  return ;
}

int main(void)
{
  int p, t;
  while(cin >> p >> t && (p | t)){
    int no[p][2][p][2][2], cnt = 0;
    REP(a, p-1)REP(b, 2){
      REP(x, p-1)REP(y, 2){
        no[a][b][x][y][0] = cnt++;
        no[a][b][x][y][1] = cnt++;
      }
    }
    Graph g(cnt);
    for(int i=0; i<t; ++i){
      int a, b;
      int src, dst;
      char p, q;
      cin >> a >> p >> b >> q;
      --a;
      --b;
      src = no[a][p == 'h'][b][q == 'h'][false];
      dst = no[a][p == 'h'][b][q == 'h'][true];
      g[src].push_back(Edge(src, dst));
      src = no[a][p == 'h'][b][q == 'h'][false];
      dst = no[a][p == 'h'][b][q == 'h'][true];
      g[src].push_back(Edge(src, dst));      
    }
    
  }
  return 0;
}
