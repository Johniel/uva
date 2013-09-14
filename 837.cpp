#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <climits>

using namespace std;

static const double EPS = 1e-7;

typedef complex<double> Point;

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

struct EndPoint{
  Point p;
  double l;
  EndPoint(){}
  EndPoint(Point _p, double _l) : p(_p), l(_l) {}
  double& real(){ return p.real(); }
  double& imag(){ return p.imag(); }
};

bool operator < (EndPoint a, EndPoint b)
{
  if(!eq(a.real(), b.real()))return lessThan(a.real(), b.real());
  return lessThan(a.imag(), b.imag());
}

#include <cstdio>
#include <vector>
int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    vector<EndPoint> v;
    cin >> n;

    Point p1, p2;
    for(int i=0; i<n; ++i){
      double p;
      cin >> p1.real() >> p1.imag() >> p2.real() >> p2.imag() >> p;

      double a, b;
      a = p1.real(), b = p2.real();
      if(eq(a, b)){
	p = 1;
	v.push_back(EndPoint(p1, 1));
	continue;
      }
      if(!lessThan(p1.real(), p2.real()))swap(p1, p2);
      v.push_back(EndPoint(p1, p));
      v.push_back(EndPoint(p2, 1/p));      
    }

    sort(v.begin(), v.end());
    
    //for(int i=0; i<v.size(); ++i)cout << v[i].p << " , " << v[i].l << endl;

    if(v.size() == 0){ 
      puts("1");
      puts("-inf +inf 1.000"); 
      if(tc)puts("");
      continue;
    }


    vector<EndPoint> re;
    double result = 1;
    for(int i=0; i+1<v.size(); ++i){      
      result *= v[i].l;
      p1.real() = v[i].real();
      p1.imag() = v[i+1].real();
      re.push_back(EndPoint(p1, result));
    }
    printf("%d\n", re.size() + 2);
    printf("-inf %.3lf 1.000\n", v[0].real());    
    for(int i=0; i<re.size(); ++i){
      printf("%.3lf %.3lf %.3lf\n", re[i].real(), re[i].imag(), re[i].l);      
    }
    printf("%.3lf +inf 1.000\n", v.back().real());
    if(tc)puts("");
  }
  return 0;
}
