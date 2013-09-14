#include <iostream>
#include <cmath>
#include <set>

using namespace std;

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

struct Double{
  double d;
  Double(double _d) : d(_d) {}

};

bool operator < (Double a, Double b)
{
  return lessThan(a.d, b.d);
}


inline
bool f(double n)
{
  set<Double> S;
  for(;;){    
    double m = floor(n);
    if(eq(m, 1) && !eq(n - m, 0))return false;
    n = (n - m) * 3.0;
    if(S.count(Double(n)))return true;
    S.insert(Double(n));
  }
  return true;
}

int main(void)
{
  for(double n; cin >> n; )
    cout << (f(n)? "" : "NON-") << "MEMBER" << endl;
  return 0;
}
