#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

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

const int N = 20;
int p[N][N], n;
vector<int> P;
void path(int src, int dst)
{
  cout << src << ' ' << dst << endl;
  if(p[src][dst] == -1 || p[src][dst] == dst || p[src][dst] == src)return;    
  path(src, p[src][dst]);
  path(p[src][dst], dst);
}

int main(void)
{  
  double t[N][N];
  while(cin >> n){    
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	p[i][j] = -1;
	if(i == j)t[i][j] = 1e-256;
	else cin >> t[i][j];
      }
    }
    for(int k=0; k<n; ++k){
      for(int i=0; i<n; ++i){
	for(int j=0; j<n; ++j){
	  double tmp = t[i][k] * t[k][j];
	  if(greaterThan(tmp, t[i][j])){
	    t[i][j] = tmp;
	    p[i][j] = k;
	  }
	}
      }
    }
    for(int i=0; i<n; ++i){
      for(int j=0; j<n; ++j){
	cout << t[i][j] << ' ' ;
      }
      cout << endl;
    }
    int src = 0, dst;
    double m = -1;
    for(int i=0; i<n; ++i){
      double tmp = t[src][i] * t[i][src];
      if(lessThan(m, tmp) && greaterThan(tmp, 0)){
	dst = i;
	m = tmp;
      }
    }
    if(eq(m, -1))cout << "no arbitrage sequence exists" << endl;
    else{
      path(src, dst);
      path(dst, src);      
    }
  }
  return 0;
}
