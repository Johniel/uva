#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cmath>
#include <climits>
#include <complex>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define fr first 
#define sc second
#define pb push_back
#define mk make_pair

using namespace std;

typedef long long int lli;
typedef complex<double> Point;

struct Edge{
  int src, dst;
  Edge(int s, int d) : src(s), dst(d) {}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

static const double EPS = 1e-7;

bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

double dist_pp(Point a, Point b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
	      (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

int bfs(const Graph &graph)
{
  const int size = graph.size();
  const int src = 0;
  const int dst = 1;
  bool visited[size];
  fill(visited, visited + size, false);
  queue< pair<int, int> > q;
  visited[src] = true;
  for(q.push(make_pair(src, 0)); !q.empty(); q.pop()){
    pair<int, int> node = q.front();
    if(node.first == dst){
      return node.second - 1;
    }
    FOR(e, graph[node.first]){
      if(visited[e->dst])continue;
      q.push(make_pair(e->dst, node.second + 1));
      visited[e->dst] = true;
    }
  }
  return -1;
}

int main(void)
{
  for(double speed, time; ; ){
    cin >> speed >> time;    
    if(speed == 0 && time == 0)break;
    cin.ignore();
    vector<Point> h;
    while(true){
      string s;
      getline(cin, s);
      if(s.size() == 0)break;
      istringstream iss(s);
      Point p;
      if(!(iss >> p.real() >> p.imag()))break;      
      //p.real() /= 100; p.imag() /= 100;
      h.push_back(p);
    }
    const int size = h.size();
    Graph graph(size);
    REP(i, size){
      REP(j, size){
	if(i == j)continue;
	double dist = dist_pp(h[i], h[j]);
	/*
	cout << i << ' ' << j << ' ' << dist << endl;
	cout << dist / speed << ' ' << time << endl;
	cout << endl;
	*/
	if(dist / (speed * 60) < time){
	  //cout << i << ' ' << j << endl;
	  graph[i].push_back(Edge(i, j));
	}
      }
    }
    int ans = bfs(graph);
    if(ans < 0)cout << "No." << endl;
    else{
      cout << "Yes, visiting " << ans << " other holes." << endl;
    }
  }
  return 0;
}
