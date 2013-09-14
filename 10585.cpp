#include <iostream>
#include <complex>
#include <algorithm>
#include <set>

using namespace std;

typedef complex<double> Point;

namespace std{
  bool operator < (Point a, Point b){
    if(a.real() != b.real())return a.real() < b.real();
    return a.real() < b.real();
  }
};

Point rev(Point p, Point c)
{
  p *= -1;
  c *= 2;
  return p + c;
}

bool f(set<Point> s, Point c)
{
  set<Point>::iterator itr;
  for(itr = s.begin(); itr != s.end(); ++itr){
    if(s.count(rev(*itr, c)) == 0)return false;
  }
  return true;
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int n;
    cin >> n;
    Point c(0, 0);
    set<Point> s;
    for(int i=0; i<n; ++i){
      Point p;
      cin >> p.real() >> p.imag();
      c += p;
      s.insert(p);
    }
    c /= n;
    cout << (f(s, c)? "yes" : "no") << endl;
  }
  return 0;
}
