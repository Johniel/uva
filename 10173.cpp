//uva 10173
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <utility>
#include <cfloat>
#include <cstdio>
#include <climits>

#define REP(i, n) for(int i=0; i<(int)n; ++i)
#define FOR(i, c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(),(c).end()

using namespace std;

#define double long double

typedef complex<double> Point;
typedef vector<Point> Points;
typedef Point V;
typedef double radian;

struct Line{
  Point p; V v;
  Line(){}
  Line(Point _p, V _v) : p(_p), v(_v) {}
};

typedef vector<Line> Lines;

static const double EPS = 1e-8;
static const double INF = 1e256;
static const double PI = acos(-1.0);

bool eq(const double &a, const double &b)
{
  return fabs(a - b) < EPS;
}

bool ptcmp(const Point &a, const Point &b){
  return (a.real()<b.real() || (a.real()==b.real() && a.imag()<b.imag()));
}

double cross(Point a, Point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

double dot(Point a, Point b)
{
  return (a.real() * b.real() + a.imag() * b.imag());
}

bool isRight(Point &a, Point &b, Point &c)
{
  return ( cross(b - a, c - a) < 0 )? true : false;
}

double distance_P(Point a, Point b)
{
  return abs(a - b);
}

double distance_LP(Point a, Point b, Point c) 
{
  if(dot(b - a, c - a) < EPS)return abs(c - a);
  if(dot(a - b, c - b) < EPS)return abs(c - b);
  return abs(cross(b - a, c - a)) / abs(b - a);
}

Point intersection_L(Point a1, Point a2, Point b1, Point b2) 
{
  Point a = a2 - a1; 
  Point b = b2 - b1;
  return a1 + a * cross(b, b1 - a1) / cross(b, a);
}

V rotating(V a, radian t)
{
  return V(cos(t) * a.real() - sin(t) * a.imag(), sin(t) * a.real() + cos(t) * a.imag());
}

radian calcAngle(const V &a, const V &b)
{
  return acos( dot(a, b) / ( abs(a) * abs(b) ) );
}

double calcArea(const Lines &L)
{  
  const int size = 4, A = 0, B = 1, C = 2, D = 3, AC = 0, AD = 1, BC = 2, BD = 3;
  const double sup = 1e1;
  Points P[size], vertex(size);
  REP(i, size)P[i].resize(2);
  REP(i, size){
    P[i][0] = L[i].p - L[i].v * sup;
    P[i][1] = L[i].p + L[i].v * sup;
  }
  vertex[AC] = intersection_L(P[A][0], P[A][1], P[C][0], P[C][1]);
  vertex[AD] = intersection_L(P[A][0], P[A][1], P[D][0], P[D][1]);
  vertex[BC] = intersection_L(P[B][0], P[B][1], P[C][0], P[C][1]);
  vertex[BD] = intersection_L(P[B][0], P[B][1], P[D][0], P[D][1]);
  return distance_P(vertex[AC], vertex[BC])* distance_P(vertex[BD], vertex[BC]);
}

Points Andrew(Points P)
{
  Points  result[2], chain;
  sort(P.begin(), P.end(), ptcmp);
  REP(j, 2){
    result[j].push_back(P[0]);
    result[j].push_back(P[1]);
    for(int i=2; i<P.size(); i++){
      result[j].push_back(P[i]);
      while(result[j].size() != 2){
	Points :: iterator itr = result[j].end();
	if( isRight( *(itr-3), *(itr-2), *(itr-1) ) )break;
	else result[j].erase( (itr-2) );
      }
    }
    REP(i, P.size())P[i].imag() *= -1;
  }
  REP(i, result[0].size())chain.push_back(result[0][i]);
  for(int i=result[1].size()-2; i>0; i--){
    Point in = result[1][i];
    in.imag() *= -1;
    chain.push_back(in);
  }
  return chain;
}

double MBR(const Points &P)
{
  const int size = P.size(), A = 0, B = 1, C = 2, D = 3;
  int ip[4] = {0, 0, 0, 0}, np[4], next;
  double result = INF;
  Lines L(4);
  V calipers[4] = {V(1, 0), V(-1, 0), V(0, -1), V(0, 1)};
  REP(i, size){
    if( P[ip[A]].imag() < P[i].imag()     )ip[A] = i;
    if( P[i].imag()     < P[ip[B]].imag() )ip[B] = i;
    if( P[ip[C]].real() < P[i].real()     )ip[C] = i;
    if( P[i].real()     < P[ip[D]].real() )ip[D] = i;
  }
  REP(i, 4)np[i] = (ip[i] + 1) % size;
  for(radian rotated = 0, min_angle; rotated < PI/2.0; rotated += min_angle){
    REP(i, 4)L[i] = Line(P[ip[i]], calipers[i]);
    result = min(result, calcArea(L));
    min_angle = INF;
    REP(i, 4){
      double tmp = calcAngle(P[np[i]] - P[ip[i]], calipers[i]);
      if(tmp < min_angle){
	next = i;
	min_angle = tmp;
      }
    }
    REP(i, 4)calipers[i] = rotating(calipers[i], -min_angle);
    np[next] = ( (ip[next] = np[next]) + 1 ) % size;
  }
  return result;
}

int main(void)
{
  int n;
  while(true){
    cin >> n;
    if(n == 0)break;
    Points P(n);
    REP(i, n)cin >> P[i].real() >> P[i].imag();
    if(n < 3){
      cout << "0.0000" << endl;
      continue;
    }
    P = Andrew(P);
    if(P.size() < 3){
      cout << "0.0000" << endl;
      continue;
    }
    REP(i, P.size() - 2){
      if(eq(calcAngle(P[i] - P[i+1], P[i+2] - P[i+1]), PI)){
	P.erase(P.begin() + i + 1);
	--i;
      }
    }
    printf("%.4Lf\n", MBR(P));
  }
  return 0;
}
