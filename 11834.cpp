#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

typedef complex<double> Point;

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

inline
double dist(Point a, Point b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
	      (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

#include <cstdio>
int main(void)
{
  double h, w, a, b; 
  while(cin >> h >> w >> a >> b && h){
    Point p(a, a), q(h - b, w - b);
    if((2 * a <= h && 2 * a <= w && 2 * b <= w && 2 * b <= h) && 
       (lessThan(a + b, dist(p, q)) || eq(a + b, dist(p, q)))){
      cout << 'S' << endl;
    }
    else cout << 'N' << endl;
  }
  return 0;
}
