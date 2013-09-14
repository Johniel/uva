#include <iostream>
#include <algorithm>
#include <cstdio>
#include <complex>

using namespace std;

static const double EPS = 1e-11;
static const double INF = 1e256;

typedef complex<double> Point;

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

inline
double distance_PP(Point a, Point b)
{    
  double tmp = ((a.real() - b.real()) * (a.real() - b.real()) + 
		(a.imag() - b.imag()) * (a.imag() - b.imag()));
  return eq(tmp, 0)? INF : sqrt(tmp);
}

inline
bool escape(Point e, Point g, Point d)
{
  double a = distance_PP(e, g);
  double b = distance_PP(e, d);
  if(eq(a, INF) || eq(b, INF))return false;
  a *= 2;
  return lessThan(a, b) || eq(a, b);
}

int main(void)
{
  Point g, d, e, r;
  for(int n; cin >> n; ){
    bool flg = false;
    cin >> g.real() >> g.imag() >> d.real() >> d.imag();
    for(int i=0; i<n; ++i){
      cin >> e.real() >> e.imag();
      if(!flg && escape(e, g, d)){
	flg = true;
	r = e;
      }
    }
    if(flg){
      printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", r.real(), r.imag());
    }
    else puts("The gopher cannot escape.");
  }  
  return 0;
}
