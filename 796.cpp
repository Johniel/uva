#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

static const int FAIL = -1;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void traverse(const Graph &G, int n, int d[], int p[], int l[], int &time)
{  
  d[n] = l[n] = ++time;
  FOR(e, G[n]){
    if(!d[e->dst]){
      p[e->dst] = e->src;
      traverse(G, e->dst, d, p, l, time); 
      l[e->src] = min(l[e->src], l[e->dst]); 
    }
    else if(p[e->src] != e->dst)
      l[e->src] = min(l[e->src], d[e->dst]); 
  }
  return ;
}

Edges findBridge(const Graph &G)
{// G is not allowed parallel edge
  const int size = G.size();
  int d[size], p[size], l[size], time = 0;
  Edges B;
  fill(d, d + size, false);
  fill(p, p + size, FAIL);
  REP(i, size){
    if(d[i])continue;
    traverse(G, i, d, p, l, time);
  }
  REP(i, size){
    if(p[i] != FAIL && d[i] == l[i])
      B.push_back(Edge(p[i], i));
  }
  return B;
}

bool cmp(const Edge &a, const Edge &b)
{
  if(a.src != b.src)return a.src < b.src;
  return a.src > b.dst;
}

#include <set>
#include <utility>
int main(void)
{
  int node;
  while(cin >> node){
    int src, edge, dst, cnt = 0;
    char c;
    set< pair<int, int> > S, T;
    Graph G(node);
    REP(i, node){
      cin >> src >> c >> edge >> c;
      REP(j, edge){
	cin >> dst;
	if(S.count(make_pair(src, dst))){
	  T.insert(make_pair(src, dst));
	}
	else{
	  G[src].push_back(Edge(src, dst));		  
	  G[dst].push_back(Edge(dst, src));
	}
      }
    }
    Edges B = findBridge(G), R;
    FOR(e, B){
      //if(T.count(make_pair(e->src, e->dst)))continue;
      R.push_back(Edge(min(e->src, e->dst), max(e->src, e->dst)));
    }
    sort(ALL(R), cmp);
    cout << R.size() << " critical links" << endl;
    FOR(e, R)
      cout << e->src << " - " << e->dst << endl;
    cout << endl;
  }
  return 0;
}
