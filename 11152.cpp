#include <iostream>
#include <math.h>

using namespace std;

double heron(double a, double b, double c)
{
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Circumscribed Circle Area
double cca(double a, double b, double c)
{
  double r = (a * b * c);
  r /= sqrt((a + b + c) * (- a + b + c) * (a - b + c) * (a + b - c));  
  return r * r * M_PI;
}

// Inscribed Circle Area
double ica(double a, double b, double c)
{
  double r = heron(a, b, c) / ((a + b + c) / 2);
  return r * r * M_PI;
}

int main(void)
{
  for(double a, b, c; cin >> a >> b >>c;){
    double s = heron(a, b, c);
    double ca = cca(a, b, c);
    double ia = ica(a, b, c);
    printf("%.4lf %.4lf %.4lf\n", ca - s, s - ia, ia);
  }
  return 0;
}
