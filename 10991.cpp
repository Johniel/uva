#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

double heron(double a, double b, double c)
{
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    double r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    double a = r2 + r3;
    double b = r1 + r3;
    double c = r2 + r1;

    double s = heron(a, b, c);
    double A = asin(2.0 * s / (b * c));
    double B = asin(2.0 * s / (a * c));
    double C = asin(2.0 * s / (b * a));

    if(b * b + c * c < a * a){
      A = M_PI - A;
    }
    if(a * a + c * c < b * b){
      B = M_PI - B;
    }
    if(b * b + a * a < c * c){
      C = M_PI - C;
    }

    double x = r1 * r1 * M_PI; 
    double y = r2 * r2 * M_PI;
    double z = r3 * r3 * M_PI;

    x *= (A / (2.0 * M_PI));
    y *= (B / (2.0 * M_PI));
    z *= (C / (2.0 * M_PI));
    
    double r = s - (x + y + z);
    printf("%.6lf\n", r);
  }
  return 0;
}
