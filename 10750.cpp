//uva 10245
#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
#include <climits>
#include <utility>
#include <cstdio>

#define REP(i, n) for(int i=0; i<n; i++)

using namespace std;

static const int MAX = 10001;
static const double EPS = 1e-7;

typedef complex<double> Point;
typedef pair<Point, Point> Points;

bool cmpX(const Point &a, const Point &b)
{
  if(a.real() != b.real())return a.real() < b.real();
  return a.imag() < b.imag();
}

bool cmpY(const Point &a, const Point &b)
{
  if(a.imag() != b.imag())return a.imag() < b.imag();
  return a.real() < b.real();
}

double distance_P(const Point &a, const Point &b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

Points divide(Point *X, Point *Y, const int &size)
{
  if(size < 4){
    double choice = 1e256, dist;
    Points result;
    REP(i, size-1)for(int j=i+1; j<size; j++){
      dist = distance_P(X[i], X[j]);
      if(dist < choice){
	result = make_pair(X[i], X[j]);
	choice = dist;
      }
    }
    return result;
  }
  int center = size/2, r = 0, l = 0, cnt = 0;
  double lim = (X[center].real() + X[size - center].real()) / 2.0;
  double dist, tmp;
  Point Xl[center], Xr[size - center], Yl[center], Yr[size - center];
  Point W[size];
  REP(i, center)Xl[i] = X[i];
  REP(i, size - center)Xr[i] = X[center + i];
  REP(i, size){
    if((Y[i].real() <= lim && l < center) || r == size - center)Yl[l++] = Y[i];
    else Yr[r++] = Y[i];
  }
  Points a = divide(Xl, Yl, l);
  Points b = divide(Xr, Yr, r);
  Points result = (distance_P(a.first, a.second) < distance_P(b.first, b.second))? a : b;
  dist = distance_P(result.first, result.second);
  REP(i, size)if(fabs(Y[i].real() - lim) < dist)
    W[cnt++] = Y[i];
  REP(i, cnt-1){
    int j = i + 1;
    while(j < cnt && fabs(W[i].imag() - W[j].imag()) < dist){
      tmp = distance_P(W[i], W[j]);
      if(tmp < dist){
	result = make_pair(W[i], W[j]);
	dist = tmp;
      }
      j++;
    }
  }
  return result;
}

Points closestPointPair(Point *p, const int &size)
{
  Point X[size], Y[size];
  REP(i, size)X[i] = Y[i] = p[i];
  sort(X, X + size, cmpX);
  sort(Y, Y + size, cmpY);
  return divide(X, Y, size);
}

int main(void)
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    Point p[n];
    REP(i, n)cin >> p[i].real() >> p[i].imag();

    Points r = closestPointPair(p, n);
    
    Point q = (r.first + r.second) / 2.0;

    printf("%.3lf %.3lf\n", q.real(), q.imag());
    
  }
  return 0;
}
