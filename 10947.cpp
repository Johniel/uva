#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <stack>

using namespace std;

typedef complex<double> Point;

const int NODE = 100 + 2 + 1;

bool g[NODE][NODE];
Point p[NODE];    
double r[NODE];

double dist(Point a, Point b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
              (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

void build(int n, int k, int m)
{
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(i == j){
        g[i][j] = false;
        continue;
      }
      double d = dist(p[i], p[j]);
      //cout << p[i] << " -> " << p[j] << " : " << d - r[i] - r[j] << endl;
      g[i][j] = (d <= k * m + r[i] + r[j]);
    }
  }
  return ;
}

bool reachable(int size, int src, int dst)
{
  stack<int> s;
  static bool vis[NODE];
  fill(vis, vis + size, false);
  vis[src] = true;
  for(s.push(src); s.size(); ){
    int v = s.top();
    s.pop();
    if(v == dst)return true;
    for(int i=0; i<size; ++i){
      if(vis[i])continue;
      if(!g[v][i])continue;
      s.push(i);
      vis[i] = true;
    }
  }
  return false;
}

int main(void)
{
  int k, m, n;
  while(cin >> k >> m){
    const int src = 0, dst = 1;
    cin >> p[src].real() >> p[src].imag() >> r[src];
    cin >> p[dst].real() >> p[dst].imag() >> r[dst];
    cin >> n;
    n += 2;
    for(int i=2; i<n; ++i){
      cin >> p[i].real() >> p[i].imag() >> r[i];
    }
    build(n, k, m);
    cout << "Larry and Ryan will ";
    cout << (reachable(n, src, dst) ? "escape!" : "be eaten to death.") << endl;
  }
  return 0;
}
