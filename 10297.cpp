#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

static const double EPS = 1e-5;

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

int main(void)
{
  double D, V;
  while( cin >> D >> V ){
    if(D == 0 && V == 0)break;
    double d = pow(D * D * D - 6.0 * V / M_PI, 1.0 / 3.0);
    printf("%.3lf\n", d);
  }
  return 0;
}
