#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

static const double EPS = 1e-12;

typedef complex<double> Point;

double distance_P(Point a, Point b)
{
  return sqrt((a.real() - b.real()) * (a.real() - b.real()) + 
	      (a.imag() - b.imag()) * (a.imag() - b.imag()));
}

int main(void)
{
  Point A, B, C;
  bool flg = true;
  while(cin 
	>> A.real() >> A.imag() 
	>> B.real() >> B.imag()
	>> C.real() >> C.imag()){
    double dist[3], a, b, c;
    int n;
    cin >> n;
    if(flg)flg = false;
    else cout << endl;
    dist[0] = distance_P(A, B);
    dist[1] = distance_P(B, C);
    dist[2] = distance_P(C, A);
    sort(dist, dist + 3);
    Point points[n];
    REP(i, n)cin >> points[i].real() >> points[i].imag();
    REP(i, n-2){
      for(int j=i+1; j<n-1; ++j){
	if(count(dist, dist + 3, distance_P(points[j], points[i])));
	else continue;
	for(int k=j+1; k<n; ++k){
	  double check[3];
	  check[0] = distance_P(points[i], points[j]);
	  check[1] = distance_P(points[j], points[k]);
	  check[2] = distance_P(points[k], points[i]);
	  sort(check, check + 3);
	  if(fabs(dist[0] == check[0]) < EPS && 
	     fabs(dist[1] == check[1]) < EPS && 
	     fabs(dist[2] == check[2]) < EPS){
	    cout << points[i].real() << ' ' << points[i].imag() << endl 
		 << points[j].real() << ' ' << points[j].imag() << endl 
		 << points[k].real() << ' ' << points[k].imag() << endl;
	    i = j = k = 1 << 20;
	  }
	}
      }
    }
  }
  return 0;
}
