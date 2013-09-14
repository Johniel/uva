#include <iostream>
#include <algorithm>

#include <cmath>

using namespace std;

static const double EPS = 1e-7;

bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

int main(void)
{
  for(double n; ; ){
    cin >> n;
    if(eq(n, 0))break;
    double r, l, c;
    
    while(r <= l){
      c = (r + l) / 2;
      
    }
    printf("%.4lf\n", );
  }
  return 0;
}
