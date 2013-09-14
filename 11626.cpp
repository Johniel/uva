#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

typedef complex<long long  int> point;

static const double EPS = 1e-11;
static const double INF = 1e256;

static const int M = 100000 + 1;

point p[M], upper[M], lower[M];

bool right(point &a, point &b, point &c)
{
  return ((b.real()-a.real())*(c.imag()-a.imag()) -
	  (c.real()-a.real())*(b.imag()-a.imag()) <= 0);  
}

bool cmpReal(const point &a, const point &b)
{
  if(a.real() != b.real())return a.real() < b.real();
  return a.imag() < b.imag();
}

int main(void)
{
  int tc;
  for(cin >> tc; tc--; ){
    int n, size = 0;
    point r, l;
    r.real() =  1000000005;
    l.real() = -1000000005;
    char c;
    cin >> n;
    REP(i, n){
      cin >> p[size].real() >> p[size].imag() >> c;
      if(c == 'Y'){
	if(r.real() > p[size].real())
	  r = p[size];
	if(r.real() == p[size].real())
	  if(r.imag() > p[size].imag())
	    r = p[size];
	if(l.real() < p[size].real())	  
	  l = p[size];
	if(l.real() == p[size].real())
	  if(l.imag() < p[size].imag())
	    l = p[size];
	++size;
      }
    }
    int ui = 0, li = 0;
    REP(i, size){      
      if(p[i] == r || p[i] == l)continue;      
      if(right(r, l, p[i]))upper[ui++] = p[i];
      else lower[li++] = p[i];
    }
    sort(upper, upper + ui, cmpReal);
    sort(lower, lower + li, cmpReal); 
    reverse(lower, lower + li);
    cout << size << endl;    
    if(size){
      cout << r.real() << ' ' << r.imag() << endl;
    }
    REP(i, ui){
      cout << upper[i].real() << ' ' << upper[i].imag() << endl;
    }
    if(size && r != l){
      cout << l.real() << ' ' << l.imag() << endl;
    }
    REP(i, li){
      cout << lower[i].real() << ' ' << lower[i].imag() << endl;
    }
  }
  return 0;
}
