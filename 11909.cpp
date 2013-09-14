#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

inline
double deg2rad(double th)
{
  return M_PI * th / 180.0;
}

inline
double dsin(double th){ return sin( deg2rad(th) ); }

inline
double dcos(double th){ return cos( deg2rad(th) ); }

inline
double calcS(double a, double b, double th)
{
  return a * b * dsin(th) / 2.0;
}

inline
double solve(double a, double th)
{
  double h = dsin(th) * a;
  double n = 180.0 - (90.0 + th);
  double m = 90.0 - n;
  double b = h / dcos(m);
  return calcS(a, h, n) + calcS(h, b, m);
}

int main(void)
{
  double l, w, h, th;
  while(cin >> l >> w >> h >> th){
    double n = 180.0 - (th + 90.0);
    double m = 90.0 - n;
    double a = dsin(th) * l;
    double b = a / dcos(m);
    double r;
    if(b <= h)r = l * h - solve(l, th);
    else r = solve(h, 90.0 - th);
    printf("%.3lf mL\n", r * w);
  }
  return 0;
}
