#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

typedef complex<double> point;

static const double EPS = 1e-7;

inline 
bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

inline 
bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

inline 
bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

int main(void)
{
  const int N = 102;
  const double INF = 1e256;
  point p[N];
  int tc, cnt = 0;
  double dist[N][N];
  for(cin >> tc; tc--; ){
    int node; 
    cin >> node;
    fill(&dist[0][0], &dist[node-1][node], INF);
    for(int i=0; i<node; ++i){
      cin >> p[i].real() >> p[i].imag();
    }
    for(int i=0; i<node; ++i){
      for(int j=i+1; j<node; ++j){
	double tmp = sqrt((p[i].real() - p[j].real()) * 
			  (p[i].real() - p[j].real()) + 
			  (p[i].imag() - p[j].imag()) * 
			  (p[i].imag() - p[j].imag()));
	if(lessThan(tmp, 10.0) || eq(tmp, 10.0)){
	  dist[i][j] = dist[j][i] = tmp;
	}
      }
    }
    for(int k=0; k<node; ++k){
      for(int i=0; i<node; ++i){
	for(int j=i+1; j<node; ++j){
	  if(greaterThan(dist[i][j], dist[i][k] + dist[k][j])){
	    dist[i][j] = dist[j][i] = dist[i][k] + dist[k][j];
	  }
	}
      }
    }
    double ans = -1; 
    for(int i=0; i<node; ++i){
      int reachable = 0;
      for(int j=0; j<node; ++j){
	if(!eq(dist[i][j], INF)){
	  ++reachable;
	  if(lessThan(ans, dist[i][j]))
	    ans = dist[i][j];
	}
      }  
      if(reachable != node-1){
	ans = -1;
	break;
      }
    } 
    printf("Case #%d:\n", ++cnt);
    if(!eq(ans, -1) && fabs(ans*1e4 - floor(ans*1e4) - 0.5) > 1e-2)
      printf("%.4lf\n", ans);
    else printf("Send Kurdy\n");
    printf("\n");
  }
  return 0;
}
