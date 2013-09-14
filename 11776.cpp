#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Farmer{
  double t;
  int d;
  Farmer(){}
  Farmer(int _d, double _t) : d(_d), t(_t) {}
};

static const double EPS = 1e-6;

inline bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}
inline bool lessThan(double a, double b)
{
  return !eq(a, b) && a < b;
}

inline bool operator < (Farmer a, Farmer b)
{  
  return lessThan(a.t, b.t);
}

int main(void)
{
  const int F = 1000;
  int tc = 0;
  Farmer f[F * 2];  
  for(int n; ; ){
    cin >> n;
    if(n == -1)break;
    for(int i=0, j=0; i<n; ++i){
      double b, e;
      cin >> b >> e;
      if(lessThan(e, b))swap(e, b);
      f[j++] = Farmer(+1, b - EPS);
      f[j++] = Farmer(-1, e + EPS);
    }
    sort(f, f + n * 2);

    //for(int i=0; i<n*2; ++i)cout << f[i].t << ' ' << f[i].d << endl;

    int result = 0, m = 0;
    for(int i=0; i<n*2; ++i){
      m += f[i].d;
      result = max(result, m);
    }

    cout << "Case " << ++tc << ": " << result << endl; 
  }
  return 0;
}
 
