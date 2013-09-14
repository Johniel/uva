#include <iostream>
#include <algorithm>

using namespace std;

class R{
public:
  int n, m;
  R(){}
  R(int _n, int _m) : n(_n), m(_m) {}
};
R operator + (const R &a, const R &b)
{
  R c;
  c.m = a.m + b.m;
  c.n = a.n + b.n;
  return c;
}

string rec( R l, R c, R r , const R t )
{  
  /*
  cout << l.m << "/" << l.n << " : " 
       << c.m << "/" << c.n << " : " 
       << r.m << "/" << r.n << endl;
  */
  if( c.m == t.m && c.n == t.n )return "";
  int n = t.m * c.n - c.m * t.n;
  if( 0 < n )return "L" + rec(l, c + l, c, t);
  else return "R" + rec(c, c + r, r , t);
}

int main(void)
{
  int n, m;
  while(cin >> n >> m ){
    if( n == 1 && m == 1 )break;
    cout << rec( R(0, 1), R(1, 1) , R(1, 0), R(n, m) ) << endl;
  }
  return 0;
}
