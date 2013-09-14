#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>

#define double long double

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef complex<double> Point,point,vec;

const double r3 = sqrt(3.0);
const double EPS = 1e-8;

set<Point> visited;

inline
bool equal(double a, double b)
{
  return abs(a - b) < EPS;
}

inline
bool lessThan(double a, double b)
{
  return !equal(a, b) && a < b;
}

inline
bool greaterThan(double a, double b)
{
  return !equal(a, b) && a > b;
}

inline
double dist_pp(Point a, Point b)
{
  return abs(b-a);
}

namespace std{
  inline
  bool operator < (Point a, Point b)
  {
    if( abs( a.real() - b.real() ) < EPS )
      return lessThan(a.imag(), b.imag());
    return lessThan(a.real(), b.real());
  }
};

inline
vec uvec(vec v){
  return v / abs(v);
}

inline
void rec(Point a, Point b, double lim)
{
  Point c, d, e, f;
  
  c = (a + b); c /= 2.;
  d = (c + a); d /= 2.;
  e = (c + b); e /= 2.;
  
  double k = r3 * abs(d-c);
  
  f =  c + k * uvec(c - a) * Point(0, 1);
  
  if(!greaterThan(dist_pp( d, f ), lim))return ;
  
  visited.insert(d);
  visited.insert(f);
  visited.insert(e);
  rec(d, f, lim);
  rec(f, e, lim);
  return ;
}

int main(void)
{
  Point a, b, buff[10000], p;
  double lim;
  int tc = 0; 
  while(true){
    scanf("%Lf %Lf %Lf %Lf %Lf", 
	  &(a.real()), 
	  &(a.imag()), 
	  &(b.real()), 
	  &(b.imag()), 
	  &(lim));
    if(lessThan(lim, 1))break;
    printf("Case %d:\n", ++tc);
    if(lessThan(0, abs(a - b) - lim)){
      rec(a, b, lim);
      visited.insert(a);
      visited.insert(b);
    }
    int size = 0;
    FOR(i, visited){
      if(i == visited.begin()){
	p = *i;
      }
      else{
	if(lessThan( abs(a - b) , EPS )){
	  buff[size++] = *i;
	}
	p = *i;
      }
    }
    
    REP(i, size)visited.erase(buff[i]);
    
    printf("%d\n", visited.size());

    FOR(i, visited){
      printf("%.5Lf %.5Lf\n", i->real(), i->imag());
    }
    visited.clear();
  }
  return 0;
}

