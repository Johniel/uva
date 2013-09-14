#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>

#define REP(i, n) for(int i=0; i<(int)n; ++i)

using namespace std;

typedef complex<double> point;

static const double EPS = 0;

vector< point > chain;

bool right(point &a, point &b, point &c)
{
  if((b.real()-a.real())*(c.imag()-a.imag()) -
     (c.real()-a.real())*(b.imag()-a.imag()) < 0)
    return true;
  return false;
}

bool ptcmp(const point &a, const point &b){
  return (a.real()<b.real() || (a.real()==b.real() && a.imag()<b.imag()));
}

void Andrew(vector< point > &points)
{
  vector< point > result[2];
  sort(points.begin(), points.end(), ptcmp);
  REP(j, 2){
    result[j].push_back(points[0]);
    result[j].push_back(points[1]);
    for(int i=2; i<points.size(); i++){
      result[j].push_back(points[i]);
      while(result[j].size() != 2){
	vector< point > :: iterator itr = result[j].end();
	if( right( *(itr-3), *(itr-2), *(itr-1) ) )break;
	else  result[j].erase( (itr-2) );
      }
    }
    REP(i, points.size())
      points[i].imag() *= -1;
  }
  REP(i, result[0].size())
    chain.push_back(result[0][i]);
  for(int i=result[1].size()-2; i>0; i--){
    point in = result[1][i];
    in.imag() *= -1;
    chain.push_back(in);
  }
  return ;
}

int main(void)
{
  int n;
  while(cin >> n && n){
    vector< point >  points;
    chain.clear();
    points.resize(n);
    for(int i=0; i<n; i++){
      cin >> points[i].real() >> points[i].imag();
    }
    Andrew( points );
    //cout << n - chain.size() << endl;
    cout << (n != chain.size() ? "Yes" : "No") << endl;
  }
  return 0;
}
