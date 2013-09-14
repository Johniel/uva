#include <iostream>
#include <cmath>
#include <cstdio>

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
  for(double a, b, c; cin >> a >> b >> c;){
    if(eq(a, 0) || eq(b, 0) || eq(c, 0)){
      printf("The radius of the round table is: 0.000\n");
    }
    else{
      double s = (a + b + c) / 2.0;
      double r = sqrt((s - a) * (s - b) * (s - c) / s);
      printf("The radius of the round table is: %.3lf\n", r);
    }
  }
  return 0;
}
