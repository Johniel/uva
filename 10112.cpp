//uva10112
#include <iostream>
#include <cmath>
#include <algorithm>
#include <complex>

using namespace std;

typedef complex<int> Point;

int cross(Point a, Point b)
{
  return (a.real() * b.imag() - a.imag() * b.real());
}

bool right(Point a, Point b, Point c)
{
  //return cross(b - a, c - a) < 0;
  int tmp = ((b.real() - a.real()) * (c.imag() - a.imag()) - 
             (c.real() - a.real()) * (b.imag() - a.imag()));
  return tmp < 0;
  /*
  double tmp = (((double)b.real() - (double)a.real()) * ((double)c.imag() - (double)a.imag()) - 
                ((double)c.real() - (double)a.real()) * ((double)b.imag() - (double)a.imag()));
  return tmp < 0;
  */
}

int area_tri(Point a, Point b, Point c)
{
  int tmp = ((c.imag() - a.imag()) * (b.real() - a.real()) - 
             (b.imag() - a.imag()) * (c.real() - a.real()));
  return abs(tmp);
}

bool is_inside(Point a, Point b, Point c, Point x)
{
  int sum = 0;
  sum += area_tri(a, b, x);
  sum += area_tri(b, c, x);
  sum += area_tri(c, a, x);
  return area_tri(a, b, c) == sum;
}

int main(void)
{
  int n;
  while(cin >> n && n){
    char c[n];
    Point p[n];
    for(int i=0; i<n; ++i){
      cin >> c[i] >> p[i].real() >> p[i].imag();
    }
    int mx = -1;
    string name;
    for(int i=0; i<n; ++i){
      for(int j=i+1; j<n; ++j){
        for(int k=j+1; k<n; ++k){
          bool flg = true;
          for(int l=0; l<n && flg; ++l){
            if(i == l)continue;
            if(j == l)continue;
            if(k == l)continue;
            flg = !is_inside(p[i], p[j], p[k], p[l]);
            continue;
            bool s = right(p[i], p[j], p[l]);
            bool t = right(p[j], p[k], p[l]);
            bool u = right(p[k], p[i], p[l]);
            if(s == t && t == u)flg = false;
          }
          if(flg){
            int tmp = area_tri(p[i], p[j], p[k]);
            string s = "";
            s += c[i];
            s += c[j];
            s += c[k];
            sort(s.begin(), s.end());
            if(mx < tmp){
              name = s;
              mx = tmp;
            }
            else if(mx == tmp)name = min(name, s);
          }
        }
      }
    }
    cout << name << endl;
  }
  return 0;
}
