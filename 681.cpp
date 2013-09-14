#include <iostream>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

typedef complex<double> point;

const double eps=1e-12;

vector< point > chain;

bool right(point &a, point &b, point &c)
{
  if((b.real()-a.real())*(c.imag()-a.imag())-(c.real()-a.real())*(b.imag()-a.imag()) == 0 )
    return false;
  if((b.real()-a.real())*(c.imag()-a.imag())-(c.real()-a.real())*(b.imag()-a.imag()) < eps )
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
  for(int j=0; j<2; j++){
    result[j].push_back(points[0]);
    result[j].push_back(points[1]);
    for(int i=2; i<points.size(); i++){
      result[j].push_back(points[i]);
      while(result[j].size() != 2){
	vector< point > :: iterator itr = result[j].end();
	if( right( *(itr-3), *(itr-2), *(itr-1) ) )break;
	else{
	  result[j].erase( (itr-2) );
	}
      }
    }
    for(int i=0; i<points.size(); i++)
      points[i].imag() *= -1;
  }
  for(int i=0; i<result[0].size(); i++)
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
  int cnt;
  cin >> cnt;cout << cnt << endl;
  while(cnt--){
    int n;
    cin >> n;
    if(n == 0)
      break;
    vector< point >  points;
    chain.clear();
    for(int i=0; i<n; i++){
      complex<double> in;
      cin >> in.real();
      cin >> in.imag();
      if( count(points.begin(), points.end(), in) == 0 ){
	points.push_back(in);
      }
    }
    if(cnt!=0){int z;cin >> z;}
    complex<double> point[points.size()];
    for(int i=0; i<points.size(); i++)
      point[i] = points[i];
    Andrew( points );
    int small = 0;
    for(int i=0; i<chain.size(); i++){
      if( chain[small].imag() > chain[i].imag())
	small = i;
      else if(chain[small].imag() == chain[i].imag()){
	if(chain[small].real() > chain[i].real()){
	  small = i;
	}
      }
    }
    int stop = small;
    cout << chain.size()+1 << endl;
    for(int i=small; i>=0; i--)
      printf("%.0f %.0f\n", chain[i].real(), chain[i].imag());
    for(int i=chain.size()-1; i>small; i--)
      printf("%.0f %.0f\n", chain[i].real(), chain[i].imag());
    printf("%.0f %.0f\n", chain[small].real(), chain[small].imag());
    if(cnt!=0)cout << -1 << endl;
  }
  return 0;
}
