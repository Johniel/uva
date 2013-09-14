#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

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

inline 
bool greaterThan(double a, double b)
{
  return !eq(a, b) && a > b;
}

struct Double{
  double d;  
  Double(){}
  Double(double _d){
    d = _d;
  }
};

bool operator < (const Double &a, const Double &b)
{
  return lessThan(a.d, b.d);
}

int main(void)
{
  while(true){
    double x1, y1, x2, y2, x3, y3, x4, y4;
    map< pair<Double, Double>, int> M;
    if(!(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4))break;
    ++M[make_pair(Double(x1), Double(y1))];
    ++M[make_pair(Double(x2), Double(y2))];
    ++M[make_pair(Double(x3), Double(y3))];
    ++M[make_pair(Double(x4), Double(y4))];
    double x = 0, y = 0;
    FOR(i, M){
      if(i->second == 1){
	x += i->first.first.d;
	y += i->first.second.d;
      }
      else{
	x -= i->first.first.d;
	y -= i->first.second.d;		
      }
    }
    printf("%.3lf %.3lf\n", x, y);
  }
  return 0;
}
