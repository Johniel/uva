#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <sstream>

using namespace std;

typedef complex<double> Point;

bool cmp(Point a, Point b)
{
  if(a.real() != b.real())return a.real() > b.real();
  return a.imag() < b.imag();
}

double dist_pp(Point a, Point b)
{
  double s = a.real() - b.real();
  double t = a.imag() - b.imag();
  return sqrt(s * s + t * t);
}

#include <cstdio>
int main(void)
{
  int tc;
  Point p[120];
  cin >> tc;
  while( tc-- ){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
      cin >> p[i].real() >> p[i].imag();
    }
    sort(p, p + n, cmp);

    //for(int i=0; i<n; ++i)cout << p[i] << endl;cout << endl;

    double imag = 0;
    double sum = 0;
    for(int i=0; i+1<n; ++i){
      if(imag > p[i+1].imag())continue;
      
      double d = dist_pp(p[i+1], p[i]);
      
      double a = p[i+1].imag() - p[i].imag();
      double b = p[i+1].imag() - imag;
      
      sum += d / a * b;
      //cout << d << ' ' << a << ' ' << b << endl;
      
      imag = p[i+1].imag();
    }
    printf("%.2lf\n", sum);
  }
  return 0;
}
