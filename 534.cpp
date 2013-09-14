//uva 11710
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <complex>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

typedef complex<double> point;

static const double INF = 1e256;
static const int FAIL = -1;

static const double EPS = 1e-7;

inline bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

inline bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

inline bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

struct Edge{
  int src, dst;
  double cost;
  Edge() : src(FAIL), dst(FAIL), cost(INF) {}
  Edge(int s, int d, double c) 
  : src(s), dst(d), cost(c) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

struct State{
  double cost;
  int dst;
  State(double c, int d) 
    : cost(c), dst(d) {}    
};

bool operator < (const State &a, const State &b)
{
  if(!eq(a.cost, b.cost))return greaterThan(a.cost, b.cost);
  return a.dst < b.dst;
}

double sssp(const Graph &G, int src, int dst)
{
  const int size = G.size();
  priority_queue<State> Q;
  bool visited[size];
  double weight[size];
  Edge path[size];
  fill(visited, visited + size, false);
  fill(weight, weight + size, INF);
  for(Q.push(State(0, src)); !Q.empty() && !visited[dst]; ){
    State s = Q.top();
    Q.pop();
    if(visited[s.dst])continue;
    cout << "pop : " << s.dst << ' ' << s.cost << endl;
    visited[s.dst] = true;
    FOR(e, G[s.dst]){
      if(!visited[e->dst] && greaterThan(weight[e->dst], s.cost + e->cost)){	
	path[e->dst] = *e;
	weight[e->dst] = s.cost + e->cost;
	Q.push(State(weight[e->dst], e->dst));
	cout << "insert : " << e->src << ' ' << e->dst << ' ' << weight[e->dst] << endl;
      }
    }
  }
  cout << "===========  " << weight[dst] << endl;
  double re = INF;
  for(int i=dst; ; i = path[i].src){    
    cout << path[i].src << ' ' << path[i].dst << ' ' << path[i].cost << endl;
    if(greaterThan(re, path[i].cost))
      re = path[i].cost;
    if(path[i].src == src)break;
  }
  return re;
}

inline double distansePP(point a, point b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
	      (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

int main(void)
{
  int tc = 0;
  while(true){
    int node;
    cin >> node;
    if(node == 0)break;
    Graph G(node);
    point p[node];
    REP(i, node)
      cin >> p[i].real() >> p[i].imag();
    REP(s, node){
      REP(d, node){
	if(s == d)continue;
	double cost = distansePP(p[s], p[d]);
	cout << "Edge : " << s << ' ' << d << ' ' << cost << endl;
	G[s].push_back(Edge(s, d, cost));
      }
    }
    cout << "Scenario #" << ++tc << endl;
    printf("Frog Distance = %.3lf\n\n", sssp(G, 0, 1));  
  }  
  return 0;
}
