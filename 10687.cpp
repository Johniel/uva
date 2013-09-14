#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

#include <stack>
bool dfs(Graph graph)
{
  const int size = graph.size();
  bool visited[size];
  stack<int> s;  
  fill(visited, visited + size, false);
  visited[0] = true;
  for(s.push(0); !s.empty(); ){
    int node = s.top();
    s.pop();
    FOR(e, graph[node]){
      if(visited[e->dst])continue;
      visited[e->dst] = true;
      s.push(e->dst);
    }
  }
  return count(visited, visited + size, true) == size;
}

#include <complex>
typedef complex<int> Point;

inline
bool operator < (Point a, Point b)
{
  if(a.real() != b.real())return a.real() < b.real();
  return a.imag() < b.imag();
}

inline
int dist(Point a, Point b)
{
  return ((a.real() - b.real()) * (a.real() - b.real()) + 
	  (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

struct Sta{
  Point p;
  int id;
  Sta(){}
  Sta(Point _p, int _id) : p(_p), id(_id) {}
};

Point base;
inline
bool operator < (const Sta a, const Sta b)
{
  Point pa = a.p, pb = b.p;
  int da = dist(base, pa);
  int db = dist(base, pb);
  if(da != db)return da < db;
  pa -= base;
  pb -= base;
  return pa < pb;
}

int main(void)
{
  Sta s[1000 + 1];
  for(int node; ; ){
    cin >> node;
    if(node == 0)break;
    Graph graph(node);
    Point p;
    for(int i=0; i<node; ++i){
      cin >> p.real() >> p.imag();
      s[i] = Sta(p, i);
    }
    if(node <= 3){
      cout << "All stations are reachable." << endl;
      continue;
    }
    p.real() = p.imag() = 1000;
    for(int i=0; i<node; ++i){
      base = s[i].p;
      Sta a(p, -1), b(p, -1);      
      for(int j=0; j<node; ++j){
	if(i == j)continue;
	if(s[j] < a){
	  b = a;
	  a = s[j];
	}
	else if(s[j] < b){
	  b = s[j];
	}
      }      
      graph[i].push_back(Edge(i, a.id));
      graph[i].push_back(Edge(i, b.id));
    }
    cout << (dfs(graph)? 
	     "All stations are reachable." : 
	     "There are stations that are unreachable.") << endl;
  }
  return 0;
}
