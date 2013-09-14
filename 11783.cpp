#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <sstream>

using namespace std;

typedef complex<double> Point;

const double EPS = 1e-11;
const double INF = 1e256;
const double PI = M_PI;

bool eq(double a, double b)
{
  return fabs(a - b) < EPS;
}

double dot(Point a, Point b){
  return (a.real() * b.real() + a.imag() * b.imag());
}

double cross(Point a, Point b){
  return (a.real() * b.imag() - a.imag() * b.real());
}

double distance_lp(Point a1, Point a2, Point b)
{
  if(dot(a2-a1, b-a1) < EPS)return abs(b-a1);
  if(dot(a1-a2, b-a2) < EPS)return abs(b-a2);
  return abs(cross(a2-a1, b-a1)) / abs(a2-a1);
}

Point intersection_LL(Point a1, Point a2, Point b1, Point b2)
{
  Point b = b2 - b1;
  double d1 = fabs(cross(b, a1-b1));
  double d2 = fabs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);
  return a1 + (a2-a1) * t;
}

double distance_l(Point a1, Point a2, Point b1, Point b2)
{
  double a = min(distance_lp(a1, a2, b1), distance_lp(a1, a2, b2));
  double b = min(distance_lp(b1, b2, a1), distance_lp(b1, b2, a2));
  return min(a, b);
}

bool intersect_ll(Point a1, Point a2, Point b1, Point b2)
{
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS && cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS;
}

bool online_pl(Point a1, Point a2, Point b)
{
  return eq(cross(a1-a2, b-a2), 0);
}

bool intersect(double x1,double y1,
	       double x2,double y2,
	       double x3,double y3,
	       double x4,double y4)
{
  //check x axis
  if(x1>=x2){
    if((x1<x3 && x1<x4)||(x2>x3 && x2>x4)){
      return false;
    }
  }else{
    if((x2<x3 && x2<x4)||(x1>x3 && x1>x4)){
      return false;
    }
  }
  //check y axis
  if(y1>=y2){
    if((y1<y3 && y1<y4)||(y2>y3 && y2>y4)){
      return false;
    }
  }else{
    if((y2<y3 && y2<y4)||(y1>y3 && y1>y4)){
      return false;
    }
  }

  //check intersect
  if( ((x1-x2)*(y3-y1)+(y1-y2)*(x1-x3))*
      ((x1-x2)*(y4-y1)+(y1-y2)*(x1-x4)) > 0){
    return false;
  }
  if( ((x3-x4)*(y1-y3)+(y3-y4)*(x3-x1))*
      ((x3-x4)*(y2-y3)+(y3-y4)*(x3-x2)) > 0){
    return false;
  }

  return true;
}

double angle(Point a, Point b)
{
  if(eq(a.real() - b.real(), 0.0))return INF;
  return (a.imag() - b.imag()) / (a.real() - b.real());
}

int main(void)
{
  for(int n; ; ){
    cin >> n;
    if(n == 0)break;
    Point p[n][2];
    double cnt[n], sum = 0;
    for(int i=0; i<n; ++i){
      cnt[i] = 0;
      cin >> p[i][0].real() >> p[i][0].imag();
      cin >> p[i][1].real() >> p[i][1].imag();
    }    
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
	if(i == j)continue;
	if(intersect_ll(p[i][0], p[i][1], p[j][0], p[j][1])){
	  cnt[i] += 0.5;
	  cnt[j] += 0.5;
	}
      }
    }
    for(int i=0; i<n; ++i){
      if(eq(cnt[i], 0))sum += 2;
      else sum += cnt[i];
    }
    cout << (int)sum << endl;
  }
  return 0;
}
