#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
#include <utility>
#include <climits>
#include <float.h>

#define LOOP(i, b, n) for(int i=b; i<(int)n; ++i)
#define REP(i, n) for(int i=0; i<(int)n; ++i)

//#define double long double

using namespace std;

static const int MAX_NODE = 50 + 1;
//static const double INF = 1e256;
static const double INF = DBL_MAX / 32;

inline bool EQUAL(double a, double b)
{
  return fabs(a - b) < 1e-11;
}

inline bool LESS(double a, double b)
{
  return (!EQUAL(a, b) && a < b);
}


inline double dist(const complex<int> &a, const complex<int> &b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
	      (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

int main(void)
{
  int src, dst, node, road;
  double graph[MAX_NODE][MAX_NODE];
  complex<int> points[MAX_NODE];
  bool exist[MAX_NODE][MAX_NODE];
  while(true){
    cin >> node >> road;
    if(node == 0 && road == 0)break;
    fill(&graph[0][0], &graph[node-1][node], INF);
    fill(&exist[0][0], &exist[node-1][node], false);
    REP(i, node){
      graph[i][i] = 0;
      cin >> points[i].real() >> points[i].imag();
    }
    REP(i, road){
      cin >> src >> dst;
      --src; --dst;
      exist[src][dst] = exist[dst][src] = true;
      graph[src][dst] = graph[dst][src] = 
	dist(points[src], points[dst]);
    }
    REP(k, node)REP(i, node)REP(j, node){
      if(graph[i][j] > graph[i][k] + graph[k][j])
	graph[i][j] = graph[i][k] + graph[k][j];
    }
    double sum, cost = INF, pre = 0, meter = INF, tmp;
    pair<int, int> result = make_pair(-1, -1);
    REP(i, node-1)LOOP(j, i+1, node){
      pre += graph[i][j];
      if(exist[i][j])continue;
      sum = 0;
      double _ij = dist(points[i], points[j]); 
      REP(p, node-1)LOOP(q, p+1, node){
	tmp = min(graph[p][i] + _ij + graph[j][q], 
		  graph[p][j] + _ij + graph[i][q]);
	sum += min(graph[p][q], tmp);
      }
      if(LESS(sum, cost) || (EQUAL(sum, cost) && LESS(_ij, meter))){
	cost = sum;
	meter = _ij;
	result = make_pair(i, j);
      }					      
    }
    //cout << pre << ' ' << cost << endl;
    if(LESS(pre - cost, 1.) || EQUAL(pre - cost, 1.))
      cout << "No road required" << endl;
    else 
      cout << result.first+1 << ' ' << result.second+1 << endl; 
  }
  return 0;
}
