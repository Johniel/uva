#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

const int NODE = 1000 + 1000;

class DisjointSet{
public: 
  int rank[NODE], p[NODE];
  DisjointSet(int size){
    fill(p, p + size, 0);
    fill(rank, rank + size, 0);
  }
  void make(int a){
    rank[a] = 0;
    p[a] = a;
  }
  void join(int a, int b){
    link(find(a), find(b));
  }
  int find(int a){
    return (a == p[a])? a : p[a] = find(p[a]);
  }
  bool isSameSet(int a, int b){
    return find(a) == find(b);
  }
  void link (int a, int b){
    if(rank[a] > rank[b])
      p[b] = a;
    else{
      p[a] = b;
      if(rank[a] == rank[b])
	rank[b]++;
    }
  }
  int sup(int a){
    return p[a] == a ? a : sup(p[a]);
  } 
};

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int color[NODE];
bool ant[NODE][NODE];

bool rec(const Graph &g, int node, int c, int depth)
{
  //cout << node << ' ' << c << endl;
  color[node] = c;
  FOR(e, g[node]){
    //cout << "DST : " << e->dst << "(" << color[e->dst] << ")" << endl;
    if(color[e->dst] == c)return false;
    if(color[e->dst] == (c ^ 1))continue;
    color[e->dst] = c ^ 1;
    if(!rec(g, e->dst, c ^ 1, depth + 1)){
      return false;
    }
  }
  return true;
}

int main(void)
{
  int tc, cnt = 0;
  cin >> tc;  
  while(tc--){
    map<string, int> conv;
    int name = 0;
    int n, m;
    cin >> n >> m;
    DisjointSet ds(NODE);
    REP(i, n){
      string s, t;
      cin >> s >> t;
      if(conv.find(s) == conv.end()){
	conv[s] = name;
	ds.make(name);
	++name;
      }
      if(conv.find(t) == conv.end()){
	conv[t] = name;
	ds.make(name);
	++name;
      }
      ds.join(conv[s], conv[t]);
    }
    int v = 0;
    static int v_name[NODE];
    for(int i=0; i<name; ++i){
      if(ds.p[i] == i){
	v_name[i] = v++;
      }
    }
    Graph g(v);
    bool flg = true;
    REP(i, m){
      string s, t;
      cin >> s >> t;
      if(conv.find(s) == conv.end()){
	conv[s] = name;
	ds.make(name);
	v_name[name] = v++;
	++name;
	g.resize(v);
      }
      if(conv.find(t) == conv.end()){
	conv[t] = name;
	ds.make(name);
	v_name[name] = v++;
	++name;
	g.resize(v);
      }      
      int a = conv[s], b = conv[t];
      if(ds.isSameSet(a, b)){
	flg = false;
      }
      int u = v_name[ds.sup(a)];
      int v = v_name[ds.sup(b)];
      g[u].push_back(Edge(u, v));
      g[v].push_back(Edge(v, u));
      continue;
      cout << u << ' ' << v << endl;      
    }
    cout << "Case " << ++cnt << ": " ;
    if(!flg)cout << "NO" << endl;
    else{
      fill(color, color + g.size(), 2);
      REP(i, g.size()){
	if(color[i] != 2)continue;
	flg = flg && rec(g, i, 0, 0);
      }
      cout << (flg ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
